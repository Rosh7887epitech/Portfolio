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
    if (sfMouse_isButtonPressed(sfMouseRight) == 1) {
        if (sfMouse_getPosition(sfMouseLeft).x >= var->button_exit.pos.x &&
            sfMouse_getPosition(sfMouseLeft).x <= var->button_exit.pos.x +
            500 &&
            sfMouse_getPosition(sfMouseLeft).y <= var->button_exit.pos.y +
            230 &&
            sfMouse_getPosition(sfMouseLeft).y >= var->button_exit.pos.y) {
            sfRenderWindow_close(var->window);
        }
    }
}
