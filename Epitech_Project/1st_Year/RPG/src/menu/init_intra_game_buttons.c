/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_intra_game_buttons
*/

#include <stdlib.h>
#include "rpg.h"

static bool init_exit_game_button(button_t **exit_game)
{
    char *filepath = "assets/images/buttons/menu_buttons_exit.png";

    *exit_game = create_buttons(filepath);
    return true;
}

static bool init_resume_button(button_t **resume)
{
    char *filepath = "assets/images/buttons/menu_buttons_resume.png";

    *resume = create_buttons(filepath);
    return true;
}

static bool init_menu_button(button_t **menu)
{
    char *filepath = "assets/images/buttons/menu_buttons_menu.png";

    *menu = create_buttons(filepath);
    return true;
}

static bool init_settings_button(button_t **settings)
{
    char *filepath = "assets/images/buttons/menu_buttons_settings.png";

    *settings = create_buttons(filepath);
    return true;
}

static bool init_save_button(button_t **new)
{
    char *filepath = "assets/images/buttons/menu_buttons_save.png";

    *new = create_buttons(filepath);
    return true;
}

bool init_intra_menu_sets(intra_menu_page_t *sets)
{
    sets->texture =
        sfTexture_createFromFile("assets/images/menu_bg.png", NULL);
    sets->sprite = sfSprite_create();
    sets->rect = (sfIntRect){0, 0, 1920, 1080};
    sets->position = (sfVector2f){960, 540};
    sets->scale = (sfVector2f){2, 2};
    sets->origin = (sfVector2f){48, 48};
    sfSprite_setTexture(sets->sprite, sets->texture, sfTrue);
    sfSprite_setTextureRect(sets->sprite, sets->rect);
    sfSprite_setPosition(sets->sprite, sets->position);
    sfSprite_setScale(sets->sprite, sets->scale);
    sfSprite_setOrigin(sets->sprite, sets->origin);
    return true;
}

bool init_intra_game_buttons(in_game_buttons_t *button)
{
    bool (*init_funcs[])(void *) = {
        (bool (*)(void *))init_exit_game_button,
        (bool (*)(void *))init_resume_button,
        (bool (*)(void *))init_settings_button,
        (bool (*)(void *))init_save_button,
        (bool (*)(void *))init_menu_button
    };
    void *params[] = {
        &button->exit_game, &button->resume, &button->settings,
        &button->save, &button->menu
    };
    int num_init_funcs = sizeof(init_funcs) / sizeof(*init_funcs);

    for (int i = 0; i < num_init_funcs; i++)
        if (!init_funcs[i](params[i]))
            return false;
    return true;
}
