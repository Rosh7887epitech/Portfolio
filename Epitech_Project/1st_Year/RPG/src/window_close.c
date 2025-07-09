/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** window_close
*/

#include "rpg.h"
#include "macro.h"

void close_window_event(sfEvent event, window_node_t *window)
{
    if (event.type == sfEvtClosed) {
        CLOSE_WINDOW(window->window);
    }
}
