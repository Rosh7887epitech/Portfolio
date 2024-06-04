/*
** EPITECH PROJECT, 2024
** evenement.c
** File description:
** that file should handle the user evenmenet
*/

#include "my_project.h"

static void outline_base_color(button_t *button)
{
    sfColor color = (sfColor){54, 57, 61, 255};

    sfRectangleShape_setOutlineColor(button->pen->rect, color);
    sfRectangleShape_setOutlineColor(button->rubber->rect, color);
    sfRectangleShape_setOutlineColor(button->color->rect, color);
    sfRectangleShape_setOutlineColor(button->pipette->rect, color);
    sfRectangleShape_setOutlineColor(button->move_hand->rect, color);
}

static int tool_button_four(win_t *win, canva_t *canva, button_t *button)
{
    if (is_button_pressed(win->event, button->sw->switch_shape)
        && canva->tool_shape == RECTANGLE) {
        sfRectangleShape_setTexture(button->sw->switch_shape->rect,
            button->sw->switch2, sfTrue);
        canva->tool_shape = CIRCLE;
        return 0;
    }
    if (is_button_pressed(win->event, button->sw->switch_shape)
        && canva->tool_shape == CIRCLE) {
        sfRectangleShape_setTexture(button->sw->switch_shape->rect,
            button->sw->switch1, sfTrue);
        canva->tool_shape = RECTANGLE;
        return 0;
    }
    return 1;
}

static int tool_button_three(win_t *win, canva_t *canva, button_t *button)
{
    if (is_button_pressed(win->event, button->zoomplus)) {
        canva->tool = NONE;
        zoom_plus(canva);
        outline_base_color(button);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    if ((is_button_pressed(win->event, button->rubber))) {
        canva->tool = RUBBER;
        outline_base_color(button);
        sfRectangleShape_setOutlineColor(button->rubber->rect, sfWhite);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    if (canva->tool == NONE)
        outline_base_color(button);
    return tool_button_four(win, canva, button);
}

static int tool_button_two(win_t *win, canva_t *canva, button_t *button)
{
    if ((is_button_pressed(win->event, button->move_hand))) {
        canva->tool = HAND;
        outline_base_color(button);
        sfRectangleShape_setOutlineColor(button->move_hand->rect, sfWhite);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    if (is_button_pressed(win->event, button->pipette)) {
        canva->tool = PIPETTE;
        outline_base_color(button);
        sfRectangleShape_setOutlineColor(button->pipette->rect, sfWhite);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    if (is_button_pressed(win->event, button->addlayer)) {
        add_layer(&canva);
        return 0;
    }
    return tool_button_three(win, canva, button);
}

static int tool_button_one(win_t *win, canva_t *canva, button_t *button)
{
    if ((is_button_pressed(win->event, button->color))) {
        canva->tool = COLOR;
        sfRectangleShape_setFillColor(button->color->rect, canva->tool_color);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    if (is_button_pressed(win->event, button->zoomminus)) {
        canva->tool = NONE;
        zoom_minus(canva);
        outline_base_color(button);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    return tool_button_two(win, canva, button);
}

static int button_tools(win_t *win, canva_t *canva, button_t *button)
{
    if (win->event.type != sfEvtMouseButtonPressed)
        return 1;
    if ((is_button_pressed(win->event, button->color))
    && canva->tool == COLOR) {
        canva->tool = PENCIL;
        outline_base_color(button);
        sfRectangleShape_setOutlineColor(button->pen->rect, sfWhite);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    if ((is_button_pressed(win->event, button->pen))) {
        canva->tool = PENCIL;
        outline_base_color(button);
        sfRectangleShape_setOutlineColor(button->pen->rect, sfWhite);
        switch_crossair(win, win->crossair_tab, canva);
        return 0;
    }
    return tool_button_one(win, canva, button);
}

static int button_layer(win_t *win, canva_t *canva)
{
    layer_t *cpy = canva->layer;

    if (win->event.type != sfEvtMouseButtonPressed)
        return 1;
    while (cpy) {
        if (is_button_pressed(win->event, cpy->button[0])) {
            reset_actif_layer(canva, cpy);
        }
        if (is_button_pressed(win->event, cpy->button[1])) {
            set_visible_layer_state(cpy);
            return 0;
        }
        cpy = cpy->next;
    }
    return 1;
}

static void zoom_scrool(win_t *win, canva_t *canva)
{
    if (win->event.type == sfEvtMouseWheelScrolled) {
        if (win->event.mouseWheelScroll.delta > 0)
            zoom_plus(canva);
        else
            zoom_minus(canva);
    }
    return;
}

void evenement_user(win_t *win, canva_t *canva, button_t *button)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(win->win);
            return;
        }
        if (win->event.type == sfEvtMouseButtonReleased) {
            canva->old_pos.x = -1;
            canva->old_pos.y = -1;
        }
        zoom_scrool(win, canva);
        if (button_tools(win, canva, button) == 0)
            return;
        if (button_layer(win, canva) == 0)
            return;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            tools_action(win, canva, button);
            delete_layer(win, canva, button);
        }
    }
}
