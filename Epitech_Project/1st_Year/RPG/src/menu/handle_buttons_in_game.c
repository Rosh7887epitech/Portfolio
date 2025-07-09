/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** handle_buttons_start_menu
*/

#include "macro.h"
#include "rpg.h"
#include "utils.h"

void handle_exit_game_button(sfEvent event, button_t *exit, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(exit)) {
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

void handle_resume_button(sfEvent event, button_t *resume, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(resume)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_resume_pressed.png", NULL);
        sfRectangleShape_setTexture(resume->rect, texture, sfTrue);
        game->menu.sets.status = RELEASE;
        game->menu.state = NONE_MENU;
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(resume))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_resume_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_resume.png", NULL);
    sfRectangleShape_setTexture(resume->rect, texture, sfTrue);
}

void handle_save_button(sfEvent event, button_t *save, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(save)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_save_pressed.png", NULL);
        sfRectangleShape_setTexture(save->rect, texture, sfTrue);
        printf("SAVE\n");
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(save))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_save_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_save.png", NULL);
    sfRectangleShape_setTexture(save->rect, texture, sfTrue);
}

void handle_sets_button(sfEvent event, button_t *settings, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(settings)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_settings_pressed.png", NULL);
        sfRectangleShape_setTexture(settings->rect, texture, sfTrue);
        game->menu.sets.status = RELEASE;
        game->menu.last_state = NONE_MENU;
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
