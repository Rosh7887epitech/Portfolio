/*
** EPITECH PROJECT, 2024
** plane
** File description:
** plane
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

sfSprite *plane(float x, float y)
{
    sfSprite *plane = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("content/plane.png", NULL);

    sizeof
    sfSprite_setPosition(plane, (sfVector2f){x, y});
    sfSprite_setTexture(plane, texture, sfFalse);
    sfSprite_setScale(plane, (sfVector2f){20.0 / 100.0, 20.0 / 100.0});
    return plane;
}
