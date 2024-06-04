/*
** EPITECH PROJECT, 2024
** create_button.c
** File description:
** this file should init the button
*/

#include "my_project.h"

sfRectangleShape *init_rectshape(sfVector2f pos, sfVector2f size, sfColor col,
    char *filepath)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfTexture *texture = NULL;
    sfColor gris = sfColor_fromRGBA(54, 57, 61, 255);

    if (filepath != NULL) {
        texture = sfTexture_createFromFile(filepath, NULL);
        sfRectangleShape_setTexture(rect, texture, sfTrue);
    } else
        sfRectangleShape_setFillColor(rect, col);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, gris);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

obj_t *init_button(sfVector2f pos, sfVector2f size, sfColor color,
    char *filepath)
{
    obj_t *object = malloc(sizeof(obj_t));

    object->rect = init_rectshape(pos, size, color, filepath);
    object->is_clicked = is_clicked;
    object->is_button_hover = is_button_hover;
    object->state = NON;
    return object;
}

void draw_tools_button(win_t *win, button_t *butt)
{
    sfRenderWindow_drawRectangleShape(win->win, butt->pen->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->color->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->zoomminus->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->zoomplus->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->rubber->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->move_hand->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->pipette->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->addlayer->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->dellayer->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win,
    butt->sw->switch_shape->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->square->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, butt->round->rect, NULL);
}
