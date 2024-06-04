/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** intra_menu
*/

#include "rpg.h"
#include "game_render.h"

void set_intra_positions(const game_t *rpg, const in_game_buttons_t *button,
    sfView *view)
{
    sfVector2f pos = sfView_getCenter(view);

    sfSprite_setPosition(rpg->menu.sets.sprite,
        (sfVector2f){pos.x - 15, pos.y + 10});
    sfRectangleShape_setPosition(button->menu->rect,
        (sfVector2f){pos.x - 50, pos.y - 50});
    sfRectangleShape_setPosition(button->resume->rect,
        (sfVector2f){pos.x - 85, pos.y - 10});
    sfRectangleShape_setPosition(button->save->rect,
        (sfVector2f){pos.x + 15, pos.y + 5});
    sfRectangleShape_setPosition(button->settings->rect,
        (sfVector2f){pos.x - 85, pos.y + 20});
    sfRectangleShape_setPosition(button->exit_game->rect,
        (sfVector2f){pos.x - 85, pos.y + 50});
}

void set_intra_scale(const in_game_buttons_t *button)
{
    sfVector2f scale = {0.90, 0.90};

    sfRectangleShape_setScale(button->menu->rect, (sfVector2f){1.25, 1.25});
    sfRectangleShape_setScale(button->exit_game->rect, scale);
    sfRectangleShape_setScale(button->resume->rect, scale);
    sfRectangleShape_setScale(button->save->rect, scale);
    sfRectangleShape_setScale(button->settings->rect, scale);
}

void display_intra_menu_buttons(const game_t *rpg)
{
    sfRenderWindow *window = rpg->window.window;
    const in_game_buttons_t *button = &rpg->menu.sets.in_game_buttons;
    sfView *view = rpg->player.p_view.view;

    set_intra_positions(rpg, button, view);
    set_intra_scale(button);
    sfRenderWindow_drawSprite(window, rpg->menu.sets.sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, button->menu->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->exit_game->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->resume->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->save->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->settings->rect, NULL);
}
