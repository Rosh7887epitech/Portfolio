/*
** EPITECH PROJECT, 2024
** new_file.c
** File description:
** that files should init the new canva
*/
#include "my_project.h"
static void free_old_canva(layer_t *layer)
{
    layer_t *new = NULL;

    while (layer) {
        new = layer->next;
        sfSprite_destroy(layer->screen_sprite);
        sfTexture_destroy(layer->texture);
        free(layer->uint_tab);
        free(layer);
        layer = new;
    }
    if (new)
        free(new);
}

void new_file(canva_t *canva, int wi, int hei)
{
    int size = canva->tools_size;
    sfColor color = canva->tool_color;

    free_old_canva(canva->layer);
    init_canva_el(canva, wi, hei, (sfVector2f){1740, 500});
    sfSprite_setOrigin(canva->layer->screen_sprite,
        (sfVector2f){wi / 2, hei / 2});
    sfSprite_setPosition(canva->layer->screen_sprite,
        (sfVector2f){890, 1080 / 2});
    sfTexture_updateFromPixels(canva->layer->texture, canva->layer->uint_tab,
        wi, hei, 0, 0);
    sfSprite_setScale(canva->layer->screen_sprite, canva->scale);
    sfSprite_setTexture(canva->layer->screen_sprite,
        canva->layer->texture, sfTrue);
    canva->sprite_rect = sfSprite_getGlobalBounds(canva->layer->screen_sprite);
    canva->tools_size = size;
    canva->tool_color = color;
}
