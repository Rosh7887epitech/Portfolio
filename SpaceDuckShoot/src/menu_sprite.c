/*
** EPITECH PROJECT, 2023
** sprite menu
** File description:
** menu
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int button_reset(stat *button_reset)
{
    button_reset->texture =
    sfTexture_createFromFile("content/restart_button.png", NULL);
    button_reset->sprite = sfSprite_create();
    button_reset->origin.x = 0;
    button_reset->origin.y = 0;
    button_reset->pos.x = 750;
    button_reset->pos.y = 700;
    button_reset->scale.x = 0.4;
    button_reset->scale.y = 0.4;
    button_reset->rect.height = 500;
    button_reset->rect.top = 0;
    button_reset->rect.left = 0;
    button_reset->rect.width = 1000;
    sfSprite_setOrigin(button_reset->sprite, button_reset->origin);
    sfSprite_setScale(button_reset->sprite, button_reset->scale);
    sfSprite_setPosition(button_reset->sprite, button_reset->pos);
    sfSprite_setTexture(button_reset->sprite, button_reset->texture, sfTrue);
    sfSprite_setTextureRect(button_reset->sprite, button_reset->rect);
}

int back_menu_init(stat *menu_background)
{
    menu_background->texture =
    sfTexture_createFromFile("content/back_menu.png", NULL);
    menu_background->sprite = sfSprite_create();
    menu_background->scale.x = 1;
    menu_background->scale.y = 1;
    sfSprite_setScale(menu_background->sprite,
    menu_background->scale);
    sfSprite_setTexture(menu_background->sprite,
    menu_background->texture, sfTrue);
}

int button_init_exit(stat *button_exit)
{
    button_exit->texture =
    sfTexture_createFromFile("content/exit_button.png", NULL);
    button_exit->sprite = sfSprite_create();
    button_exit->origin.x = 0;
    button_exit->origin.y = 0;
    button_exit->pos.x = 20;
    button_exit->pos.y = 540;
    button_exit->scale.x = 0.4;
    button_exit->scale.y = 0.4;
    button_exit->rect.height = 1;
    button_exit->rect.top = 1;
    button_exit->rect.left = 1;
    button_exit->rect.width = 1;
    sfSprite_setOrigin(button_exit->sprite, button_exit->origin);
    sfSprite_setScale(button_exit->sprite, button_exit->scale);
    sfSprite_setPosition(button_exit->sprite, button_exit->pos);
    sfSprite_setTexture(button_exit->sprite, button_exit->texture, sfTrue);
}

int button_init_set(stat *button_setting)
{
    button_setting->texture =
    sfTexture_createFromFile("content/setting_button.png", NULL);
    button_setting->sprite = sfSprite_create();
    button_setting->origin.x = 0;
    button_setting->origin.y = 0;
    button_setting->pos.x = 20;
    button_setting->pos.y = 300;
    button_setting->scale.x = 0.4;
    button_setting->scale.y = 0.4;
    button_setting->rect.height = 1;
    button_setting->rect.top = 1;
    button_setting->rect.left = 1;
    button_setting->rect.width = 1;
    sfSprite_setOrigin(button_setting->sprite, button_setting->origin);
    sfSprite_setScale(button_setting->sprite, button_setting->scale);
    sfSprite_setPosition(button_setting->sprite, button_setting->pos);
    sfSprite_setTexture(button_setting->sprite, button_setting->texture,
    sfTrue);
}

int button_init(stat *button_start)
{
    button_start->texture =
    sfTexture_createFromFile("content/start_button.png", NULL);
    button_start->sprite = sfSprite_create();
    button_start->origin.x = 0;
    button_start->origin.y = 0;
    button_start->pos.x = 20;
    button_start->pos.y = 60;
    button_start->scale.x = 0.4;
    button_start->scale.y = 0.4;
    button_start->rect.height = 1;
    button_start->rect.top = 1;
    button_start->rect.left = 1;
    button_start->rect.width = 1;
    sfSprite_setOrigin(button_start->sprite, button_start->origin);
    sfSprite_setScale(button_start->sprite, button_start->scale);
    sfSprite_setPosition(button_start->sprite, button_start->pos);
    sfSprite_setTexture(button_start->sprite, button_start->texture, sfTrue);
}
