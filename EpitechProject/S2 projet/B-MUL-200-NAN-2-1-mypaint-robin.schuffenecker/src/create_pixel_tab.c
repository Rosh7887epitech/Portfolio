/*
** EPITECH PROJECT, 2024
** create_pixel_tab.c
** File description:
** that file should handle all creation and modification on sfUint8 tab
*/

#include "my_project.h"
#include <stdio.h>

static void pixel_vertical(int pos_x, int pos_y, canva_t *canva,
    layer_t *layer)
{
    int tab_index = 0;
    int y = 0;

    for (int j = 0; j < canva->tools_size; j++) {
        y = pos_y + j;
        if (pos_x < canva->width && y < canva->height) {
            tab_index = ((y * canva->width + pos_x) * 4);
            layer->uint_tab[tab_index] = canva->tool_color.r;
            layer->uint_tab[tab_index + 1] = canva->tool_color.g;
            layer->uint_tab[tab_index + 2] = canva->tool_color.b;
            layer->uint_tab[tab_index + 3] = canva->tool_color.a;
        }
    }
}

static void draw_correctly(canva_t *canva, int pos_x, int pos_y,
    layer_t *layer)
{
    sfVector2i position = {pos_x, pos_y};
    int status = 0;

    if (layer == NULL)
        return;
    if (canva->old_pos.x != -1 && canva->old_pos.y != -1) {
        if (canva->tool_shape == RECTANGLE)
            places_pixels(position, canva->old_pos, canva, layer);
        else
            place_circle(pos_x, pos_y, canva, layer);
        status = 1;
    }
    if (status == 0 && canva->tool_shape == RECTANGLE) {
        for (int i = 0; i < canva->tools_size; i++)
            pixel_vertical(pos_x + i, pos_y, canva, layer);
    }
    if (status == 0 && canva->tool_shape == CIRCLE)
        place_circle(pos_x, pos_y, canva, layer);
    canva->old_pos.x = pos_x;
    canva->old_pos.y = pos_y;
}

static void get_sprite_info(sfSprite *sprite, canva_t *canva)
{
    canva->sprite_rect = sfSprite_getGlobalBounds(sprite);
    canva->scale = sfSprite_getScale(sprite);
}

sfUint8 *create_sfuint8_array(int height, int width)
{
    int window_size = height * width;
    sfUint8* array = malloc(sizeof(sfUint8) * (window_size * 4));

    for (int i = 0; i < window_size * 4; i++)
        array[i] = 255;
    return array;
}

void modify_sfuint8(win_t *win, canva_t *canva)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->win);
    int pos_x = 0;
    int pos_y = 0;
    layer_t *layer = canva->layer;

    get_sprite_info(canva->layer->screen_sprite, canva);
    if (click_pos.x < 1740 && sfFloatRect_contains(&canva->sprite_rect,
        click_pos.x, click_pos.y) && click_pos.y > 43 && click_pos.x > 43) {
        pos_x = (click_pos.x - canva->sprite_rect.left);
        pos_x /= canva->scale.x;
        pos_y = (click_pos.y - canva->sprite_rect.top) / canva->scale.y;
        while (layer && layer->is_active != sfTrue)
            layer = layer->next;
        draw_correctly(canva, pos_x, pos_y, layer);
        sfTexture_updateFromPixels(layer->texture, layer->uint_tab,
            canva->width, canva->height, 0, 0);
    } else {
        canva->old_pos.x = -1;
        canva->old_pos.y = -1;
    }
}

void draw_canva(canva_t *canva, win_t *win)
{
    layer_t *cpy = canva->layer;

    while (cpy) {
        if (cpy->is_visible)
            sfRenderWindow_drawSprite(win->win, cpy->screen_sprite, NULL);
        cpy = cpy->next;
    }
}
