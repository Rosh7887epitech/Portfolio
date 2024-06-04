/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

void display(sfRenderWindow *window, sfSprite *my_sprite, sfIntRect rect, sfTexture *my_texture)
{
    sfRenderWindow_clear(window, sfBlack);
    size_of_sprite(rect, my_sprite, my_texture);
    sfRenderWindow_drawSprite(window, my_sprite, NULL);
    sfRenderWindow_display(window);
}

