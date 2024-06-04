/*
** EPITECH PROJECT, 2024
** B-AIA-200-NAN-2-1-n4s-robin.schuffenecker
** File description:
** info_func
*/

#include <unistd.h>
#include "my.h"

void get_lidar(char *line, size_t buff, info_t *info)
{
    info->first_info = NULL;
    info->last_info = NULL;
    info->mid_info = NULL;
    dprintf(1, "GET_INFO_LIDAR\n");
    getline(&line, &buff, stdin);
    info->first_info = strtok(strdup(line), ":");
    for (int i = 0; i < 3; i++) {
        info->first_info = strtok(NULL, ":");
    }
    info->last_info = strtok(strdup(line), ":");
    for (int i = 0; i < 34; i++) {
        info->last_info = strtok(NULL, ":");
    }
    info->mid_info = strtok(strdup(line), ":");
    for (int i = 0; i < 19; i++) {
        info->mid_info = strtok(NULL, ":");
    }
    return;
}

void get_info(char *line, size_t buff)
{
    dprintf(1, "GET_INFO_SIMTIME\n");
    getline(&line, &buff, stdin);
    dprintf(2, line);
}
