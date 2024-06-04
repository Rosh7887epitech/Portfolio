/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** sprite
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

void set_sprite(sfTexture *my_texture, sfSprite *my_sprite,
    sfVector2f my_pos, sfVector2f scale)
{
    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
}
