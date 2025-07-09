/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** action
*/

#include "my.h"

void send_player_score(int nbplayers, server_t *info, int i)
{
    for (int j = 1; j < nbplayers; j++) {
        dprintf(info->fds[i].fd, "801:%d %d\r\n", j, info->clients[j].score);
        if (info->showDebug)
            printf("<$ 801:%d %d\n", j, info->clients[j].score);
    }
}

void update_physics(server_t *info, struct timeval *last_print,
    float *elapsedTime)
{
    if ((*elapsedTime) < 0.1)
        return;
    gettimeofday(last_print, NULL);
    (*elapsedTime) = 0;
    for (int i = 1; i < info->nfds; i++) {
        info->clients[i].posY += 30.f;
        if (info->clients[i].posY < 70.0f)
            info->clients[i].posY = 70.0f;
        if (info->clients[i].posY > 920.0f)
            info->clients[i].posY = 920.0f;
        handle_collission(info, i);
    }
}

void update_player_pos(server_t *info, int i)
{
    info->clients[i].posY -= 40.f;
    dprintf(info->fds[i].fd, "201:%d OK\r\n", i);
    if (info->showDebug)
        printf("<$ 201:%d OK\n", i);
    handle_collission(info, i);
}

static void send_entity(int client_fd, char entity_type, int posX, int posY)
{
    if (entity_type == 'c')
        dprintf(client_fd, "701: COIN (%d;%d)\r\n", posX, posY);
    else if (entity_type == 'e')
        dprintf(client_fd, "701: ZAPPY (%d;%d)\r\n", posX, posY);
}

static void send_line_entities(server_t *info, int i, entity_args_t args)
{
    int cols = 0;
    int parsed = 0;
    int posX = 0;
    int posY = 0;
    int advanced = info->actual_map_index;
    char c = info->clients[i].player_map[args.row][advanced];

    for (cols = advanced; c != '\0' &&
        cols < my_strlen(info->clients[i].player_map[args.row]); cols++) {
            if (parsed > 18)
                break;
        posX = parsed * args.tile_width;
        posY = args.row * args.tile_height;
        send_entity(info->fds[i].fd, c, posX, posY);
        if (info->showDebug && (c == 'c' || c == 'e'))
            printf("<$ 701: %c (%d;%d)\n", c, posX, posY);
        c = info->clients[i].player_map[args.row][cols];
        parsed++;
    }
}

static void update_state_end_map(server_t *info)
{
    int bestPlayer = 0;

    for (int j = 1; j < info->nfds; j++) {
        if (info->clients[j].score > info->clients[bestPlayer].score)
            bestPlayer = j;
    }
    for (int j = 1; j < info->nfds; j++) {
        if (j == bestPlayer)
            info->clients[j].state = 1;
        else
            info->clients[j].state = 0;
    }
}

void send_entities(server_t *info, int i)
{
    int total_rows = 0;
    float elapsedTime = 0;

    if (info->clients[i].player_map == NULL ||
        info->clients[i].player_map[0] == NULL)
        return;
    for (; info->clients[i].player_map[total_rows] != NULL; total_rows++);
    for (int rows = 0; rows < total_rows; rows++)
    send_line_entities(info, i, (entity_args_t){rows, 107, 1080 / total_rows});
    elapsedTime = (info->first_clock.tv_sec - info->last_upt_enti.tv_sec) +
    (info->first_clock.tv_usec - info->last_upt_enti.tv_usec) / 1000000.0;
    if (i != 1 || elapsedTime < 0.5f)
        return;
    gettimeofday(&info->last_upt_enti, NULL);
    if (info->actual_map_index < strlen(info->clients[i].player_map[0])) {
        info->actual_map_index++;
        return;
    }
    update_state_end_map(info);
}

static void event_parse(char *msg, server_t *info, int i)
{
    if (my_strcmp(msg, "900 VICTORY") == 0)
        dprintf(info->fds[i].fd, "901: %d\r\n", info->clients[i].state);
    if (my_strcmp(msg, "800 SCORE") == 0)
        send_player_score(info->nfds, info, i);
}

void parse_event(char *msg, server_t *info, int i)
{
    if (msg) {
        if (my_strcmp(msg, "100 QUIT") == 0)
            disconnect_client(info, &i);
        if (my_strcmp(msg, "500 NB_PLAYERS") == 0)
            send_nb_player(info->fds[i].fd, info->nfds - 1, info->showDebug);
        if (my_strcmp(msg, "300 CONNECTED") == 0)
            send_connected(info, i);
        if (my_strcmp(msg, "400 POSITION") == 0)
            send_players_pos(info->nfds, info, i);
        if (my_strcmp(msg, "200 UP") == 0)
            update_player_pos(info, i);
        if (my_strcmp(msg, "600 START") == 0)
            send_start_game(info->nfds, info);
        if (my_strcmp(msg, "700 ENTITY") == 0)
            send_entities(info, i);
        event_parse(msg, info, i);
        free(msg);
    }
}
