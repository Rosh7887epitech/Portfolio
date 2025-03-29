/*
** EPITECH PROJECT, 2024
** pos
** File description:
** search
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

static int plane_search(base_st *var, int i, int p)
{
    for (int m = 0; m < var->path.col; m++) {
        if (var->path.map[i][m] == 'A')
            p++;
    }
    return p;
}

static int tower_search(base_st *var, int i, int t)
{
    for (int m = 0; m < var->path.col; m++) {
        if (var->path.map[i][m] == 'T')
            t++;
    }
    return t;
}

int init_search(base_st *var, circle_st **shape, tower_st **tow)
{
    int p = 0;
    int t = 0;

    for (int i = 0; i < var->path.row; i++) {
        p = plane_search(var, i, p);
        t = tower_search(var, i, t);
    }
    var->nb_c = p;
    var->nb_t = t;
    return 0;
}

void plane_data(base_st *var, circle_st *current, int size, int *number)
{
    for (int i = 0; i < var->path.row; i++) {
        if (var->path.map[i][0] == 'A') {
            number = my_getnbr(var->path.map[i], &size);
            current->p_init.startx = number[0];
            current->p_init.starty = number[1];
            current->p_init.endx = number[2];
            current->p_init.endy = number[3];
            current->p_init.speed = number[4];
            current->p_init.delai = number[5];
            var->zone.start.x = current->p_init.startx;
            var->zone.start.y = current->p_init.starty;
            var->zone.end.x = current->p_init.endx;
            var->zone.end.y = current->p_init.endy;
            sfCircleShape_setPosition(current->c, var->zone.start);
            current = current->next;
        }
    }
}

void tower_data(base_st *var, tower_st *now, int size, int *number)
{
    for (int i = 0; i < var->path.row; i++) {
        if (var->path.map[i][0] == 'T') {
            number = my_getnbr(var->path.map[i], &size);
            now->t_init.posx = number[0];
            now->t_init.posy = number[1];
            now->t_init.radius = number[2];
            var->zone.start.x = now->t_init.posx;
            var->zone.start.y = now->t_init.posy;
            sfCircleShape_setPosition(now->c,
                (sfVector2f){number[0] - number[2], number[1] - number[2]});
            sfSprite_setPosition(now->t,
                (sfVector2f){number[0] - (250.0 * 0.08),
                number[1] - (250.0 * 0.08)});
            sfCircleShape_setRadius(now->c, now->t_init.radius);
            now = now->next;
        }
    }
}

int pos_search(base_st *var, circle_st **shape, tower_st **tow)
{
    circle_st *current = (*shape);
    tower_st *now = (*tow);
    int size = 0;
    int *number;

    plane_data(var, current, size, number);
    tower_data(var, now, size, number);
    return 0;
}
