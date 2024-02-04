/*
** EPITECH PROJECT, 2023
** movr
** File description:
** move
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void move_sprite(base_st *var)
{
    move_ship(var);
}

void move_ship(base_st *var)
{
    if (var->clock_ship == NULL)
        return;
    var->ship.time = sfClock_getElapsedTime(var->clock_ship);
    var->ship.stock_time = var->ship.time.microseconds / 1000000.0;
    if (var->ship.stock_time > 0.02) {
        var->ship.rect.left += 517;
        var->ship.pos.x += var->ship.speed;
        sfSprite_setPosition(var->ship.sprite, var->ship.pos);
        sfSprite_setTextureRect(var->ship.sprite, var->ship.rect);
        sfClock_restart(var->clock_ship);
    }
    pos_ship(var);
    if (var->ship.rect.left >= 1030) {
        var->ship.rect.left = 0;
        sfSprite_setTextureRect(var->ship.sprite, var->ship.rect);
    }
}

void pos_ship(base_st *var)
{
    if (var->ship.pos.x >= 1920) {
        var->ship.pos.x = -100;
        var->ship.pos.y = rand() % 880 + 50;
        var->ship.speed = var->ship.speed * 1.016;
        var->life.rect.left += 500;
        sfSprite_setTextureRect(var->life.sprite, var->life.rect);
        sfSprite_setTextureRect(var->ship.sprite, var->ship.rect);
    }
}
