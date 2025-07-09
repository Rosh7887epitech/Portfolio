/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** rect
*/

#include "my.h"
#include <SFML/Graphics.h>

void my_move_rect(sfIntRect *rect, int offset, int max_value, int *direction)
{
    rect->left += offset * (*direction);
    if (rect->left >= max_value) {
        *direction = -1;
        rect->left = max_value - (rect->left - max_value);
    } else if (rect->left <= 0) {
        *direction = 1;
        rect->left = -rect->left;
    }
}

void create_texture(sfSprite *sprite, sfTexture *texture, sfIntRect *rect)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, *rect);
}
