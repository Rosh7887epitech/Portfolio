/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy
*/

#pragma once

#include "game_types.h"

typedef struct enemy_s {
    enemy_type_t type;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f origin;
    sfIntRect rect;
    int health;
    int damage;
} enemy_t;

typedef struct {
    enemy_t bat;
    enemy_t slime;
    enemy_t goblin;
    enemy_t boss;
} enemies_t;
