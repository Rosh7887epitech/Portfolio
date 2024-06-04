/*
** EPITECH PROJECT, 2024
** rendu_n4S
** File description:
** stay_straight
*/
#include <unistd.h>
#include "my.h"

int go_back_if_block(char *line, size_t buff, info_t *info)
{
    if (atoi(info->first_info) <= 120 || atoi(info->last_info) <= 120) {
        move_backwards(line, buff, 1);
        cycle_wait(line, buff, 3);
    }
}

int straight_line(char *line, size_t buff, info_t *info)
{
    if (atoi(info->mid_info) > 2000) {
        info->speed = 1;
    }
    move_forward(line, buff, info->speed);
    info->speed = 0.35;
    cycle_wait(line, buff, 1);
    if (atoi(info->mid_info) > 2000) {
        info->continue_while = 1;
        return 0;
    } else {
        return 1;
    }
}

int turning_corners(char *line, size_t buff, info_t *info)
{
    if (atoi(info->first_info) < atoi(info->last_info)) {
        if (atoi(info->first_info) <= 680) {
            turn(line, buff, -0.35);
            cycle_wait(line, buff, 2);
            turn(line, buff, 0);
        }
    } else {
        if (atoi(info->last_info) <= 680) {
            turn(line, buff, 0.35);
            cycle_wait(line, buff, 2);
            turn(line, buff, 0);
        }
    }
}

int stay_straight(char *line, size_t buff, info_t *info)
{
    go_back_if_block(line, buff, info);
    if (straight_line(line, buff, info) == 0) {
        return 0;
    }
    while (atoi(info->first_info) <= 700) {
        get_lidar(line, buff, info);
        turning_corners(line, buff, info);
    }
    while (atoi(info->last_info) <= 700) {
        get_lidar(line, buff, info);
        turning_corners(line, buff, info);
    }
}
