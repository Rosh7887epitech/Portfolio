/*
** EPITECH PROJECT, 2023
** add_circle_st
** File description:
** add circle_st for link circle_st
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

circle_st *node_creator(circle_st *shape, sfCircleShape *rond)
{
    circle_st *node = malloc(sizeof(circle_st));

    node->c = rond;
    node->next = NULL;
    return node;
}

void add_circle_st(circle_st **shape, sfCircleShape *rond, int pos)
{
    circle_st *node = node_creator(*shape, rond);
    circle_st *current = *shape;

    if (!node) {
        return;
    }
    if (*shape == NULL || pos == 0) {
        node->next = *shape;
        *shape = node;
    } else {
        for (int i = 0; i < pos - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}
