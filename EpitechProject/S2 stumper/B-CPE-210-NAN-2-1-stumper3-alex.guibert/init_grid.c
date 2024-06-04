/*
** EPITECH PROJECT, 2024
** tictactoe
** File description:
** alloc
*/

#include "include/my.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char **init_grid(char **grid, int size)
{
    grid[0][0] = '+';
    for (int i = 1; i < size + 1; i++) {
        grid[0][i] = '-';
    }
    grid[0][size + 1] = '+';
    for (int j = 1; j < size + 1; j++) {
        grid[j][0] = '|';
        for (int k = 1; k < size + 1; k++) {
            grid[j][k] = ' ';
        }
        grid[j][size + 1] = '|';
    }
    grid[size + 1][0] = '+';
    for (int w = 1; w < size + 1; w++) {
        grid[size + 1][w] = '-';
    }
    grid[size + 1][size + 1] = '+';
    return grid;
}

char **create_grid(int size)
{
    char **grid = malloc(sizeof(char *) * (size + 3));

    if (grid == NULL)
        return NULL;
    for (int j = 0; j < size + 2; j++) {
        grid[j] = malloc(sizeof(char) * (size + 2));
        if (grid[j] == NULL)
            return NULL;
        grid[j][size + 2] = '\0';
    }
    grid[size + 3] = NULL;
    return init_grid(grid, size);
}
