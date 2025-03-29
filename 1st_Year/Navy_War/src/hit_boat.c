/*
** EPITECH PROJECT, 2024
** project
** File description:
** load_boat
*/

#include "my.h"

int is_good_num_two(base_t *var, int x, int y)
{
    if (var->map_ptwo[y][x] == '2' || var->map_ptwo[y][x] == '3' ||
    var->map_ptwo[y][x] == '4' || var->map_ptwo[y][x] == '5') {
        return 1;
    }
    return 0;
}

int hit_boat_two(base_t *var, int x, int y)
{
    if (is_good_num_two(var, x, y) == 1) {
        var->map_ptwo[y][x] = 'x';
        return 1;
    } else {
        var->map_ptwo[y][x] = 'o';
        return 0;
    }
}

int is_good_num(base_t *var, int x, int y)
{
    if (var->map_pone[y][x] == '2' || var->map_pone[y][x] == '3' ||
    var->map_pone[y][x] == '4' || var->map_pone[y][x] == '5') {
        return 1;
    }
    return 0;
}

int hit_boat(base_t *var, int x, int y)
{
    if (is_good_num(var, x, y) == 1) {
        var->map_pone[y][x] = 'x';
        return 1;
    } else {
        var->map_pone[y][x] = 'o';
        return 0;
    }
}
