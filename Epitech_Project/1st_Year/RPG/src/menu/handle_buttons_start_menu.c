/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** handle_buttons_states
*/

#include "macro.h"
#include "rpg.h"
#include "utils.h"

void handle_exit_button(sfEvent event, button_t *exit, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed &&
        IS_CLICK(exit)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_exit_pressed.png", NULL);
        sfRectangleShape_setTexture(exit->rect, texture, sfTrue);
        CLOSE_WINDOW(game->window.window);
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(exit))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_exit_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_exit.png", NULL);
    sfRectangleShape_setTexture(exit->rect, texture, sfTrue);
}

void handle_new_button(sfEvent event, button_t *new, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed &&
        (IS_CLICK(new) || (IS_PRES(new) && IS_REL(new)))) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_new_pressed.png", NULL);
        sfRectangleShape_setTexture(new->rect, texture, sfTrue);
        game->menu.last_state = NONE_MENU;
        game->menu.state = NONE_MENU;
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(new))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_new_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_new.png", NULL);
    sfRectangleShape_setTexture(new->rect, texture, sfTrue);
}

void handle_load_button(sfEvent event, button_t *load, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed &&
        IS_CLICK(load)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_load_pressed.png", NULL);
        sfRectangleShape_setTexture(load->rect, texture, sfTrue);
        printf("LOAD GAME\n");
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(load))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_load_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_load.png", NULL);
    sfRectangleShape_setTexture(load->rect, texture, sfTrue);
}

void handle_settings_button(sfEvent event, button_t *settings, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(settings)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_settings_pressed.png", NULL);
        sfRectangleShape_setTexture(settings->rect, texture, sfTrue);
        game->menu.state = SETTING_MENU;
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(settings))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_settings_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_settings.png", NULL);
    sfRectangleShape_setTexture(settings->rect, texture, sfTrue);
}
