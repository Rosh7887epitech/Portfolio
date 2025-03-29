/*
** EPITECH PROJECT, 2023
** shape
** File description:
** shape
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int circle_init(base_st *var, circle_st **shape)
{
    sfCircleShape *rond;
    circle_st *src = (*shape);

    rond = sfCircleShape_create();
    var->zone.start.x = 100;
    var->zone.start.y = 100;
    var->zone.end.x = 100;
    var->zone.end.y = 100;
    var->zone.radius = 10;
    var->zone.thickness = 3;
    sfCircleShape_setPosition(rond, var->zone.start);
    sfCircleShape_setRadius(rond, var->zone.radius);
    sfCircleShape_setOutlineThickness(rond, var->zone.thickness);
    sfCircleShape_setOutlineColor(rond, sfTransparent);
    sfCircleShape_setFillColor(rond, sfTransparent);
    add_circle_st(shape, rond, 0);
    return 0;
}

int tower_circle_init(base_st *var, tower_st **tow)
{
    sfCircleShape *cercle;

    cercle = sfCircleShape_create();
    var->zone.start.x = 100;
    var->zone.start.y = 100;
    var->zone.radius = 70;
    var->zone.thickness = 2;
    sfCircleShape_setPosition(cercle, var->zone.start);
    sfCircleShape_setRadius(cercle, var->zone.radius);
    sfCircleShape_setOutlineThickness(cercle, var->zone.thickness);
    sfCircleShape_setOutlineColor(cercle, sfGreen);
    sfCircleShape_setFillColor(cercle, sfTransparent);
    add_tower_st(tow, cercle, 0);
    return 0;
}

sfRectangleShape *square_init(float x, float y)
{
    sfRectangleShape *square;

    square = sfRectangleShape_create();
    sfRectangleShape_setSize(square, (sfVector2f){20.0, 20.0});
    sfRectangleShape_setPosition(square, (sfVector2f){x, y});
    sfRectangleShape_setOutlineThickness(square, 1.0);
    sfRectangleShape_setOutlineColor(square, sfRed);
    sfRectangleShape_setFillColor(square, sfTransparent);
    return square;
}
