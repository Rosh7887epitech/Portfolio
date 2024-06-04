/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** menu
*/

#include "rpg.h"
#include "game_render.h"

bool init_all_buttons(menu_t *menu)
{
    if (!init_start_buttons(&menu->settings.start_buttons))
        return false;
    if (!init_intra_game_buttons(&menu->sets.in_game_buttons))
        return false;
    if (!init_settings_buttons(&menu->set.settings_buttons))
        return false;
    return true;
}

bool init_menu(menu_t *menu)
{
    if (!init_start_menu_sets(&menu->settings))
        return false;
    if (!init_intra_menu_sets(&menu->sets))
        return false;
    if (!init_settings_menu_sets(&menu->set))
        return false;
    if (!init_all_buttons(menu))
        return false;
    menu->sets.status = NONE;
    menu->state = NONE_MENU;
    return true;
}

void check_status_menu(game_t *rpg, sfEvent event)
{
    if (rpg->menu.state == START_MENU || rpg->menu.state == SETTING_MENU)
        return;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM) {
        if (rpg->menu.state == INTRA_MENU)
            rpg->menu.state = NONE_MENU;
        else
            rpg->menu.state = INTRA_MENU;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI) {
        if (rpg->menu.state == INVENTORY_MENU)
            rpg->menu.state = NONE_MENU;
        else
            rpg->menu.state = INVENTORY_MENU;
    }
}
