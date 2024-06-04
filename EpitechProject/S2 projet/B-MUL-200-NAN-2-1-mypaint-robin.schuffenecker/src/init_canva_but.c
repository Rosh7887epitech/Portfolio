/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-robin.schuffenecker
** File description:
** init_canva_but
*/

#include "my_project.h"

void draw_canva_layer(win_t *win, layer_t *list)
{
    while (list) {
        sfRenderWindow_drawRectangleShape(win->win,
            list->button[0]->rect, NULL);
        sfRenderWindow_drawRectangleShape(win->win,
            list->button[1]->rect, NULL);
        list = list->next;
    }
}

obj_t **init_canva_but(sfVector2f pos)
{
    obj_t **but = malloc(sizeof(obj_t *) * 2);
    sfColor color = (sfColor){100, 100, 100, 100};

    but[0] = init_button(pos, (sfVector2f){150, 30}, color, NULL);
    pos.x += 150;
    but[1] = init_button(pos, (sfVector2f){30, 30}, color, "./img/eye.png");
    return but;
}
