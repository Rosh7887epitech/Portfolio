/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** collision
*/
#include "my.h"
#include <math.h>
#include <stdio.h>

int map_row_count(char **map)
{
    int count = 0;

    if (map == NULL || map[0] == NULL)
        return 0;
    while (map[count] != NULL)
        count++;
    return count;
}

static void update_on_collide(server_t *info, int i, int posX, int posY)
{
    if (info->clients[i].player_map[posY][posX] == 'c') {
        info->clients[i].score += 1;
        info->clients[i].player_map[posY][posX] = '_';
    }
    if (info->clients[i].player_map[posY][posX] != 'e')
        return;
    info->clients[i].state = 0;
    for (int j = 0; j < info->nfds; j++) {
        if (j == i)
            continue;
        info->clients[j].state = 1;
    }
}

void handle_collide_cols(server_t *info, int i, int row, int advanced)
{
    int parsed = 0;
    char c = info->clients[i].player_map[row][advanced];
    int total_rows = map_row_count(info->clients[i].player_map);

    for (int cols = advanced; c != '\0' &&
        cols < my_strlen(info->clients[i].player_map[row]); cols++) {
        c = info->clients[i].player_map[row][cols];
        if (parsed > 18)
            break;
        if (c != 'c' && c != 'e') {
            parsed++;
            continue;
        }
        if ((info->clients[i].posX + 150 + 107 > parsed * (1920 / 18)) &&
        (info->clients[i].posX + 150 < parsed * (1920 / 18) + 50) &&
        (info->clients[i].posY + 107 > row * (1080 / total_rows)) &&
        (info->clients[i].posY < row * (1080 / total_rows)))
                    update_on_collide(info, i, cols, row);
        parsed++;
    }
}

void handle_collission(server_t *info, int i)
{
    int total_rows = map_row_count(info->clients[i].player_map);
    int advanced = info->actual_map_index;

    for (int row = 0; row < total_rows; row++) {
        handle_collide_cols(info, i, row, advanced);
    }
}
