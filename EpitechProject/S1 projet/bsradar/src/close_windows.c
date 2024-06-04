/*
** EPITECH PROJECT, 2023
** close windows
** File description:
** close windows
*/

#include "../include/include.h"
#include "../include/game.h"
#include "../include/my.h"

void close_window(base_st *var, sfEvent event)
{
    while (sfRenderWindow_pollEvent(var->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(var->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1) {
            sfRenderWindow_close(var->window);
        }
    }
}
