/*
** EPITECH PROJECT, 2025
** Zappynian
** File description:
** Timing integration implementation
*/

#include "../include/timing_integration.h"
#include "../include/food_timer.h"
#include "../include/command_timer.h"
#include <stdlib.h>

int server_timing_init(server_t *server)
{
    if (!server || !server->args)
        return -1;
    server->timing_manager = malloc(sizeof(timing_manager_t));
    if (!server->timing_manager)
        return -1;
    if (timing_manager_init(server->timing_manager,
        server->args->frequency) != 0) {
        free(server->timing_manager);
        server->timing_manager = NULL;
        return -1;
    }
    server->food_timer = malloc(sizeof(food_timer_t));
    if (!server->food_timer) {
        free(server->timing_manager);
        server->timing_manager = NULL;
        return -1;
    }
    return food_timer_init((food_timer_t *)server->food_timer);
}

void server_timing_destroy(server_t *server)
{
    if (!server)
        return;
    if (server->timing_manager) {
        timing_manager_destroy(server->timing_manager);
        free(server->timing_manager);
        server->timing_manager = NULL;
    }
    if (server->food_timer) {
        food_timer_destroy((food_timer_t *)server->food_timer);
        free(server->food_timer);
        server->food_timer = NULL;
    }
}

void server_timing_tick(server_t *server)
{
    size_t i;

    if (!server || !server->timing_manager || !server->food_timer)
        return;
    timing_manager_mark_tick(server->timing_manager);
    food_timer_tick((food_timer_t *)server->food_timer);
    for (i = 0; i < server->player_count; i++) {
        if (server->players[i])
            command_timer_tick(server->players[i]);
    }
    process_food_consumption(server, server->food_timer);
}

int server_get_poll_timeout(server_t *server)
{
    if (!server || !server->timing_manager)
        return 100;
    return timing_manager_get_poll_timeout(server->timing_manager);
}

bool server_should_tick(server_t *server)
{
    if (!server || !server->timing_manager)
        return false;
    return timing_manager_should_tick(server->timing_manager);
}
