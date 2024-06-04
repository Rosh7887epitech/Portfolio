/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_settings_menu
*/

#include <stdlib.h>
#include "rpg.h"

static bool init_exit_setting_button(button_t **setting_exit)
{
    char *filepath = "assets/images/buttons/menu_buttons_exit.png";

    *setting_exit = create_buttons(filepath);
    return true;
}

static bool init_on_off_vol_button(button_t **volume)
{
    char *filepath = "assets/images/buttons/menu_buttons_volume.png";

    *volume = create_buttons(filepath);
    return true;
}

static bool init_setting_help_button(button_t **setting_help)
{
    char *filepath = "assets/images/buttons/menu_buttons_setting_help.png";

    *setting_help = create_buttons(filepath);
    return true;
}

bool init_settings_menu_sets(settings_menu_page_t *set)
{
    set->texture =
        sfTexture_createFromFile("assets/images/menu_bg.png", NULL);
    set->sprite = sfSprite_create();
    set->rect = (sfIntRect){0, 0, 1920, 1080};
    set->position = (sfVector2f){960, 540};
    set->scale = (sfVector2f){6, 6};
    set->origin = (sfVector2f){48, 48};
    sfSprite_setTexture(set->sprite, set->texture, sfTrue);
    sfSprite_setTextureRect(set->sprite, set->rect);
    sfSprite_setPosition(set->sprite, set->position);
    sfSprite_setScale(set->sprite, set->scale);
    sfSprite_setOrigin(set->sprite, set->origin);
    return true;
}

bool init_settings_buttons(settings_buttons_t *button)
{
    bool (*init_funcs[])(void *) = {
        (bool (*)(void *))init_exit_setting_button,
        (bool (*)(void *))init_on_off_vol_button,
        (bool (*)(void *))init_setting_help_button,
    };
    void *params[] = {
        &button->setting_exit, &button->volume, &button->setting_help
    };
    int num_init_funcs = sizeof(init_funcs) / sizeof(*init_funcs);

    for (int i = 0; i < num_init_funcs; i++)
        if (!init_funcs[i](params[i]))
            return false;
    return true;
}
