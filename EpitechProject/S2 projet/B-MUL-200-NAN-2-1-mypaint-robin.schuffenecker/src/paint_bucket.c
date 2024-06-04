/*
** EPITECH PROJECT, 2024
** paint_bucket.c
** File description:
** that function should make the paint bucket tool
*/
#include "my_project.h"
#include <stdio.h>

// static int is_color_eq(sfColor *first, sfColor second)
// {
//     if (first->a != second.a)
//         return 1;
//     if (first->g != second.g)
//         return 1;
//     if (first->b != second.b)
//         return 1;
//     if (first->r != second.r)
//         return 1;
//     return 0;
// }

// static void fill_right(sfVector2i clickpos, canva_t *canva, sfColor *col,
//     sfColor *n_col)
// {
//     int tab_index = (clickpos.y * canva->width + clickpos.x) * 4;
//     int index_max = (clickpos.y * canva->width + canva->width) * 4;

//     for (int j = tab_index; j < index_max; j += 4) {
//         if (is_color_eq(col, get_pixel_color(canva->layer, j)) != 0)
//             return;
//         canva->layer->uint_tab[j] = n_col->r;
//         canva->layer->uint_tab[j + 1] = n_col->g;
//         canva->layer->uint_tab[j + 2] = n_col->b;
//         canva->layer->uint_tab[j + 3] = n_col->a;
//     }
//     return;
// }

// static void fill_left(sfVector2i clickpos, canva_t *canva, sfColor *col,
//     sfColor *n_col)
// {
//     int tab_index = (clickpos.y * canva->width + clickpos.x) * 4;
//     int index_max = (clickpos.y * canva->width * 4);

//     for (int j = tab_index; j >= index_max; j -= 4) {
//         if (is_color_eq(col, get_pixel_color(canva->layer, j - 4)) != 0)
//             return;
//         canva->layer->uint_tab[j] = n_col->r;
//         canva->layer->uint_tab[j + 1] = n_col->g;
//         canva->layer->uint_tab[j + 2] = n_col->b;
//         canva->layer->uint_tab[j + 3] = n_col->a;
//     }
//     return;
// }

// static void fill_line(sfVector2i clickpos, canva_t *canva, sfColor *col,
//     sfColor *n_col)
// {
//     sfVector2u text_size = sfTexture_getSize(canva->layer->texture);

//     fill_right(clickpos, canva, col, n_col);
//     fill_left(clickpos, canva, col, n_col);
//     sfTexture_updateFromPixels(canva->layer->texture,
//             canva->layer->uint_tab,
//         text_size.x, text_size.y, 0, 0);
// }

// void paint_bucket(canva_t *canva, win_t *win, sfColor *n_color)
// {
//     sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->win);
//     sfFloatRect sprite_rect =
//             sfSprite_getGlobalBounds(canva->layer->screen_sprite);
//     int pos_x = click_pos.x - sprite_rect.left;
//     int pos_y = click_pos.y - sprite_rect.top;
//     int tab_index = 0;
//     sfColor colored;

//     if (sfFloatRect_contains(&sprite_rect, click_pos.x, click_pos.y)) {
//         tab_index = (pos_y * canva->width + pos_x) * 4;
//         colored = get_pixel_color(canva->layer, tab_index);
//         click_pos.x = pos_x;
//         click_pos.y = pos_y;
//         fill_line(click_pos, canva, &colored, n_color);
//     }
// }
