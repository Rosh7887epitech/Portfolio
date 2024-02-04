/*
** EPITECH PROJECT, 2023
** stat
** File description:
** stat
*/

#include "../include/soko.h"

int stat_of_file(int argc, char const **argv, soko_t *var, struct stat *sb)
{
    int v = 0;

    if (S_ISREG(sb->st_mode) != 0) {
        v = sokoban(argc, argv, var, sb);
        if (v == 84) {
            return 84;
        } else {
            return 0;
        }
        return 0;
    } else {
        return 84;
    }
}
