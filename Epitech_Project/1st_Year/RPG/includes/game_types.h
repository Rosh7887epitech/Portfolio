/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game_types
*/

#pragma once

typedef enum {
    GAME_RUNNING,
    GAME_PAUSED,
    GAME_MENU,
    GAME_OVER
} game_state_t;

typedef enum {
    ENEMY_GHOST,
    ENEMY_GOBLIN,
    ENEMY_DRAGON
} enemy_type_t;

typedef struct inventory_s inventory_t;
typedef struct player_s player_t;
typedef struct enemy_s enemy_t;
typedef struct menu_s menu_t;
typedef struct game_s game_t;
