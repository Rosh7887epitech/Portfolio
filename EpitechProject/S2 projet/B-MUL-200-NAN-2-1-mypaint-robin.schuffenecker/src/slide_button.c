/*
** EPITECH PROJECT, 2024
** slide_button.c
** File description:
** that functio should init the slide menu
*/

#include "my_project.h"

static int update_value(slide_t *slide)
{
    sfVector2f pos_cross = sfRectangleShape_getPosition(slide->cross);
    sfVector2f pos_bar = sfRectangleShape_getPosition(slide->bar);
    float lenght_bar = sfRectangleShape_getSize(slide->bar).x - 10;
    float real = pos_cross.x - pos_bar.x;
    float value = (slide->max_value / lenght_bar) * real;

    if (value >= 255)
        return 255;
    return value + 1;
}

static int update_position(sfVector2i click_pos, slide_t *slide,
    int lenght_bar)
{
    sfVector2f pos;
    sfVector2f pos_bar;
    int value = 0;

    pos_bar = sfRectangleShape_getPosition(slide->bar);
    pos = sfRectangleShape_getPosition(slide->cross);
    pos_bar.x -= 1;
    if (click_pos.x > pos_bar.x && click_pos.x < pos_bar.x + lenght_bar) {
        pos = (sfVector2f){click_pos.x, pos.y};
        sfRectangleShape_setPosition(slide->cross, pos);
        value = update_value(slide);
        slide->actual_value = value;
        return value;
    }
    return slide->actual_value;
}

sfCircleShape *create_circle(sfVector2f pos, float radius, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, (float)radius);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOrigin(circle, (sfVector2f){0, 0});
    return circle;
}

slide_t *create_slide(sfVector2f pos, int max_value, int start_value)
{
    slide_t *slide = malloc(sizeof(slide_t));

    slide->bar = init_rectshape(pos, (sfVector2f){140, 10}, sfWhite, NULL);
    sfRectangleShape_setOutlineColor(slide->bar, sfWhite);
    pos.x -= 5;
    slide->left = create_circle(pos, 5, sfWhite);
    pos.x += 140;
    slide->right = create_circle(pos, 5, sfWhite);
    pos.x = pos.x - 145 + ((140 * start_value) / max_value);
    slide->start_pos = (sfVector2f){pos.x, pos.y - 2};
    slide->cross = init_rectshape((sfVector2f){pos.x, pos.y - 5},
        (sfVector2f){6, 20}, sfWhite, NULL);
    sfRectangleShape_setOutlineThickness(slide->cross, 3);
    sfRectangleShape_setOutlineColor(slide->cross, sfBlack);
    slide->max_value = max_value;
    slide->actual_value = start_value;
    if (slide->actual_value > 255)
        slide->actual_value = 255;
    return slide;
}

int move_cross(slide_t *slide, win_t *win)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(slide->bar);
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->win);
    float lenght_bar = 0.0;

    if (sfFloatRect_contains(&bounds, click_pos.x, click_pos.y)) {
        win->event.type = sfEvtKeyReleased;
        lenght_bar = sfRectangleShape_getSize(slide->bar).x - 8;
        return update_position(click_pos, slide, lenght_bar);
    }
    return sfFalse;
}
