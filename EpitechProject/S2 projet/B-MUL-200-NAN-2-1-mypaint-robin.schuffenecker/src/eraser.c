/*
** EPITECH PROJECT, 2024
** eraser.c
** File description:
** that function should make the eraser
*/
#include "my_project.h"

void our_eraser(win_t *win, canva_t *canva)
{
    layer_t *layer = canva->layer;
    int count = 0;
    sfColor tmp_color = canva->tool_color;

    while (layer && layer->is_active != sfTrue) {
        count++;
        layer = layer->next;
    }
    if (layer == NULL)
        return;
    if (count == 0)
        canva->tool_color = sfWhite;
    else
        canva->tool_color = (sfColor) {0, 0, 0, 0};
    modify_sfuint8(win, canva);
    canva->tool_color = tmp_color;
}
