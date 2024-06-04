/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** main
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static void display_grid(char **grid)
{
    for (int i = 0; grid[i] != NULL; i++) {
        printf("%s\n", grid[i]);
    }
}

static int verif_map_one(char **grid)
{
    int i = 0;

    i = check_end(grid);
    if (i != 0) {
        if (i == 1)
            printf("Player 1 won!");
        if (i == 2)
            printf("Equality");
        exit(0);
    } else {
        return 0;
    }
}

static int verif_map_two(char **grid)
{
    int i = 0;

    i = check_end(grid);
    if (i != 0) {
        if (i == 1)
            printf("Player 2 won!");
        if (i == 2)
            printf("Equality");
        exit(0);
    } else {
        return 0;
    }
}

static char cond_change(int i, int j, char **grid, char p)
{
    if (grid[i][j] == ' ')
        grid[i][j] = p;
}

static char **change_map(char p, char *input, char **grid)
{
    char **res = my_str_to_word_tok(input, ",");
    int x = atoi(res[0]);
    int y = atoi(res[1]);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x ; j++) {
            grid[i][j] = cond_change(x, y, grid, p);
        }
    }
}

static int player_one(game_t *game)
{
    char *input = NULL;
    size_t bufsize = 0;
    int read = 0;
    int i = 0;

    printf("Player 1> ");
    read = getline(&input, &bufsize, stdin);
    game->game_map = change_map(game->p1, input, game->game_map);
    display_grid(game->game_map);
}

static int player_two(game_t *game)
{
    char *input = NULL;
    size_t bufsize = 0;
    int read = 0;
    int i = 0;

    printf("Player 2> ");
    read = getline(&input, &bufsize, stdin);
    game->game_map = change_map(game->p2 ,input, game->game_map);
    display_grid(game->game_map);
}

int main_loop(game_t *game)
{
    display_grid(game->game_map);
    while (1) {
        player_one(game);
        verif_map_one(game->game_map);
        player_two(game);
        verif_map_two(game->game_map);
    }
    return 0;
}
