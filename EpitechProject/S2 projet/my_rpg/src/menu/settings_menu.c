/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** settings_menu
*/

#include "rpg.h"
#include "game_render.h"

void set_setting_position(const settings_buttons_t *but, sfView *view)
{
    sfVector2f pos = sfView_getCenter(view);

    sfRectangleShape_setPosition(but->volume->rect,
        (sfVector2f){pos.x + 300, pos.y - 100});
    sfRectangleShape_setPosition(but->setting_help->rect,
        (sfVector2f){pos.x + 300, pos.y});
    sfRectangleShape_setPosition(but->setting_exit->rect,
        (sfVector2f){pos.x + 300, pos.y + 100});
}

void set_setting_scale(const settings_buttons_t *but)
{
    sfVector2f scale = {5, 5};

    sfRectangleShape_setScale(but->setting_exit->rect, scale);
    sfRectangleShape_setScale(but->setting_help->rect, scale);
    sfRectangleShape_setScale(but->volume->rect, scale);
}

void display_settings_menu_buttons(const game_t *rpg)
{
    sfRenderWindow *window = rpg->window.window;
    const settings_buttons_t *but = &rpg->menu.set.settings_buttons;
    sfView *view = sfView_create();

    if (rpg->menu.state != SETTING_MENU)
        return;
    if (rpg->menu.last_state == START_MENU) {
        set_setting_position(but, view);
        set_setting_scale(but);
        sfRenderWindow_drawSprite(window, rpg->menu.settings.sprite, NULL);
    } else
        set_settings_menu_in_game(rpg);
    sfRenderWindow_drawSprite(window, rpg->menu.set.sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, but->setting_exit->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, but->setting_help->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, but->volume->rect, NULL);
}

void set_settings_menu_in_game(const game_t *rpg)
{
    const settings_buttons_t *but = &rpg->menu.set.settings_buttons;
    sfView *view = rpg->player.p_view.view;
    sfVector2f pos = sfView_getCenter(view);
    sfVector2f scale = {1, 1};

    sfSprite_setPosition(rpg->menu.set.sprite,
        (sfVector2f){pos.x - 15, pos.y + 10});
    sfRectangleShape_setPosition(but->volume->rect,
        (sfVector2f){pos.x - 40, pos.y - 25});
    sfRectangleShape_setPosition(but->setting_help->rect,
        (sfVector2f){pos.x - 40, pos.y + 10});
    sfRectangleShape_setPosition(but->setting_exit->rect,
        (sfVector2f){pos.x - 40, pos.y + 45});
    sfSprite_setScale(rpg->menu.set.sprite, (sfVector2f){2, 2});
    sfRectangleShape_setScale(but->setting_exit->rect, scale);
    sfRectangleShape_setScale(but->setting_help->rect, scale);
    sfRectangleShape_setScale(but->volume->rect, scale);
}
