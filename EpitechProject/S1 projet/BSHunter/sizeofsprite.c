/*
** EPITECH PROJECT, 2023
** size_of_sprite
** File description:
** size_of_sprite
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

void size_of_sprite(sfIntRect rect, sfSprite *my_sprite, sfTexture *my_texture)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    sfSprite_setTextureRect(my_sprite, rect);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
}
