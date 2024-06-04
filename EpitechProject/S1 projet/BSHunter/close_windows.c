/*
** EPITECH PROJECT, 2023
** close windows
** File description:
** close windows
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}
