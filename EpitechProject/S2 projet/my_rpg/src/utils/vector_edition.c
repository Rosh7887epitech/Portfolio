/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** vector_edition
*/

#include <SFML/Graphics.h>
#include "utils.h"

sfVector2f vector_edition(sfVector2f pos, int x, int y)
{
    sfVector2f new_pos = {pos.x + x, pos.y + y};

    return new_pos;
}
