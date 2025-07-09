/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"
#include "my.h"
#include "npc.h"

const sfVector2f vectorfzero = {0, 0};
const sfVector2f initial_menu_size = {100, 50};
const sfColor hover_color = {169, 169, 169, 255};
const sfColor grey_color = {128, 128, 128, 255};
const sfColor silver_color = {192, 192, 192, 255};
const sfColor light_gray = {211, 211, 211, 255};
const sfColor dimgray = {105, 105, 105, 255};

void print_game(game_t game)
{
    node_npc_t *current = game.n_npc;

    while (current != NULL) {
        print_npc(current->npc);
        current = current->next;
    }
}

int my_rpg(int ac, char *param1)
{
    game_t game;

    if (ac == 2 && my_strcmp(param1, "-h") == 0) {
        my_putstr("USAGE\n\t./my_rpg\n\nDESCRIPTION\n\tA simple RPG game.\n");
        return 0;
    }
    if (!initialize_game(&game))
        return 84;
    if (ac != 1)
        return 84;
    game_loop(&game);
    shutdown_game(&game);
    return 0;
}
