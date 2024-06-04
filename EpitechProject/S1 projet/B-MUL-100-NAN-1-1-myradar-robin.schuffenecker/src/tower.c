/*
** EPITECH PROJECT, 2024
** tower
** File description:
** tower
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

sfSprite *tower(float x, float y)
{
    sfSprite *tower = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("content/tower.png", NULL);

    sfSprite_setPosition(tower, (sfVector2f){x, y});
    sfSprite_setOrigin(tower, (sfVector2f){0.0, 0.0});
    sfSprite_setTexture(tower, texture, sfFalse);
    sfSprite_setScale(tower, (sfVector2f){40.0 / 500.0, 40.0 / 500.0});
    return tower;
}
