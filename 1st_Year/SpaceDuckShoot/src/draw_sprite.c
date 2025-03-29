/*
** EPITECH PROJECT, 2023
** draw
** File description:
** draw
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void draw_sprite(base_st *var)
{
    sfRenderWindow_drawSprite(var->window, var->background.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->life.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->ship.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->aim.sprite, NULL);
}

void draw_sprite_menu(base_st *var)
{
    sfRenderWindow_drawSprite(var->window, var->menu_background.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->button_start.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->button_setting.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->button_exit.sprite, NULL);
}

void draw_sprite_end(base_st *var)
{
    sfRenderWindow_drawSprite(var->window, var->background.sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->background_end.sprite, NULL);
}
