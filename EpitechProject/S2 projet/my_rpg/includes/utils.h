/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** utils
*/

#pragma once

#include <SFML/Graphics.h>
#include "npc.h"

typedef struct off_set_s {
    int x;
    int y;
} off_set_t;

sfVector2f vector_edition(sfVector2f pos, int x, int y);
void my_move_rect(sfIntRect *rect, int offset, int max_value, int *direction);
void create_texture(sfSprite *sprite, sfTexture *texture, sfIntRect *rect);

bool init_frame(sprite_object_t *frame);
bool init_quest_frame(sprite_object_t *frame);
bool init_health_bar(sprite_object_t *health_bar);
