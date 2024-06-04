/*
** EPITECH PROJECT, 2023
** draw
** File description:
** draw
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void move_circle(circle_st *shape, base_st *var)
{
    sfVector2f move;
    circle_st *dup = shape;

    for (int i = 0; i < var->nb_c; i++) {
        move.x = sfCircleShape_getPosition(dup->c).x;
        move.y = sfCircleShape_getPosition(dup->c).y;
        move.x += rand() % 3 - 1;
        move.y += rand() % 3 - 1;
        sfCircleShape_setPosition(dup->c, move);
        dup = dup->next;
    }
    return;
}

void draw_circle(circle_st *shape, base_st *var)
{
    circle_st *tmp = shape;

    for (int i = 0; i < var->nb_c; i++) {
        sfRenderWindow_drawCircleShape(var->window, tmp->c, NULL);
        tmp = tmp->next;
    }
    move_circle(shape, var);
    return;
}
