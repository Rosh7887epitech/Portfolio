/*
** EPITECH PROJECT, 2024
** check_end
** File description:
** Return 1 if game won 2 if it is a draw 0 else
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int check_draw_by_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ' ')
            return 1;
    return 0;
}

static int check_draw(char **grid)
{
    for (int i = 0; grid[i] != NULL; i++)
        if (check_draw_by_line(grid[i]) != 0)
            return 1;
    return 0;
}

static int check_diag_win(char **grid)
{
    char upper_left = grid[1][1];
    char lower_left = grid[strlen(grid[0]) - 1][1];
    int len = strlen(grid[0]);

    for (int i = 2; grid[i][i] != '+'; i++)
        if (grid[i][i] != upper_left)
            return 1;
    for (int i = 2; grid[len - 1][i] != '+'; i++) {
        if (grid[len - 1][i] != lower_left)
            return 1;
        len--;
    }
    return 0;
}

static int check_each_line(char *line)
{
    char c = line[1];

    for (int i = 2; line[i] != '\0'; i++)
        if (line[i] != c && c != '-')
            return 1;
    return 0;
}

static int check_line_win(char **grid)
{
    for (int i = 0; grid[i] != NULL; i++) {
        if (check_each_line(grid[i]) == 0)
            return 0;
    }
    return 1;
}

int check_each_column(char **grid, int col)
{
    char c = grid[col][1];

    for (int i = 1; grid[col][i] != '\0'; i++)
        if (grid[col][i] != c)
            return 1;
    return 0;
}

int check_column_win(char **grid)
{
    for (int i = 0; i < strlen(grid[0]); i++)
        if (check_each_column(grid, i) == 0)
            return 0;
    return 1;
}

int check_end(char **grid)
{
    if (check_line_win(grid) == 0)
        return 1;
    if (check_diag_win(grid) == 0)
        return 1;
    if (check_column_win(grid) == 0)
        return 1;
    if (check_draw(grid) == 0)
        return 2;
    return 0;
}
