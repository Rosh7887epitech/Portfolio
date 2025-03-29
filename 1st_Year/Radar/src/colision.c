/*
** EPITECH PROJECT, 2023
** is_intersecting_circles
** File description:
** touch or not
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
        float cx = sfCircleShape_getPosition(c1).x;
        float cy = sfCircleShape_getPosition(c1).y;
        float cr = sfCircleShape_getRadius(c1);
        float dx = sfCircleShape_getPosition(c2).x;
        float dy = sfCircleShape_getPosition(c2).y;
        float dr = sfCircleShape_getRadius(c2);

        if ((pow((cx - dx), 2)) + (pow((cy - dy), 2)) <= (pow((cr + dr), 2)))
            return 1;
        else
            return 0;
}

void verifloop(circle_st *dup, circle_st *start)
{
    int r = 0;

    while (dup != NULL) {
        r = is_intersecting_circles(start->c, dup->c);
        if (r == 1 && dup->bol == 1 && start->bol == 1 &&
            dup->boul == 0 && start->boul == 0) {
            dup->bol = 2;
            start->bol = 2;
        }
        dup = dup->next;
    }
    return;
}

void verif_collision(circle_st *shape, base_st *var)
{
    circle_st *start = shape;
    circle_st *dup = NULL;

    while (start != NULL) {
        dup = start->next;
        verifloop(dup, start);
        start = start->next;
    }
}
