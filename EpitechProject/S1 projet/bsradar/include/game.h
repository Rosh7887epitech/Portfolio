/*
** EPITECH PROJECT, 2023
** gmae
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "include.h"
    #include "my.h"

typedef struct sprite_stat {

    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    sfIntRect rect;
    sfTime time;
    float speed;
    float stock_time;
    float radius;
    float thickness;


} stat;

typedef struct base {

    sfRenderWindow *window;
    stat background;
    stat ship;
    stat zone;
    int nb_c;
    sfClock *clock_ship;
    sfMusic *music;
    sfCircleShape *circle;

} base_st;

typedef struct circle {

    sfCircleShape *c;
    struct circle *next;

} circle_st;

void close_window(base_st *var, sfEvent event);
void game_init(base_st *var, circle_st **shape);
int circle_init(base_st *var, circle_st **shape, float x, float y);
int is_intersecting_circles(circle_st *shape);
void add_circle_st(circle_st **shape, sfCircleShape *rond, int pos);
void move_circle(circle_st *shape, base_st *var);
void draw_circle(circle_st *shape, base_st *var);
void verif_collision(circle_st *shape);


#endif /* !game */
