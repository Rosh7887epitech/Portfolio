/*
** EPITECH PROJECT, 2024
** modify_canva.c
** File description:
** that function should modify the canva
*/

#include "my_project.h"

static void place_one_pixel(int x, int y, canva_t *canva, layer_t *layer)
{
    int tab_index = 0;

    if (x >= canva->width || y >= canva->height || x < 0 || y < 0) {
        canva->old_pos.x = -1;
        canva->old_pos.y = -1;
        return;
    }
    tab_index = ((y * canva->width + x) * 4);
    layer->uint_tab[tab_index] = canva->tool_color.r;
    layer->uint_tab[tab_index + 1] = canva->tool_color.g;
    layer->uint_tab[tab_index + 2] = canva->tool_color.b;
    layer->uint_tab[tab_index + 3] = canva->tool_color.a;
}

static void place_rond(canva_t *canva, int y, layer_t *layer,
    sfVector2f pos)
{
    int pow_size = (canva->tools_size * canva->tools_size) / 2;
    int max_y = (y + canva->tools_size - 1);

    for (int j = y - canva->tools_size + 1; j <= max_y; j++) {
        if ((pos.x - pos.y) * (pos.x - pos.y) + (j - y) * (j - y) <= pow_size)
            place_one_pixel(pos.x, j, canva, layer);
    }
}

/* DISTANCE = SQRT((Xb - Xa)² + (Yb - Ya)²) */
void place_circle(int x, int y, canva_t *canva, layer_t *layer)
{
    int max_x = (x + canva->tools_size - 1);

    for (int i = x - canva->tools_size + 1; i <= max_x; i++)
        place_rond(canva, y, layer, (sfVector2f){i, x});
}

static int calcul_distance(int dest, int src)
{
    int result = dest - src;

    if (result < 0)
        result *= -1;
    return result;
}

static int calcul_mult_direction(int dest, int src)
{
    if (dest < src)
        return 1;
    return -1;
}

static void boucle_draw(canva_t *canva, int pos_x, int pos_y, layer_t *layer)
{
    for (int i = 0; i < canva->tools_size; i++) {
        for (int j = 0; j < canva->tools_size; j++)
            place_one_pixel(pos_x + i, pos_y + j, canva, layer);
    }
}

static void draw_good_shape(canva_t *canva, layer_t *layer, sfVector2i pos1)
{
    if (canva->tool_shape == RECTANGLE)
        boucle_draw(canva, pos1.x, pos1.y, layer);
    else
        place_circle(pos1.x, pos1.y, canva, layer);
}

void places_pixels(sfVector2i pos1, sfVector2i pos2, canva_t *canva,
    layer_t *layer)
{
    int dx = calcul_distance(pos2.x, pos1.x);
    int dy = calcul_distance(pos2.y, pos1.y);
    int multX = calcul_mult_direction(pos1.x, pos2.x);
    int multY = calcul_mult_direction(pos1.y, pos2.y);
    int verti_or_hori = dx - dy;
    int verti_or_hori2 = 0;

    while (pos1.x != pos2.x || pos1.y != pos2.y) {
        draw_good_shape(canva, layer, pos1);
        verti_or_hori2 = 2 * verti_or_hori;
        if (verti_or_hori2 > (dy * -1)) {
            verti_or_hori -= dy;
            pos1.x += multX;
        }
        if (verti_or_hori2 < dx) {
            verti_or_hori += dx;
            pos1.y += multY;
        }
    }
}
