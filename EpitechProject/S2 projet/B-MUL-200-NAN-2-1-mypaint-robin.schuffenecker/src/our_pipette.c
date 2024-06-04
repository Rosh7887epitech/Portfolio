/*
** EPITECH PROJECT, 2024
** our_pipette.c
** File description:
** that function should handle the pipette tools
*/

#include "my_project.h"
#include <stdio.h>

sfColor get_pixel_color(layer_t *layer, int tab_index)
{
    sfColor color;

    color.r = layer->uint_tab[tab_index];
    color.g = layer->uint_tab[tab_index + 1];
    color.b = layer->uint_tab[tab_index + 2];
    color.a = layer->uint_tab[tab_index + 3];
    return color;
}

void our_pipette(win_t *win, canva_t *canva, button_t *button)
{
    layer_t *layer = canva->layer;
    sfVector2i click_pos;
    int pos_x = 0;
    int pos_y = 0;

    while (layer && layer->is_active != sfTrue)
        layer = layer->next;
    if (layer == NULL)
        return;
    click_pos = sfMouse_getPositionRenderWindow(win->win);
    pos_x = (click_pos.x - canva->sprite_rect.left) / canva->scale.x;
    pos_y = (click_pos.y - canva->sprite_rect.top) / canva->scale.y;
    pos_x = (pos_y * canva->width + pos_x) * 4;
    if (sfFloatRect_contains(&canva->sprite_rect, click_pos.x, click_pos.y))
        canva->tool_color = get_pixel_color(layer, pos_x);
    sfRectangleShape_setFillColor(button->color->rect, canva->tool_color);
}
