/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** musics
*/

#pragma once

#include <SFML/Audio.h>

enum music_state_e {
    ON,
    OFF
};

typedef struct music_s {
    enum music_state_e music_state;
    sfMusic *music;
    sfMusic *slash;
    sfMusic *walk;
} music_t;
