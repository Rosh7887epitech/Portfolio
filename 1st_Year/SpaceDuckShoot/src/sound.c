/*
** EPITECH PROJECT, 2023
** sound
** File description:
** sound
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void music_init(base_st *var)
{
    sfMusic_play(var->music);
    sfMusic_setVolume(var->music, 35.0);
    sfMusic_setVolume(var->shoot, 100.0);
    sfMusic_setLoop(var->music, sfTrue);
}
