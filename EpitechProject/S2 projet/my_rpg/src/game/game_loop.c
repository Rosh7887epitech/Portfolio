/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game_loop
*/

#include "rpg.h"
#include "game_logic.h"
#include "game_render.h"
#include "macro.h"

static bool start_anime(game_t *game)
{
    sfVector2f scale = {8, 8};

    while (scale.x > 1.2) {
        scale.x -= 0.1;
        scale.y -= 0.1;
        sfSprite_setScale(game->window.room.start_anim, scale);
        sfRenderWindow_clear(game->window.window, sfBlack);
        sfRenderWindow_drawSprite(game->window.window,
            game->window.room.start_anim, NULL);
        sfRenderWindow_display(game->window.window);
        sfSleep((sfTime){10000});
    }
    sfSleep((sfTime){800000});
    return true;
}

void game_loop(game_t *game)
{
    bool start = false;

    while (game->state == GAME_RUNNING && IS_W_OPEN(game->window.window)) {
        if (start == false)
            start = start_anime(game);
        handle_events(game);
        update_game(game);
        render_game(game);
    }
}
