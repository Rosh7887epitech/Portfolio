/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_start_buttons
*/

#include <stdlib.h>
#include "rpg.h"

static bool init_exit_button(button_t **exit)
{
    char *filepath = "assets/images/buttons/menu_buttons_exit.png";

    *exit = create_buttons(filepath);
    return true;
}

static bool init_load_button(button_t **load)
{
    char *filepath = "assets/images/buttons/menu_buttons_load.png";

    *load = create_buttons(filepath);
    return true;
}

static bool init_settings_button(button_t **settings)
{
    char *filepath = "assets/images/buttons/menu_buttons_settings.png";

    *settings = create_buttons(filepath);
    return true;
}

static bool init_new_button(button_t **new)
{
    char *filepath = "assets/images/buttons/menu_buttons_new.png";

    *new = create_buttons(filepath);
    return true;
}

bool init_start_menu_sets(start_menu_page_t *settings)
{
    settings->texture =
        sfTexture_createFromFile("assets/images/bg_start_game1.png", NULL);
    settings->sprite = sfSprite_create();
    settings->rect = (sfIntRect){0, 0, 1920, 1080};
    settings->position = (sfVector2f){0, 0};
    settings->scale = (sfVector2f){1, 1};
    settings->origin = (sfVector2f){0, 0};
    sfSprite_setTexture(settings->sprite, settings->texture, sfTrue);
    sfSprite_setTextureRect(settings->sprite, settings->rect);
    sfSprite_setPosition(settings->sprite, settings->position);
    sfSprite_setScale(settings->sprite, settings->scale);
    sfSprite_setOrigin(settings->sprite, settings->origin);
    return true;
}

bool init_start_buttons(start_buttons_t *button)
{
    bool (*init_funcs[])(void *) = {
        (bool (*)(void *))init_exit_button, (bool (*)(void *))init_load_button,
        (bool (*)(void *))init_settings_button,
        (bool (*)(void *))init_new_button
    };
    void *params[] = {
        &button->exit, &button->load, &button->settings, &button->new_game,
    };
    int num_init_funcs = sizeof(init_funcs) / sizeof(*init_funcs);

    for (int i = 0; i < num_init_funcs; i++)
        if (!init_funcs[i](params[i]))
            return false;
    return true;
}
