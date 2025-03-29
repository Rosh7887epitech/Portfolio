/*
** EPITECH PROJECT, 2023
** add_circle_st
** File description:
** add circle_st for link circle_st
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

tower_st *tower_node_creator(tower_st *shape, sfCircleShape *rond)
{
    tower_st *node = malloc(sizeof(tower_st));
    sfVector2f pos = sfCircleShape_getPosition(rond);

    node->bol = 0;
    node->c = rond;
    node->t = tower(pos.x, pos.y);
    node->next = NULL;
    return node;
}

void add_tower_st(tower_st **shape, sfCircleShape *rond, int pos)
{
    tower_st *node = tower_node_creator(*shape, rond);
    tower_st *current = *shape;

    if (!node) {
        return;
    }
    if (*shape == NULL || pos == 0) {
        node->next = *shape;
        *shape = node;
    }
}

circle_st *node_creator(circle_st *shape, sfCircleShape *rond)
{
    circle_st *node = malloc(sizeof(circle_st));
    sfVector2f pos = sfCircleShape_getPosition(rond);

    node->bol = 0;
    node->boul = 0;
    node->c = rond;
    node->s = square_init(pos.x, pos.y);
    node->p = plane(pos.x, pos.y);
    node->next = NULL;
    return node;
}

void add_circle_st(circle_st **shape, sfCircleShape *rond, int pos)
{
    circle_st *node = node_creator(*shape, rond);

    if (!node) {
        return;
    }
    if (*shape == NULL || pos == 0) {
        node->next = *shape;
        *shape = node;
    }
}
