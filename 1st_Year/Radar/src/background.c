/*
** EPITECH PROJECT, 2024
** background
** File description:
** background
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

sfSprite *background(void)
{
    sfSprite *background = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("content/map.png", NULL);

    sfSprite_setPosition(background, (sfVector2f){0, 0});
    sfSprite_setTexture(background, texture, sfFalse);
    sfSprite_setScale(background, (sfVector2f){1, 1});
    return background;
}
