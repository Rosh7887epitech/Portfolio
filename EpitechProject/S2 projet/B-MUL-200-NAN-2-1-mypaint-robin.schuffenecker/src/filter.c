/*
** EPITECH PROJECT, 2024
** filter.c
** File description:
** that function should make the filter
*/

#include "my_project.h"

void black_and_white(canva_t *canva)
{
    sfImage *image = sfTexture_copyToImage(canva->layer->texture);
    sfColor color;
    int calcul = 0;
    sfColor new_color;
    layer_t *layer = canva->layer;

    while (layer && layer->is_active != sfTrue)
        layer = layer->next;
    if (!layer)
        return;
    for (int y = 0; y < canva->height; ++y) {
        for (int x = 0; x < canva->width; ++x) {
            color = sfImage_getPixel(image, x, y);
            calcul = color.r * 0.299 + color.g * 0.587 + color.b * 0.114;
            new_color = (sfColor){calcul, calcul, calcul, color.a};
            sfImage_setPixel(image, x, y, new_color);
        }
    }
    sfTexture_updateFromImage(canva->layer->texture, image, 0, 0);
    canva->layer->uint_tab = (sfUint8 *)sfImage_getPixelsPtr(image);
}

void xray_filter(canva_t *canva)
{
    sfImage *image = sfTexture_copyToImage(canva->layer->texture);
    sfColor color;
    sfColor new_color;
    layer_t *layer = canva->layer;

    while (layer && layer->is_active != sfTrue)
        layer = layer->next;
    if (!layer)
        return;
    for (int y = 0; y < canva->height; ++y) {
        for (int x = 0; x < canva->width; ++x) {
            color = sfImage_getPixel(image, x, y);
            new_color = (sfColor){color.b, color.g, color.r, color.a};
            sfImage_setPixel(image, x, y, new_color);
        }
    }
    sfTexture_updateFromImage(canva->layer->texture, image, 0, 0);
    canva->layer->uint_tab = (sfUint8 *)sfImage_getPixelsPtr(image);
}

void invert_color(canva_t *canva)
{
    sfImage *image = sfTexture_copyToImage(canva->layer->texture);
    sfColor color;
    sfColor new_color;
    layer_t *layer = canva->layer;

    while (layer && layer->is_active != sfTrue)
        layer = layer->next;
    if (!layer)
        return;
    for (int y = 0; y < canva->height; ++y) {
        for (int x = 0; x < canva->width; ++x) {
            color = sfImage_getPixel(image, x, y);
            new_color = (sfColor){255 - color.b, 255 - color.g,
                255 - color.r, color.a};
            sfImage_setPixel(image, x, y, new_color);
        }
    }
    sfTexture_updateFromImage(canva->layer->texture, image, 0, 0);
    canva->layer->uint_tab = (sfUint8 *)sfImage_getPixelsPtr(image);
}
