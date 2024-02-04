/*
** EPITECH PROJECT, 2024
** verif
** File description:
** la map
*/

#include "my.h"

int loop_map_two(base_t *var, int g, int i)
{
    for (int j = 0; j < 10; j++) {
        if (var->map_ptwo[j][i] == 'x')
            g++;
    }
    return g;
}

int verif_map_two(base_t *var)
{
    int g = 0;

    for (int i = 0; i < 18; i++) {
        g = loop_map_two(var, g, i);
    }
    if (g == 14)
        var_sig.bol = 2;
}

int loop_map(base_t *var, int g, int i)
{
    for (int j = 0; j < 10; j++) {
        if (var->map_pone[j][i] == 'x')
            g++;
    }
    return g;
}

int verif_map(base_t *var)
{
    int g = 0;

    for (int i = 0; i < 18; i++) {
        g = loop_map(var, g, i);
    }
    if (g == 14)
        var_sig.bol = 1;
}
