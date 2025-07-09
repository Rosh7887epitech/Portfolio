/*
** EPITECH PROJECT, 2025
** Zappynian
** File description:
** death
*/

#include "../include/death.h"

void death_handle(player_t *player, map_t *map, server_t *server)
{
    tile_t *tile = NULL;
    team_t *team = NULL;

    if (!player)
        return;
    tile = get_tile(map, player->x, player->y);
    if (tile)
        remove_player_from_tile(tile, player);
    if (player->team_name) {
        team = get_team_by_name(server->args, player->team_name);
        if (team && team->current_players > 0)
            team->current_players--;
        team_free_slot(server->args, player->team_name);
    }
    free(player->team_name);
    free(player);
}

void death_check(player_t **players, int player_count, map_t *map,
    server_t *server)
{
    for (int i = 0; i < player_count; i++) {
        if (players[i] && players[i]->food <= 0) {
            printf("Player %d died of hunger!\n", players[i]->id);
            players[i]->dead = true;
            send_pdi(server, players[i]);
            death_handle(players[i], map, server);
            players[i] = NULL;
            zn_send_message(server->connection->zn_server, "dead");
        }
    }
}
