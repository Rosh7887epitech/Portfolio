/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-robin.schuffenecker
** File description:
** all_slide
*/

#include "my_project.h"

static void draw_slide(slide_t *slide, win_t *win)
{
    sfRenderWindow_drawCircleShape(win->win, slide->left, NULL);
    sfRenderWindow_drawCircleShape(win->win, slide->right, NULL);
    sfRenderWindow_drawRectangleShape(win->win, slide->bar, NULL);
    sfRenderWindow_drawRectangleShape(win->win, slide->cross, NULL);
}

void all_slide(win_t *win, canva_t *canva, button_t *but)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (move_cross(but->slide_size, win))
            canva->tools_size = but->slide_size->actual_value;
        if (move_cross(but->slide_trans, win)) {
            canva->tool_color.a = but->slide_trans->actual_value;
            sfRectangleShape_setFillColor(but->color->rect, canva->tool_color);
        }
    }
    draw_slide(but->slide_size, win);
    draw_slide(but->slide_trans, win);
}
