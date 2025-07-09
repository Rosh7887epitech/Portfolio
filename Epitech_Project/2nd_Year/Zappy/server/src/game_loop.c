/*
** EPITECH PROJECT, 2025
** Zappynian
** File description:
** game_loop
*/

#include "../include/game_loop.h"

void game_loop_init(server_t *server)
{
    if (!server) {
        return;
    }
    server->tick_count = 0;
    server->game_running = true;
}

void handle_resource_spawn(server_t *server)
{
    if (!server || !server->map)
        return;
    if (server->tick_count > 0 && server->tick_count % 20 == 0) {
        resource_spawn_periodic(server->map);
    }
    if (server->tick_count % 10 == 0) {
        resource_check_minimum(server->map);
    }
}

void game_loop_tick(server_t *server)
{
    if (!server || !server->game_running)
        return;
    server->tick_count++;
    handle_resource_spawn(server);
}

void game_loop_run(server_t *server)
{
    if (!server) {
        return;
    }
    game_loop_init(server);
    if (!server->game_running)
        return;
    server_loop(server);
}
