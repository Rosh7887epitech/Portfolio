/*
** EPITECH PROJECT, 2024
** create_background.c
** File description:
** that function should init the background
*/

#include "my_project.h"

static sfRectangleShape *create_gui_right(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, (sfColor){74, 77, 81, 255});
    sfRectangleShape_setPosition(rect, (sfVector2f){1740, 90});
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){180, 375});
    sfRectangleShape_setOutlineColor(rect, (sfColor){54, 57, 61, 255});
    sfRectangleShape_setOutlineThickness(rect, 1);
    return rect;
}

static sfRectangleShape *create_gui_canva(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, (sfColor){74, 77, 81, 255});
    sfRectangleShape_setPosition(rect, (sfVector2f){1740, 480});
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){180, 400});
    sfRectangleShape_setOutlineColor(rect, (sfColor){54, 57, 61, 255});
    sfRectangleShape_setOutlineThickness(rect, 1);
    return rect;
}

static sfRectangleShape *create_gui_left(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, (sfColor){74, 77, 81, 255});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 107});
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){41, 360});
    return rect;
}

static sfRectangleShape *create_gui_up(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, (sfColor){74, 77, 81, 255});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 60});
    return rect;
}

win_t *create_gui(win_t *win)
{
    win->gui = create_gui_up();
    win->gui_left = create_gui_left();
    win->crossair_tab = create_crossair_tab();
    win->gui_canva = create_gui_canva();
    win->gui_right = create_gui_right();
    return win;
}

sfRectangleShape *create_background(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, (sfColor){50, 50, 50, 255});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    return rect;
}
