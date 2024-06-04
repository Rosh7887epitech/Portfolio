/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** main
*/

#include "include/my.h"
#include <stdlib.h>

static void free_all(game_t *game)
{
    for (int i = 0; game->cmd[i] != NULL; i++) {
        free(game->cmd[i]);
    }
    free(game->cmd);
    for (int j = 0; game->game_map[j] != NULL; j++) {
        free(game->game_map[j]);
    }
    free(game->game_map);
    free(game);
}

int main(int ac, char **av)
{
    game_t *game = (game_t *)malloc(sizeof(game_t));

    if (ac == 1) {
        game->p1 = 'X';
        game->p2 = 'O';
        game->map_size = 3;
    } else {
        fill_cmd(av, game);
    }
    game->game_map = create_grid(game->map_size);
    main_loop(game);
    free_all(game);
    return 0;
}
