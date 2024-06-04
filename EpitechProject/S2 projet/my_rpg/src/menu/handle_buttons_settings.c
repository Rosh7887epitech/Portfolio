/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** handle_buttons_settings
*/

#include "macro.h"
#include "rpg.h"
#include "utils.h"

void music_on_off(sfTexture *texture, game_t *game, button_t *volume)
{
    if (game->music.music_state == ON) {
        texture = sfTexture_createFromFile(
        "assets/images/buttons/menu_buttons_volume_pressed.png", NULL);
        sfRectangleShape_setTexture(volume->rect, texture, sfTrue);
        game->music.music_state = OFF;
        sfMusic_pause(game->music.music);
    } else {
        texture = sfTexture_createFromFile(
        "assets/images/buttons/menu_buttons_volume.png", NULL);
        sfRectangleShape_setTexture(volume->rect, texture, sfTrue);
        game->music.music_state = ON;
        sfMusic_play(game->music.music);
    }
}

void handle_exit_sets_button(sfEvent event, button_t *exit, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(exit)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_exit_pressed.png", NULL);
        sfRectangleShape_setTexture(exit->rect, texture, sfTrue);
        if (game->menu.last_state == NONE_MENU)
            game->menu.state = NONE_MENU;
        else
            game->menu.state = START_MENU;
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(exit))
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_exit_hover.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_exit.png", NULL);
    sfRectangleShape_setTexture(exit->rect, texture, sfTrue);
}

void handle_volume_button(sfEvent event, button_t *volume, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(volume))
        music_on_off(texture, game, volume);
    if (event.type == sfEvtMouseMoved && IS_HOVER(volume) &&
        game->music.music_state == ON)
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_volume_hover.png", NULL);
    else if (game->music.music_state != OFF)
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_volume.png", NULL);
    else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_volume_pressed.png", NULL);
    sfRectangleShape_setTexture(volume->rect, texture, sfTrue);
}

void handle_help_button(sfEvent event, button_t *help, game_t *game)
{
    sfTexture *texture = NULL;

    if (event.type == sfEvtMouseButtonPressed && IS_CLICK(help)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_setting_help_pressed.png",
            NULL);
        sfRectangleShape_setTexture(help->rect, texture, sfTrue);
        printf("HELP\n");
        return;
    }
    if (event.type == sfEvtMouseMoved && IS_HOVER(help)) {
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_setting_help_hover.png", NULL);
    } else
        texture = sfTexture_createFromFile(
            "assets/images/buttons/menu_buttons_setting_help.png", NULL);
    sfRectangleShape_setTexture(help->rect, texture, sfTrue);
}
