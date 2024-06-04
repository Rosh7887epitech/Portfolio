/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game_render
*/

#include "rpg.h"
#include "macro.h"
#include "game_render.h"
#include "npc.h"
#include "text.h"
#include "extern.h"
#include "my.h"

static void display_text_o(sfView *view, sfRenderWindow *window,
    sfText *text, off_set_t offset)
{
    sfVector2f pos = sfView_getCenter(view);

    sfText_setFont(text, globalFont);
    sfText_setScale(text, (sfVector2f){0.2, 0.2});
    pos = vector_edition(pos, offset.x, offset.y);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
}

void check_states(const game_t *game)
{
    if (game->menu.state == 0)
        return;
    if (game->menu.state == START_MENU)
        display_start_menu_buttons(game);
    if (game->menu.state == INTRA_MENU)
        display_intra_menu_buttons(game);
    if (game->menu.state == SETTING_MENU)
        display_settings_menu_buttons(game);
    if (game->menu.state == INVENTORY_MENU)
        display_inventory_menu(game);
}

static void render_quest_text(const game_t *game)
{
    off_set_t quest_frame_offset = {140, -100};

    display_frame(game->window.window, game->player.p_view.view,
        game->quest_frame.sprite, quest_frame_offset);
    display_text_on_screen(game->player.p_view.view, game->window.window,
        (info_text_t){quest_name_offset, quest_name_scale,
        global_quest_text});
    if (game->n_npc->npc.n_quest == NULL)
        return;
    if (game->n_npc->npc.n_quest->quest.current_step >= 1)
        display_text_on_screen(game->player.p_view.view, game->window.window,
            (info_text_t){quest_text_offset, quest_text_scale,
            game->n_npc->npc.n_quest->quest.title_obj});
}

void render_text_in_game(const game_t *game)
{
    if (game->n_npc->index != 0)
        display_text_on_screen(game->player.p_view.view, game->window.window,
            (info_text_t){npc_text_name_offset, npc_text_name_scale,
            game->n_npc->npc.name_obj});
    if (game->n_npc->npc.n_stories->stories.n_dialog->index != 0)
        display_text_on_screen(game->player.p_view.view, game->window.window,
            (info_text_t){npc_dialog_text_offset, npc_story_name_scale,
            game->n_npc->npc.n_stories->stories.n_dialog->dialog.text_obj});
}

static void display_room(const game_t *game)
{
    if (game->player.p_sprite.room == MAP) {
        sfRenderWindow_drawSprite(game->window.window,
            game->window.back, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->player.p_sprite.sprite, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->window.couche, NULL);
    }
    draw_school(game);
}

void render_game(const game_t *game)
{
    off_set_t health_bar_offset = {-200, -108};
    sfText *level = sfText_create();
    off_set_t xp = {-178, -85};

    DISPLAY_WINDOW(game->window.window);
    CLEAR_WINDOW(game->window.window, sfWhite);
    display_room(game);
    display_npc_on_screen(game);
    check_states(game);
    if (game->enemies.bat.health > 0)
        sfRenderWindow_drawSprite(game->window.window,
            game->enemies.bat.sprite, NULL);
    render_quest_text(game);
    check_states(game);
    draw_minimap(game);
    display_frame(game->window.window, game->player.p_view.view,
        game->health_bar.sprite, health_bar_offset);
    sfText_setString(level, my_strcat(my_itoa(game->player.level), " LVL"));
    display_text_o(game->player.p_view.view, game->window.window,
        level, xp);
}
