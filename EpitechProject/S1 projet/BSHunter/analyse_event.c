/*
** EPITECH PROJECT, 2023
** event
** File description:
** event
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    sfMouseButtonEvent click;

    manage_mouse_click(click, window);
    close_window(window, event);
}
