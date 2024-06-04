/*
** EPITECH PROJECT, 2023
** mouse
** File description:
** click
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "game.h"

void manage_mouse_click(sfMouseButtonEvent event, sfRenderWindow *window)
{
    if (event.button == sfMouseLeft) {
        my_putstr("Mouse x=");
        my_put_nbr(event.x);
        my_putstr(" ");
        my_putstr("y=");
        my_put_nbr(event.y);
        my_putstr("\n");
    }
}
