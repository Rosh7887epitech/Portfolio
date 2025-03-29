/*
** EPITECH PROJECT, 2023
** close windows
** File description:
** close windows
*/

#include "../include/include.h"
#include "../include/game.h"
#include "../include/my.h"

void touch(base_st *var, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyL) {
        if (var->l_touch == 0)
            var->l_touch = 1;
        else
            var->l_touch = 0;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyS) {
        if (var->s_touch == 0)
            var->s_touch = 1;
        else
            var->s_touch = 0;
    }
}

int end_close(base_st *var, circle_st *shape, sfEvent event)
{
    int j = 0;

    while (shape != NULL) {
        if (shape->bol != -1)
            j = 0;
        else
            j = 1;
        shape = shape->next;
    }
}

void close_window(base_st *var, circle_st *shape, sfEvent event)
{
    while (sfRenderWindow_pollEvent(var->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(var->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(var->window);
        if (end_close(var, shape, event) == 1)
            sfRenderWindow_close(var->window);
        touch(var, event);
    }
}
