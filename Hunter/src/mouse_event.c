/*
** EPITECH PROJECT, 2023
** mouse
** File description:
** mouse
*/

#include "../include/include.h"
#include "../include/game.h"
#include "../include/my.h"

void mouse_pos(base_st *var, sfEvent event)
{
    if (sfMouse_getPosition(sfMouseLeft).x >= var->ship.pos.x - 105 &&
            sfMouse_getPosition(sfMouseLeft).x <= var->ship.pos.x + 110 &&
            sfMouse_getPosition(sfMouseLeft).y <= var->ship.pos.y + 65 &&
            sfMouse_getPosition(sfMouseLeft).y >= var->ship.pos.y - 100) {
            var->ship.pos.x = -150;
            var->ship.pos.y = rand() % (700 - 100) + 100;
            var->score += 15;
            var->ship.speed = var->ship.speed * 1.04;
            sfSprite_setTextureRect(var->ship.sprite, var->ship.rect);
        }
    if (sfMouse_getPosition(sfMouseLeft).x >= var->button_start.pos.x &&
        sfMouse_getPosition(sfMouseLeft).x <= var->button_start.pos.x +
        798 &&
        sfMouse_getPosition(sfMouseLeft).y <= var->button_start.pos.y +
        230 &&
        sfMouse_getPosition(sfMouseLeft).y >= var->button_start.pos.y) {
        var->bool = 1;
    }
}

void mouse_event(base_st *var, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        sfMusic_play(var->shoot);
        mouse_pos(var, event);
    }
}
