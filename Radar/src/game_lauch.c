/*
** EPITECH PROJECT, 2024
** game
** File description:
** game
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void game(base_st *var, tower_st *tow, circle_st *shape)
{
    verif_collision(shape, var);
    draw_circle(&shape, tow, var);
    timer(var);
}
