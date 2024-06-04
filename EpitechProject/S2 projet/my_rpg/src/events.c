/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** events
*/

#include "macro.h"
#include "rpg.h"
#include "npc.h"
#include "utils.h"

void handle_start_menu(sfEvent event, game_t *game)
{
    if (game->menu.state != START_MENU)
        return;
    handle_exit_button(event, game->menu.settings.start_buttons.exit, game);
    handle_new_button(event, game->menu.settings.start_buttons.new_game, game);
    handle_load_button(event, game->menu.settings.start_buttons.load, game);
    handle_settings_button(event,
    game->menu.settings.start_buttons.settings, game);
}

void handle_intra_menu(sfEvent event, game_t *game)
{
    sfVector2i mous_pos = sfMouse_getPositionRenderWindow(game->window.window);
    sfView *view = game->player.p_view.view;
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window.window,
    mous_pos, view);

    if (game->menu.state != INTRA_MENU)
        return;
    event.mouseButton.x = pos.x;
    event.mouseButton.y = pos.y;
    handle_exit_game_button(event,
        game->menu.sets.in_game_buttons.exit_game, game);
    handle_resume_button(event, game->menu.sets.in_game_buttons.resume, game);
    handle_save_button(event, game->menu.sets.in_game_buttons.save, game);
    handle_sets_button(event, game->menu.sets.in_game_buttons.settings, game);
}

void handle_setting_menu(sfEvent event, game_t *game)
{
    sfVector2i mous_pos = sfMouse_getPositionRenderWindow(game->window.window);
    sfView *view = game->player.p_view.view;
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window.window,
    mous_pos, view);

    if (game->menu.state != SETTING_MENU)
        return;
    if (game->menu.last_state == NONE_MENU) {
        event.mouseButton.x = pos.x;
        event.mouseButton.y = pos.y;
    }
    handle_exit_sets_button(event,
        game->menu.set.settings_buttons.setting_exit, game);
    handle_volume_button(event, game->menu.set.settings_buttons.volume, game);
    handle_help_button(event, game->menu.set.settings_buttons.setting_help,
        game);
}

void handle_inventory(sfEvent event, game_t *game)
{
    if (game->menu.state != INVENTORY_MENU)
        return;
}

static void check_wich_key_pressed_for_menues(sfEvent event, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM)
        display_intra_menu_buttons(game);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        display_inventory_menu(game);
}

static void do_npc_action(sfEvent event, node_npc_t *current)
{
    if (current->npc.is_spoken && event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyE)
        npc_dialogue_next(&current->npc);
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
        current->npc.is_spoken = true;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF)
        reset_dialogues(&current->npc);
}

static void text_action(sfEvent event, game_t *game)
{
    node_npc_t *current = game->n_npc;

    if (game->menu.state != NONE_MENU)
        return;
    while (current) {
        do_npc_action(event, current);
        current = current->next;
    }
}

void handle_events(game_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window.window, &event)) {
        check_status_menu(rpg, event);
        handle_start_menu(event, rpg);
        check_states(rpg);
        handle_intra_menu(event, rpg);
        check_states(rpg);
        handle_setting_menu(event, rpg);
        check_states(rpg);
        update_state_minimap(rpg, event, &rpg->minimap);
        handle_inventory(event, rpg);
        player_action(event, rpg);
        close_window_event(event, &rpg->window);
        text_action(event, rpg);
    }
    move_condition(event, rpg);
}
