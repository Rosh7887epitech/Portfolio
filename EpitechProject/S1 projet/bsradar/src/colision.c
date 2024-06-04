/*
** EPITECH PROJECT, 2023
** is_intersecting_circles
** File description:
** touch or not
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int is_intersecting_circles(circle_st *shape)
{
    int cx = 0;
    int cy = 0;
    int dx = 0;
    int dy = 0;
    int cr = 0;
    int dr = 0;
    circle_st *start = shape;
    circle_st *comp = shape;

    while (start != NULL) {
        cx = sfCircleShape_getPosition(start->c).x;
        cy = sfCircleShape_getPosition(start->c).y;
        cr = sfCircleShape_getRadius(start->c);
        while (comp != NULL) {
            dx = sfCircleShape_getPosition(comp->c).x;
            dy = sfCircleShape_getPosition(comp->c).y;
            dr = sfCircleShape_getRadius(comp->c);
            if ((pow((cx - dx), 2)) + (pow((cy - dy), 2)) <= (pow((cr + dr), 2))) {
                return 1;
            } else {
                return 0;
            }
            comp = comp->next;
        }
        start = start->next;
    }
}

void verif_collision(circle_st *shape)
{
    int r = 0;

    r = is_intersecting_circles(shape);
    if (r == 1) {
        sfCircleShape_setFillColor(shape->c, sfWhite);
    } else {
        sfCircleShape_setFillColor(shape->c, sfTransparent);
    }
}
