/*
** EPITECH PROJECT, 2023
** compt
** File description:
** coordinate
*/

#include "../include/soko.h"

static int search_o(soko_t *var, int i, int j)
{
    if (var->map[i][j] == 'O') {
        var->nb_o++;
    }
}

static int search_x(soko_t *var, int i, int j)
{
    if (var->map[i][j] == 'X') {
        var->nb_x++;
    }
}

int nb_of_o(soko_t *var)
{
    for (int i = 0; i != var->row; i++) {
        for (int j = 0; j != var->col; j++) {
            search_o(var, i, j);
        }
    }
    return var->nb_o;
}

int nb_of_x(soko_t *var)
{
    for (int i = 0; i != var->row; i++) {
        for (int j = 0; j != var->col; j++) {
            search_x(var, i, j);
        }
    }
    return var->nb_o;
}
