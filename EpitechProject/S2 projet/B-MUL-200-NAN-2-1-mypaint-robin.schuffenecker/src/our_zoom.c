/*
** EPITECH PROJECT, 2024
** our_zoom.c
** File description:
** that function should handle the zoom function
*/
#include "my_project.h"

void zoom_minus(canva_t *canva)
{
    layer_t *layer = canva->layer;
    sfVector2f scale = sfSprite_getScale(layer->screen_sprite);
    sfSprite *sprite;

    if (scale.x <= 0.1 || scale.y <= 0.1)
        return;
    scale.x -= 0.2;
    scale.y -= 0.2;
    sprite = layer->screen_sprite;
    while (layer) {
        sfSprite_setScale(layer->screen_sprite, scale);
        canva->scale = scale;
        canva->height = sfTexture_getSize(layer->texture).y;
        canva->width = sfTexture_getSize(layer->texture).x;
        canva->sprite_rect = sfSprite_getGlobalBounds(sprite);
        layer = layer->next;
    }
    return;
}

void zoom_plus(canva_t *canva)
{
    layer_t *layer = canva->layer;
    sfVector2f scale = sfSprite_getScale(layer->screen_sprite);
    sfSprite *sprite = layer->screen_sprite;

    scale.x += 0.2;
    scale.y += 0.2;
    while (layer) {
        sfSprite_setScale(layer->screen_sprite, scale);
        canva->scale = scale;
        canva->height = sfTexture_getSize(layer->texture).y;
        canva->width = sfTexture_getSize(layer->texture).x;
        canva->sprite_rect = sfSprite_getGlobalBounds(sprite);
        layer = layer->next;
    }
    return;
}
