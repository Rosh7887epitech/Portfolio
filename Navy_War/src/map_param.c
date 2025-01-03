/*
** EPITECH PROJECT, 2024
** map
** File description:
** map
*/

#include "my.h"

int display_map_pone(base_t *var)
{
    my_putstr("\nmy navy:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 18; j++) {
            my_putchar(var->map_pone[i][j]);
        }
        my_putstr("\n");
    }
    my_putstr("\nenemy navy:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 18; j++) {
            my_putchar(var->map_ptwo[i][j]);
        }
        my_putstr("\n");
    }
}

int display_map_ptwo(base_t *var)
{
    my_putstr("\nmy navy:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 18; j++) {
            my_putchar(var->map_ptwo[i][j]);
        }
        my_putstr("\n");
    }
    my_putstr("\nenemy navy:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 18; j++) {
            my_putchar(var->map_pone[i][j]);
        }
        my_putstr("\n");
    }
    my_putstr("\n");
}
