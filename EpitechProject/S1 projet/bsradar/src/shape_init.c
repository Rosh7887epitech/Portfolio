/*
** EPITECH PROJECT, 2023
** shape
** File description:
** shape
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int circle_init(base_st *var, circle_st **shape, float x, float y)
{
    sfCircleShape *rond;

    rond = sfCircleShape_create();
    var->zone.pos.x = x;
    var->zone.pos.y = y;
    var->zone.radius = 35;
    var->zone.thickness = 3;
    sfCircleShape_setPosition(rond, var->zone.pos);
    sfCircleShape_setRadius(rond, var->zone.radius);
    sfCircleShape_setOutlineThickness(rond, var->zone.thickness);
    sfCircleShape_setOutlineColor(rond, sfRed);
    sfCircleShape_setFillColor(rond, sfTransparent);
    add_circle_st(shape, rond, 0);
}
