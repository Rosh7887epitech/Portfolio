/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** menu_controller
*/

#include "rpg.h"

sfBool is_button_hovered(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&bounds, event->x, event->y)) {
        button->state = HOVER;
        return sfTrue;
    }
    button->state = NON;
    return sfFalse;
}

sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&bounds, event->x, event->y)) {
        button->state = CLICKED;
        return sfTrue;
    }
    button->state = NON;
    return sfFalse;
}

sfBool is_button_released(button_t *button, sfMouseButtonEvent *event)
{
    if (event->type == sfEvtMouseButtonReleased && button->state == CLICKED)
        button->state = RELEASED;
    return (button->state == RELEASED) ? sfTrue : sfFalse;
}

sfBool is_button_pressed(button_t *button, sfMouseButtonEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed && button->state == HOVER)
        button->state = CLICKED;
    return (button->state == CLICKED) ? sfTrue : sfFalse;
}
