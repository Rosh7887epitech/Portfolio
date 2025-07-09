/*
** EPITECH PROJECT, 2025
** Zappynian
** File description:
** Action command implementations
*/

#include "../include/commands.h"
#include "../include/server.h"
#include "../include/world.h"
#include "../include/team.h"
#include "../include/egg.h"
#include "../include/elevation.h"

void cmd_eject(player_t *player, server_t *server)
{
    tile_t *current_tile;
    size_t players_to_eject_count = 0;
    client_t *ejecting_client;

    ejecting_client = find_client_by_player(server, player);
    if (!ejecting_client)
        return;
    if (player->dead || player->in_elevation)
        return (void)zn_send_message(ejecting_client->zn_sock, "ko");
    current_tile = get_tile(server->map, player->x, player->y);
    if (!current_tile)
        return (void)zn_send_message(ejecting_client->zn_sock, "ko");
    players_to_eject_count = get_nb_player(current_tile, player);
    if (players_to_eject_count == 0) {
        destroy_eggs_at_position(player->x, player->y, server);
        send_pex(server, player);
        return (void)zn_send_message(ejecting_client->zn_sock, "ok");
    }
    if (make_player_array(current_tile, player, server, ejecting_client) == -1)
        return (void)zn_send_message(ejecting_client->zn_sock, "ko");
}

void cmd_take(player_t *player, server_t *server)
{
    int resource_type;
    tile_t *current_tile;
    client_t *client;

    client = find_client_by_player(server, player);
    if (!client)
        return;
    if (player->dead || player->in_elevation)
        return (void)zn_send_message(client->zn_sock, "ko");
    resource_type = get_resource_type_from_name(get_command_argument(player));
    if (resource_type == -1)
        return (void)zn_send_message(client->zn_sock, "ko");
    current_tile = get_tile(server->map, player->x, player->y);
    if (take_resource_from_tile(current_tile, resource_type)) {
        add_resources(player, resource_type, server, client);
    } else
        zn_send_message(client->zn_sock, "ko");
}

void cmd_set(player_t *player, server_t *server)
{
    int resource_type;
    client_t *client;

    client = find_client_by_player(server, player);
    if (!client)
        return;
    if (player->dead || player->in_elevation)
        return (void)zn_send_message(client->zn_sock, "ko");
    resource_type = get_resource_type_from_name(get_command_argument(player));
    if (resource_type == -1) {
        zn_send_message(client->zn_sock, "ko");
        return;
    }
    if (resource_type == 0)
        manage_food(server, player, client, resource_type);
    else
        manage_stones(server, player, client, resource_type);
}

void cmd_incantation(player_t *player, server_t *server)
{
    tile_t *current_tile;
    client_t *player_client;
    elevation_requirement_t req[MAX_LEVEL];

    if (!player || !server)
        return;
    player_client = find_client_by_player(server, player);
    if (!player_client)
        return;
    if (player->dead || player->in_elevation)
        return (void)zn_send_message(player_client->zn_sock, "ko");
    current_tile = get_tile(server->map, player->x, player->y);
    if (!current_tile)
        return (void)zn_send_message(player_client->zn_sock, "ko");
    elevation_init_requirements(req);
    if (!can_start_incantation(current_tile, player, req))
        return (void)zn_send_message(player_client->zn_sock, "ko");
    start_incantation(current_tile);
    zn_send_message(player_client->zn_sock, "Elevation underway");
    check_and_send_elevation_status(server, player, current_tile, req);
}
