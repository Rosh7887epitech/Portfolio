/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** sprite
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int sprite_init(base_st *var)
{
    back_init(&var->background);
    ship_init(&var->ship);
    button_init(&var->button_start);
    button_init_set(&var->button_setting);
    button_init_exit(&var->button_exit);
    back_menu_init(&var->menu_background);
    life_init(&var->life);
    end_sprite(&var->background_end);
    button_reset(&var->button_reset);
}

int ship_init(stat *ship)
{
    ship->texture = sfTexture_createFromFile("content/chip.png", NULL);
    ship->sprite = sfSprite_create();
    ship->pos.x = -150;
    ship->pos.y = 200;
    ship->scale.x = 0.4;
    ship->scale.y = 0.4;
    ship->rect.height = 350;
    ship->rect.top = 0;
    ship->rect.left = 0;
    ship->rect.width = 512;
    ship->origin.x = 256;
    ship->origin.y = 256;
    sfSprite_setOrigin(ship->sprite, ship->origin);
    sfSprite_setScale(ship->sprite, ship->scale);
    sfSprite_setPosition(ship->sprite, ship->pos);
    sfSprite_setTexture(ship->sprite, ship->texture, sfTrue);
    sfSprite_setTextureRect(ship->sprite, ship->rect);
}

int life_init(stat *life)
{
    life->texture = sfTexture_createFromFile("content/life.png", NULL);
    life->sprite = sfSprite_create();
    life->pos.x = 1770;
    life->pos.y = 15;
    life->scale.x = 0.3;
    life->scale.y = 0.3;
    life->rect.height = 239;
    life->rect.top = 0;
    life->rect.left = 0;
    life->rect.width = 500;
    life->origin.x = 0;
    life->origin.y = 0;
    sfSprite_setOrigin(life->sprite, life->origin);
    sfSprite_setScale(life->sprite, life->scale);
    sfSprite_setPosition(life->sprite, life->pos);
    sfSprite_setTexture(life->sprite, life->texture, sfTrue);
    sfSprite_setTextureRect(life->sprite, life->rect);
}

int back_init(stat *background)
{
    background->texture = sfTexture_createFromFile("content/back1.jpg", NULL);
    background->sprite = sfSprite_create();
    background->scale.x = 1;
    background->scale.y = 1;
    sfSprite_setScale(background->sprite, background->scale);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
}

int end_sprite(stat *background_end)
{
    background_end->texture = sfTexture_createFromFile("content/end_back.png",
    NULL);
    background_end->sprite = sfSprite_create();
    background_end->scale.x = 1;
    background_end->scale.y = 1;
    sfSprite_setScale(background_end->sprite, background_end->scale);
    sfSprite_setTexture(background_end->sprite, background_end->texture,
    sfTrue);
}
