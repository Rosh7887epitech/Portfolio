/*
** EPITECH PROJECT, 2023
** pop up
** File description:
** pop up
*/

#include "../include/soko.h"

static int search(soko_t *var)
{
    if (var->map[var->i][var->j] == 'P') {
        var->p_row = var->i ;
        var->p_col = var->j;
    }
}

soko_t *pos_of_p(soko_t *var)
{
    for (var->i = 0; var->i != var->row; var->i++) {
        for (var->j = 0; var->j != var->col; var->j++) {
            search(var);
        }
    }
    return var;
}

void display(soko_t *var)
{
    if (LINES < var->row + 2 || COLS < var->col + 2)
        mvprintw(LINES / 2, (COLS / 2) - (15 / 2), "SHELL TOO SMALL");
    else
        for (int i = 0; i < var->row; i++)
            mvprintw(LINES / 2 - var->row / 2 + i, COLS / 2 - var->col / 2,
            var->map[i]);
}

static void restart(soko_t *var, char ch)
{
    if (ch == ' ') {
        var->map = var->dup;
        coordinate_of_x(var);
        pos_of_p(var);
    }
}

int win_cond(soko_t *var, int k)
{
    k = 0;
    for (int i = 0; i < var->nb_o; i++) {
        if (var->coor_x_y[i] == var->coor_o_y[i] &&
        var->coor_x_x[i] == var->coor_o_x[i]) {
            k++;
        }
        if (var->map[var->coor_o_y[i]][var->coor_o_x[i]] == ' ') {
            var->map[var->coor_o_y[i]][var->coor_o_x[i]] = 'O';
        }
    }
    return k;
}

int window(soko_t *var, int k, char ch)
{
    initscr();
    while (1) {
        clear();
        display(var);
        ch = getch();
        move_player(ch, var, var->row, var->col);
        coordinate_of_x(var);
        k = win_cond(var, k);
        if (k == var->nb_o) {
            usleep(10000);
            endwin();
            return 0;
        }
        restart(var, ch);
        refresh();
    }
    endwin();
    return 0;
}

int my_popup(soko_t *var)
{
    int k = 0;
    char ch;

    object(var);
    pos_of_p(var);
    window(var, k, ch);
    return 0;
}
