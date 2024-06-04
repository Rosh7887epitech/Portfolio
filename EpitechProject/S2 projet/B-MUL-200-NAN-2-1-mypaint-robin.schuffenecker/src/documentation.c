/*
** EPITECH PROJECT, 2024
** BSpaint
** File description:
** documentation
*/

#include "my_project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int evenement_doc(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            sfRenderWindow_close(win->win);
            return 0;
        }
    }
    return 1;
}

win_t *init_doc_window(void)
{
    sfVideoMode win_size = {1920, 1080, 0};
    win_t *window = malloc(sizeof(win_t));

    window->win = sfRenderWindow_create(win_size, "My Paint Documentation",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->win, 60);
    sfRenderWindow_setMouseCursorVisible(window->win, sfTrue);
    window->background = init_rectshape((sfVector2f){0, 0},
        (sfVector2f){1920, 1080}, sfRed, "img/help.png");
    return window;
}

void doc_loop(menu_t *menu)
{
    win_t *win = init_doc_window();
    sfColor gris = (sfColor){255, 230, 195, 255};

    while (sfRenderWindow_isOpen(win->win)) {
        sfRenderWindow_clear(win->win, gris);
        evenement_doc(win);
        sfRenderWindow_drawRectangleShape(win->win, win->background, sfFalse);
        sfRenderWindow_display(win->win);
    }
    sfRenderWindow_destroy(win->win);
    sfRectangleShape_destroy(win->background);
    free(win);
    menu->state = RELEASED;
    return;
}
