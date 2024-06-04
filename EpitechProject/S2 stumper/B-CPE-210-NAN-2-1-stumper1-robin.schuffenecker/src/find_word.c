/*
** EPITECH PROJECT, 2024
** boggle
** File description:
** find the word in the grid
*/

#include "boggle.h"
#include <unistd.h>
#include <stdio.h>

int is_upper(char c)
{
    if ('A' <= c && c <= 'Z') {
        return 1;
    }
    return 0;
}

int explore_next_spot(char **grid, int i, int j, char *str)
{
    if (explore_grid(grid, i + 1, j, str + 1)) {
        return 1;
    }
    if (explore_grid(grid, i - 1, j, str + 1)) {
        return 1;
    }
    if (explore_grid(grid, i, j + 1, str + 1)) {
        return 1;
    }
    if (explore_grid(grid, i, j - 1, str + 1)) {
        return 1;
    }
    return 0;
}

int explore_grid(char **grid, int i, int j, char *str)
{
    if (*str == '\0') {
        return 1;
    }
    if (i < 0 || j < 0 || !grid[i] || !grid[i][j]
        || is_upper(grid[i][j]) || grid[i][j] != *str) {
        return 0;
    }
    grid[i][j] -= 32;
    if (explore_next_spot(grid, i, j, str)) {
        return 1;
    }
    grid[i][j] += 32;
    return 0;
}

int find_word(infos_t *infos)
{
    int done = 0;

    for (int i = 0; i < infos->size && !done; i++) {
        for (int j = 0; j < infos->size && !done; j++) {
            done = explore_grid(infos->grid, i, j, infos->word);
        }
    }
    if (!done) {
        my_putstr("The word \"");
        my_putstr(infos->word);
        my_putstr("\" is not in the grid.\n");
    } else {
        if (!isatty(0)) {
            write(1, "\b\b\0", 3);
        }
        display_boggle(infos);
    }
    return done;
}
