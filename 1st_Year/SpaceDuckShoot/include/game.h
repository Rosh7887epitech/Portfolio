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
    float speed_two;
    float stock_time;


} stat;

typedef struct base {

    sfRenderWindow *window;
    stat background;
    stat background_end;
    stat menu_background;
    stat ship;
    stat ship_two;
    stat button_start;
    stat button_setting;
    stat button_exit;
    stat button_reset;
    stat aim;
    stat life;
    stat level;
    stat score_l;
    int score;
    int bool;
    sfText *text;
    char *str;
    sfClock *clock_ship;
    sfMusic *music;
    sfMusic *shoot;
    char *score_s;

} base_st;


void close_window(base_st *var, sfEvent event);
void mouse_event(base_st *var, sfEvent event);
int ship_init(stat *ship);
int button_init(stat *button_start);
int back_init(stat *background);
int sprite_init(base_st *var);
void music_init(base_st *var);
void move_sprite(base_st *var);
void move_ship(base_st *var);
void run_game(base_st *var);
void run_menu(base_st *var);
void move_sprite_menu(base_st *var);
int button_init_set(stat *button_setting);
int button_init_exit(stat *button_exit);
int back_menu_init(stat *menu_background);
int life_init(stat *life);
void end_game(base_st *var);
int aim_init(stat *aim, base_st *var);
void run_game(base_st *var);
void run_menu(base_st *var);
void draw_sprite(base_st *var);
void draw_sprite_menu(base_st *var);
void move_sprite_lvltwo(base_st *var);
void move_ship_two(base_st *var);
void run_game_lvltwo(base_st *var);
void draw_sprite_lvltwo(base_st *var);
void run_lvlmenu(base_st *var);
void draw_sprite_lvlmenu(base_st *var);
int shiptwo_init(stat *ship);
void pos_ship(base_st *var);
void draw_sprite_end(base_st *var);
void run_end(base_st *var);
int end_sprite(stat *background_end);
int button_reset(stat *button_reset);
char *my_itoa(int score);
void display_txt(base_st *var);
void destroy_sprite(base_st *var);
void destroy_texture(base_st *var);

#endif /* !game */
