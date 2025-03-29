/*
** EPITECH PROJECT, 2023
** coordinate
** File description:
** coordinate
*/

#include "../include/soko.h"

static int search(soko_t *var, int i, int j, int index)
{
    if (var->map[i][j] == 'O') {
        var->coor_o_y[index] = i;
        var->coor_o_x[index] = j;
        index++;
    }
    return index;
}

static int search_x(soko_t *var, int i, int j, int index)
{
    if (var->map[i][j] == 'X') {
        var->coor_x_y[index] = i;
        var->coor_x_x[index] = j;
        index++;
    }
    return index;
}

soko_t *coordinate_of_o(soko_t *var)
{
    int index = 0;

    var->coor_o_x = malloc(sizeof(int)* var->nb_o);
    var->coor_o_y = malloc(sizeof(int)* var->nb_o);
    for (int i = 0; i < var->row; i++) {
        for (int j = 0; var->map[i][j] != '\n'; j++) {
            index = search(var, i, j, index);
        }
    }
    return var;
}

soko_t *coordinate_of_x(soko_t *var)
{
    int index = 0;

    var->coor_x_x = malloc(sizeof(int)* var->nb_x);
    var->coor_x_y = malloc(sizeof(int)* var->nb_x);
    for (int i = 0; i < var->row; i++) {
        for (int j = 0; var->map[i][j] != '\n'; j++) {
            index = search_x(var, i, j, index);
        }
    }
    return var;
}

int object(soko_t *var)
{
    var->nb_o = nb_of_o(var);
    var->nb_x = nb_of_x(var);
    coordinate_of_o(var);
    coordinate_of_x(var);
}
