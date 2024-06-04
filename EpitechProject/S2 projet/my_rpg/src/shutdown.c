/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** shutdown
*/

#include <stdlib.h>
#include "rpg.h"
#include "npc.h"

void shutdown_game(game_t *game)
{
    sfRenderWindow_destroy(game->window.window);
    sfMusic_destroy(game->music.music);
    free_items_list(game->node_items);
    free_npc(game->n_npc);
}
