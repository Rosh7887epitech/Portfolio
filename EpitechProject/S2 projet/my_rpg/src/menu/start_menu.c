/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include "game_render.h"

void set_position(const start_buttons_t *but)
{
    sfRectangleShape_setPosition(but->new_game->rect,
        (sfVector2f){-30, 500});
    sfRectangleShape_setPosition(but->load->rect,
        (sfVector2f){-30, 610});
    sfRectangleShape_setPosition(but->settings->rect,
        (sfVector2f){-30, 720});
    sfRectangleShape_setPosition(but->exit->rect,
        (sfVector2f){-30, 830});
}

void set_scale(const start_buttons_t *but)
{
    sfVector2f scale = {5, 5};

    sfRectangleShape_setScale(but->exit->rect, scale);
    sfRectangleShape_setScale(but->settings->rect, scale);
    sfRectangleShape_setScale(but->new_game->rect, scale);
    sfRectangleShape_setScale(but->load->rect, scale);
}

void display_start_menu_buttons(const game_t *rpg)
{
    sfRenderWindow *window = rpg->window.window;
    const start_buttons_t *but = &rpg->menu.settings.start_buttons;

    if (rpg->menu.state != START_MENU)
        return;
    set_position(but);
    set_scale(but);
    sfRenderWindow_drawSprite(window, rpg->menu.settings.sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, but->exit->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, but->load->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, but->new_game->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, but->settings->rect, NULL);
}
