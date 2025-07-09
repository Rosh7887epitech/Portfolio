/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** send_response
*/

#include "my.h"

void send_nb_player(int fd, int nbplayers, bool debug)
{
    dprintf(fd, "501:%d\r\n", nbplayers);
    if (debug)
        printf("<$ 501:%d\n", nbplayers);
}

void send_players_pos(int nbplayers, server_t *info, int i)
{
    for (int j = 1; j < nbplayers; j++) {
        dprintf(info->fds[i].fd, "401:%d (%f;%f)\r\n", j,
            info->clients[j].posX,
            info->clients[j].posY);
        if (info->showDebug)
            printf("<$ 401:%d (%f;%f)\n", j, info->clients[j].posX,
                info->clients[j].posY);
    }
}

void send_connected(server_t *info, int i)
{
    dprintf(info->fds[i].fd, "301:%d OK\r\n", i);
    if (info->showDebug)
        printf("<$ 301:%d OK\n", i);
}

void send_start_game(int nbplayers, server_t *info)
{
    for (int j = 1; j < nbplayers; j++) {
        dprintf(info->fds[j].fd, "601: START\r\n");
        for (int j = 0; j < info->nfds; j++) {
            info->clients[j].posX = 100;
            info->clients[j].posY = 700;
            info->clients[j].player_map = copy_map(info->map);
            info->clients[j].state = -1;
            info->clients[j].score = 0;
        }
        info->actual_map_index = 0;
        if (info->showDebug)
            printf("<$ 601: START\n");
    }
}
