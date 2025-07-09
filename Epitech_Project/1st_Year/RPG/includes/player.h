/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.h>
#include "game_types.h"
#include "inventory.h"

typedef enum room_state_s {
    MAP,
    SCHOOL,
    WITCH,
    DUNGEON
} room_state_t;

typedef enum {
    IDLE,
    ATTACKING
} player_state_t;

typedef enum {
    NOP,
    WALKING,
} player_move_t;

typedef struct player_view {
    sfView *view;
} player_view_t;

typedef struct player_texture {
    sfTexture *texture1;
    sfTexture *slash_tx;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f origin;
    sfVector2f scale;
    sfVector2f position;
    player_state_t state;
    player_move_t move_state;
    room_state_t room;
    sfIntRect attack_rect;
    sfVector2f attack_origin;
    sfVector2f attack_scale;
} player_texture_t;

typedef struct player_s {
    int health;
    int attack;
    int defense;
    int level;
    int exp;
    inventory_t *inventory;
    player_view_t p_view;
    player_texture_t p_sprite;
    sfRectangleShape* player_hitbox;
} player_t;
