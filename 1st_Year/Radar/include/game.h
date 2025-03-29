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
    sfVector2f start;
    sfVector2f end;
    sfVector2f scale;
    sfVector2f origin;
    sfIntRect rect;
    sfTime time;
    float speed;
    float stock_time;
    float radius;
    float thickness;


} stat_st;


typedef struct file {

    char **map;
    int row;
    int col;

} file_t;

typedef struct move {

    int newx;
    int newy;
    float ratio;
    float road;
    float total;

} move_t;

typedef struct base {

    sfRenderWindow *window;
    stat_st background;
    stat_st ship;
    stat_st zone;
    int nb_c;
    int nb_t;
    char *buff;
    int l_touch;
    int s_touch;
    sfMusic *music;
    sfCircleShape *circle;
    sfRectangleShape *square;
    sfSprite *back;
    sfClock *temps;
    file_t path;

} base_st;

typedef struct start_tower {

    int nb_t;
    float posx;
    float posy;
    float radius;

} start_t;

typedef struct start_plane {

    int nb_c;
    float startx;
    float starty;
    float endx;
    float endy;
    float speed;
    float delai;

} start_p;

typedef struct tower {

    sfSprite *t;
    sfCircleShape *c;
    int bol;
    start_t t_init;
    struct tower *next;

} tower_st;


typedef struct circle {

    sfSprite *p;
    sfCircleShape *c;
    sfRectangleShape *s;
    int bol;
    int boul;
    start_p p_init;
    struct circle *next;

} circle_st;

typedef struct quad {

    circle_st *no;
    circle_st *ne;
    circle_st *so;
    circle_st *se;

} quad_st;

void close_window(base_st *var, circle_st *shape, sfEvent event);
int game_init(base_st *var, tower_st **tow, circle_st **shape,
    char const **argv);
int circle_init(base_st *var, circle_st **shape);
int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2);
void add_circle_st(circle_st **shape, sfCircleShape *rond, int pos);
void move_circle(circle_st *shape, base_st *var);
void draw_circle(circle_st **shape, tower_st *tow, base_st *var);
void verif_collision(circle_st *shape, base_st *var);
sfSprite *plane(float x, float y);
sfSprite *background(void);
sfSprite *tower(float x, float y);
int tower_circle_init(base_st *var, tower_st **tow);
void add_tower_st(tower_st **shape, sfCircleShape *rond, int pos);
sfRectangleShape *square_init(float x, float y);
int filereader(base_st *var, char const **argv);
int pos_search(base_st *var, circle_st **shape, tower_st **tow);
char *my_strdup(char *src);
int init_search(base_st *var, circle_st **shape, tower_st **tow);
char **load_2d_arr_from_file(char *buff, base_st *var);
int my_len(int index, const char *buff);
int length(const char *buff);
void plane_data(base_st *var, circle_st *current, int size, int *number);
void tower_data(base_st *var, tower_st *now, int size, int *number);
void move_cond(circle_st *shape, base_st *var, move_t *traj);
void move_loop(circle_st *shape, base_st *var, move_t *traj);
void game(base_st *var, tower_st *tow, circle_st *shape);
void timer(base_st *var);

#endif /* !game */
