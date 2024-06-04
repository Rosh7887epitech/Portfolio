/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** rpg
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "player.h"
#include "enemy.h"
#include "game_render.h"
#include "game_types.h"
#include "item.h"
#include "my_json.h"
#include "inventory.h"
#include "npc.h"

#define HEALTH_BAR_PATH "assets/images/all/health-bar.png"

typedef struct node_npc_s node_npc_t;

typedef enum {
    PRINT,
    NO
} minimap_state_t;

typedef struct minimap_s {
    sfSprite *map;
    sfCircleShape *dot;
    minimap_state_t state;
} minimap_t;

typedef struct room_s {
    sfSprite *back;
    sfSprite *bar;
    sfSprite *shop;
    sfSprite *school;
    sfSprite *dungeon;
    sfSprite *col2;
    sfSprite *start_anim;
} room_t;

typedef struct {
    char *window_name;
    sfRenderWindow *window;
    bool should_close;
    sfSprite *back;
    sfSprite *couche;
    sfImage *col;
    sfImage *col2;
    sfSprite *colision;
    room_t room;
} window_node_t;

typedef struct game_s {
    menu_t menu;
    bool touch;
    player_t player;
    minimap_t minimap;
    enemies_t enemies;
    game_state_t state;
    window_node_t window;
    item_node_t *node_items;
    sfClock *clock;
    node_npc_t *n_npc;
    inventory_t inventory;
    sprite_object_t frame;
    sprite_object_t quest_frame;
    sprite_object_t health_bar;
    music_t music;
} game_t;

// init.c
/// @brief init game
/// @param game
/// @return bool
bool initialize_game(game_t *game);
void init_room(window_node_t *win);
bool init_player(player_t *player);
bool init_player_hitbox(player_t *player);
bool init_player_sprite(player_t *player);
bool init_enemy_sprite(enemy_t *enemies, char *filepath, sfVector2f pos);
bool init_sound_effect(music_t *music);

// game_loop.c

/// @brief game loop
/// @param game
void game_loop(game_t *game);


// shutdown.c

void shutdown_game(game_t *game);

// window.c

void close_window_event(sfEvent event, window_node_t *current);
sfRenderWindow *create_window(char *title, sfVideoMode mode);

// events.c

void handle_events(game_t *rpg);

// json.c

json_value_t *json_file(char *file);

// game_view.c

bool init_player_view(player_view_t *view);

// player_controller.c

void player_action(sfEvent event, game_t *rpg);
void player_attack(sfEvent event, game_t *rpg);
void update_attack_animation(player_t *player, sfClock *clock);
void init_attack_rect(player_t *player);
void attack_enemy(game_t *rpg);
void move_condition(sfEvent event, game_t *rpg);
void draw_school(const game_t *game);

// my_rpg.c

int my_rpg(int ac, char *param1);

// menu_controller.c

sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *event);
sfBool is_button_hovered(button_t *button, sfMouseMoveEvent *event);
sfBool is_button_released(button_t *button, sfMouseButtonEvent *event);
sfBool is_button_pressed(button_t *button, sfMouseButtonEvent *event);

// create_button.c

button_t *create_buttons(char *filepath);
button_t *init_button(sfColor color, char *filepath);
sfRectangleShape *init_rectshape(sfColor col, char *filepath);

// collision.c

int verif_collision(window_node_t *window, player_t *player);
int side_collision(window_node_t *window, player_t *player);
bool compare_pos(sfVector2f pos1, sfVector2f pos2);
bool compare_pos_enemy(sfVector2f pos1, sfVector2f pos2);

// room_door.c

void check_door(game_t *game);

// minimap.c

void init_minimap(minimap_t *mini, player_t *player);
void draw_minimap(const game_t *game);
void update_state_minimap(game_t *game, sfEvent event, minimap_t *mini);

/// @brief init rect
/// @param int top
/// @param int left
/// @param int width
/// @param int height
/// @return sfIntRect
sfIntRect init_rect(int top, int left, int width, int height);


void browse_and_fill_npc(game_t *game);
