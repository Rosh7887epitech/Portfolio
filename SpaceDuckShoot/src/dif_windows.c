/*
** EPITECH PROJECT, 2023
** windows
** File description:
** windows
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void run_game(base_st *var)
{
    if (var->bool == 1) {
        move_sprite(var);
        draw_sprite(var);
        sfRenderWindow_setMouseCursorVisible(var->window, sfFalse);
    }
}

void run_menu(base_st *var)
{
    if (var->bool == 0) {
        draw_sprite_menu(var);
    }
}

void run_end(base_st *var)
{
    if (var->bool == 2) {
        draw_sprite_end(var);
        sfRenderWindow_setMouseCursorVisible(var->window, sfTrue);
    }
}

int aim_init(stat *aim, base_st *var)
{
    aim->texture = sfTexture_createFromFile("content/aim.png", NULL);
    aim->sprite = sfSprite_create();
    aim->pos.x = sfMouse_getPositionRenderWindow(var->window).x;
    aim->pos.y = sfMouse_getPositionRenderWindow(var->window).y;
    aim->scale.x = 0.5;
    aim->scale.y = 0.5;
    aim->rect.height = 200;
    aim->rect.top = 0;
    aim->rect.left = 0;
    aim->rect.width = 200;
    aim->origin.x = 100;
    aim->origin.y = 100;
    sfSprite_setOrigin(aim->sprite, aim->origin);
    sfSprite_setScale(aim->sprite, aim->scale);
    sfSprite_setPosition(aim->sprite, aim->pos);
    sfSprite_setTexture(aim->sprite, aim->texture, sfTrue);
    sfSprite_setTextureRect(aim->sprite, aim->rect);
}
