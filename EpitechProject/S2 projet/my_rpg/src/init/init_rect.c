/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_rect
*/

#include "rpg.h"

sfIntRect init_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}
