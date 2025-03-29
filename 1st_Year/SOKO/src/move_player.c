/*
** EPITECH PROJECT, 2023
** move
** File description:
** move
*/

#include "../include/soko.h"

int left_move(char ch, soko_t *var, int nb_rows, int nb_cols)
{
    if (ch == 'D') {
        if (var->map[var->p_row][var->p_col - 1] == 'X' &&
        var->map[var->p_row][var->p_col - 2] != '#') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row][var->p_col - 1] = 'P';
            var->map[var->p_row][var->p_col - 2] = 'X';
            pos_of_p(var);
        } else {
            var->map[var->p_row][var->p_col] = 'P';
            pos_of_p(var);
        }
        if (var->map[var->p_row][var->p_col - 1] != '#' &&
        var->map[var->p_row][var->p_col - 1] != 'X') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row][var->p_col - 1] = 'P';
            pos_of_p(var);
        }
    }
}

int right_move(char ch, soko_t *var, int nb_rows, int nb_cols)
{
    if (ch == 'C') {
        if (var->map[var->p_row][var->p_col + 1] == 'X' &&
        var->map[var->p_row][var->p_col + 2] != '#') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row][var->p_col + 1] = 'P';
            var->map[var->p_row][var->p_col + 2] = 'X';
            pos_of_p(var);
        } else {
            var->map[var->p_row][var->p_col] = 'P';
            pos_of_p(var);
        }
        if (var->map[var->p_row][var->p_col + 1] != '#' &&
        var->map[var->p_row][var->p_col + 1] != 'X') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row][var->p_col + 1] = 'P';
            pos_of_p(var);
        }
    }
}

int up_move(char ch, soko_t *var, int nb_rows, int nb_cols)
{
    if (ch == 'A') {
        if (var->map[var->p_row - 1][var->p_col] == 'X' &&
        var->map[var->p_row - 2][var->p_col] != '#') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row - 1][var->p_col] = 'P';
            var->map[var->p_row - 2][var->p_col] = 'X';
            pos_of_p(var);
        } else {
            var->map[var->p_row][var->p_col] = 'P';
            pos_of_p(var);
        }
        if (var->map[var->p_row - 1][var->p_col] != '#' &&
        var->map[var->p_row - 1][var->p_col] != 'X') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row - 1][var->p_col] = 'P';
            pos_of_p(var);
        }
    }
}

int down_move(char ch, soko_t *var, int nb_rows, int nb_cols)
{
    if (ch == 'B') {
        if (var->map[var->p_row + 1][var->p_col] == 'X' &&
        var->map[var->p_row + 2][var->p_col] != '#') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row + 1][var->p_col] = 'P';
            var->map[var->p_row + 2][var->p_col] = 'X';
            pos_of_p(var);
        } else {
            var->map[var->p_row][var->p_col] = 'P';
            pos_of_p(var);
        }
        if (var->map[var->p_row + 1][var->p_col] != '#' &&
        var->map[var->p_row + 1][var->p_col] != 'X') {
            var->map[var->p_row][var->p_col] = ' ';
            var->map[var->p_row + 1][var->p_col] = 'P';
            pos_of_p(var);
        }
    }
}

int move_player(char ch, soko_t *var, int nb_rows, int nb_cols)
{
    up_move(ch, var, nb_rows, nb_cols);
    down_move(ch, var, nb_rows, nb_cols);
    left_move(ch, var, nb_rows, nb_cols);
    right_move(ch, var, nb_rows, nb_cols);
}
