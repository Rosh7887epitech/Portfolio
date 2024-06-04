/*
** EPITECH PROJECT, 2023
** draw
** File description:
** draw
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void move_cond(circle_st *shape, base_st *var, move_t *traj)
{
    if (traj->road <= traj->total) {
        traj->ratio = (traj->road / traj->total);
        traj->newx = ((shape->p_init.endx -
            shape->p_init.startx) * traj->ratio) + shape->p_init.startx;
        traj->newy = ((shape->p_init.endy -
            shape->p_init.starty) * traj->ratio) + shape->p_init.starty;
        sfCircleShape_setPosition(shape->c,
            (sfVector2f){traj->newx, traj->newy});
        sfRectangleShape_setPosition(shape->s,
            (sfVector2f){traj->newx, traj->newy});
        sfSprite_setPosition(shape->p, (sfVector2f){traj->newx, traj->newy});
    } else {
        shape->bol = -1;
    }
}

void move_loop(circle_st *shape, base_st *var, move_t *traj)
{
    while (shape != NULL) {
        if ((shape->bol == 0 || shape->bol == 1) &&
            var->ship.stock_time >= shape->p_init.delai) {
            shape->bol = 1;
            traj->road = (shape->p_init.speed *
                (var->ship.stock_time - shape->p_init.delai));
            traj->total = (sqrt(pow(shape->p_init.endx -
                shape->p_init.startx, 2) + pow(shape->p_init.endy -
                shape->p_init.starty, 2)));
            move_cond(shape, var, traj);
            traj->ratio = 0.0;
            traj->road = 0.0;
            traj->total = 0.0;
        }
        shape = shape->next;
    }
}

void move_circle(circle_st *shape, base_st *var)
{
    move_t *traj = malloc(sizeof(move_t));

    traj->newx = 0;
    traj->newy = 0;
    traj->ratio = 0.0;
    traj->road = 0.0;
    traj->total = 0.0;
    var->ship.time = sfClock_getElapsedTime(var->temps);
    var->ship.stock_time = var->ship.time.microseconds / 1000000.0;
    move_loop(shape, var, traj);
    return;
}

void cond_draw(base_st *var, circle_st *tmp)
{
    if (tmp->bol == 1) {
        if (var->s_touch == 0)
            sfRenderWindow_drawSprite(var->window, tmp->p, NULL);
        if (var->l_touch == 0) {
            sfRenderWindow_drawRectangleShape(var->window, tmp->s, NULL);
            sfRenderWindow_drawCircleShape(var->window, tmp->c, NULL);
        }
        sfCircleShape_setFillColor(tmp->c, sfTransparent);
    }
}

void draw_circle(circle_st **shape, tower_st *tow, base_st *var)
{
    circle_st *tmp = *shape;
    tower_st *wait = tow;

    while (wait != NULL) {
        if (var->s_touch == 0)
            sfRenderWindow_drawSprite(var->window, wait->t, NULL);
        if (var->l_touch == 0)
            sfRenderWindow_drawCircleShape(var->window, wait->c, NULL);
        sfCircleShape_setFillColor(wait->c, sfTransparent);
        wait = wait->next;
    }
    while (tmp != NULL) {
        cond_draw(var, tmp);
        tmp = tmp->next;
    move_circle(*shape, var);
    }
    return;
}
