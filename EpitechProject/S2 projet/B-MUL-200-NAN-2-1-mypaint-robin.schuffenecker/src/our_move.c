/*
** EPITECH PROJECT, 2024
** our_move.c
** File description:
** that function should handle the movement of the canva
*/
#include "my_project.h"

void move_canva(win_t *win, canva_t *canva)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->win);
    int pos_x = (click_pos.x);
    int pos_y = (click_pos.y);
    sfVector2f pos = (sfVector2f){pos_x, pos_y};
    layer_t *lay = canva->layer;

    if (sfFloatRect_contains(&canva->sprite_rect, pos_x, pos_y)) {
        while (lay) {
            sfSprite_setPosition(lay->screen_sprite, pos);
            lay = lay->next;
        }
    }
    return;
}
