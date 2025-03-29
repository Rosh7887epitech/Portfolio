/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void destroy_texture(base_st *var)
{
    sfTexture_destroy(var->aim.texture);
    sfTexture_destroy(var->background.texture);
    sfTexture_destroy(var->background_end.texture);
    sfTexture_destroy(var->menu_background.texture);
    sfTexture_destroy(var->ship.texture);
    sfTexture_destroy(var->button_exit.texture);
    sfTexture_destroy(var->button_reset.texture);
    sfTexture_destroy(var->button_setting.texture);
    sfTexture_destroy(var->button_start.texture);
    sfTexture_destroy(var->life.texture);
}

void destroy_sprite(base_st *var)
{
    sfClock_destroy(var->clock_ship);
    sfSprite_destroy(var->aim.sprite);
    sfSprite_destroy(var->background.sprite);
    sfSprite_destroy(var->background_end.sprite);
    sfSprite_destroy(var->menu_background.sprite);
    sfSprite_destroy(var->ship.sprite);
    sfSprite_destroy(var->button_exit.sprite);
    sfSprite_destroy(var->button_reset.sprite);
    sfSprite_destroy(var->button_setting.sprite);
    sfSprite_destroy(var->button_start.sprite);
    sfSprite_destroy(var->life.sprite);
    sfMusic_destroy(var->music);
    sfMusic_destroy(var->shoot);
    sfRenderWindow_destroy(var->window);
}
