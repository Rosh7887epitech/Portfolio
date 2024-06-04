/*
** EPITECH PROJECT, 2024
** button_action.c
** File description:
** that file should handle the action do by the button
*/

#include "my_project.h"
#include <stdio.h>

sfBool is_clicked(obj_t *button, sfMouseButtonEvent *evt)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button->rect);

    if (evt->x >= bound.left && evt->x <= bound.left + bound.width &&
        evt->y >= bound.top && evt->y <= bound.top + bound.height) {
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_button_hover(obj_t *button, sfMouseMoveEvent *evt)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button->rect);

    if (evt->x >= bound.left && evt->x <= bound.left + bound.width &&
        evt->y >= bound.top && evt->y <= bound.top + bound.height) {
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_button_pressed(sfEvent event, obj_t *button)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (button->is_clicked(button, &event.mouseButton)) {
            return sfTrue;
        }
    }
    return sfFalse;
}
