/*
** EPITECH PROJECT, 2024
** our_layer.c
** File description:
** that function should init the layers
*/
#include "my_project.h"

static int nb_layer(layer_t *layer)
{
    int count = 0;

    while (layer) {
        layer = layer->next;
        count++;
    }
    return count;
}

static void reverse_list(layer_t **list)
{
    layer_t *prev = NULL;
    layer_t *next = NULL;
    layer_t *current = *list;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

layer_t *init_layer(canva_t *canva, sfVector2f pos_button_layer)
{
    layer_t *layer = malloc(sizeof(layer_t));
    int windows_size = canva->height * canva->width * 4;
    sfVector2f pos = sfSprite_getPosition(canva->layer->screen_sprite);

    layer->texture = sfTexture_create(canva->width, canva->height);
    layer->screen_sprite = sfSprite_create();
    layer->button = init_canva_but(pos_button_layer);
    sfRectangleShape_setFillColor(layer->button[0]->rect,
        (sfColor){74, 77, 81, 255});
    layer->uint_tab = malloc(sizeof(sfUint8) * windows_size);
    for (int i = 0; i < windows_size; i++)
        layer->uint_tab[i] = 0;
    sfSprite_setOrigin(layer->screen_sprite,
        (sfVector2f){canva->width / 2, canva->height / 2});
    sfSprite_setPosition(layer->screen_sprite, pos);
    sfTexture_updateFromPixels(layer->texture, layer->uint_tab,
        canva->width, canva->height, 0, 0);
    sfSprite_setScale(layer->screen_sprite, canva->scale);
    return layer;
}

void reset_actif_layer(canva_t *canva, layer_t *actual_layer)
{
    layer_t *layer = canva->layer;

    while (layer) {
        sfRectangleShape_setFillColor(layer->button[0]->rect,
            (sfColor){74, 77, 81, 255});
        layer->is_active = sfFalse;
        layer = layer->next;
    }
    sfRectangleShape_setFillColor(actual_layer->button[0]->rect,
        (sfColor){100, 100, 100, 100});
    actual_layer->is_active = sfTrue;
}

void set_visible_layer_state(layer_t *layer)
{
    if (layer->is_visible == sfTrue) {
        sfRectangleShape_setFillColor(layer->button[1]->rect, sfBlack);
        layer->is_visible = sfFalse;
    } else {
        sfRectangleShape_setFillColor(layer->button[1]->rect, sfWhite);
        layer->is_visible = sfTrue;
    }
}

void add_layer(canva_t **canva)
{
    int layer_nb = nb_layer((*canva)->layer);
    sfVector2f pos;
    layer_t *new = NULL;

    if (layer_nb >= 10)
        return;
    pos = sfRectangleShape_getPosition((*canva)->layer->button[0]->rect);
    pos.y += 30 * layer_nb;
    new = init_layer(*canva, pos);
    sfSprite_setTexture(new->screen_sprite, new->texture, sfTrue);
    new->next = NULL;
    new->is_active = sfFalse;
    new->is_visible = sfTrue;
    reverse_list(&(*canva)->layer);
    new->next = (*canva)->layer;
    (*canva)->layer = new;
    reverse_list(&(*canva)->layer);
}

void delete_layer(win_t *win, canva_t *canva, button_t *butt)
{
    if (is_button_pressed(win->event, butt->dellayer)) {
        free_node(&canva->layer);
        reset_actif_layer(canva, canva->layer);
    }
    return;
}
