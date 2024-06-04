/*
** EPITECH PROJECT, 2024
** free_node.c
** File description:
** that function should free a node
*/
#include "my_project.h"

static void replace_layer_button(layer_t *layer)
{
    sfVector2f pos;

    while (layer) {
        pos = sfRectangleShape_getPosition(layer->button[0]->rect);
        pos.y -= 30;
        sfRectangleShape_setPosition(layer->button[0]->rect, pos);
        pos.x += 150;
        sfRectangleShape_setPosition(layer->button[1]->rect, pos);
        layer = layer->next;
    }
}

static sfBool free_first_node(layer_t **list, int position, layer_t *temp)
{
    if (position == 0) {
        *list = temp->next;
        free(temp);
        replace_layer_button(*list);
        return sfTrue;
    }
    return sfFalse;
}

static int find_position_layer(layer_t *layer)
{
    int count = 0;

    while (layer) {
        if (layer->is_active == sfTrue)
            return count;
        count++;
        layer = layer->next;
    }
    return count;
}

void free_node(layer_t **list)
{
    layer_t *temp = NULL;
    layer_t *next = NULL;
    int position = find_position_layer(*list);

    if ((*list)->next == NULL)
        return;
    temp = *list;
    if (free_first_node(list, position, temp))
        return;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
    replace_layer_button(next);
}
