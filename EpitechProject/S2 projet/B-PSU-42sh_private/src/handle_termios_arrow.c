/*
** EPITECH PROJECT, 2024
** handle_termios_arrow.c
** File description:
** that file should handle termios arrows
*/
#include "my_project.h"

static int advance_in_history(char *str)
{
    int len = 0;
    int count = 0;

    for (len = 0; str[len] != '\0' && count != 2; len++) {
        if (str[len] == ' ')
            count++;
    }
    return len;
}

bool handle_arrow_right(term_stru_t *term)
{
    int cursor_x = 0;

    if (term->move_col < 0) {
        term->move_col++;
        cursor_x = term->min_col + my_strlen(term->str) + term->move_col;
        move_cursor(term->row, cursor_x);
    }
    return true;
}

bool handle_arrow_left(term_stru_t *term)
{
    int tmp = term->move_col * -1;
    int cursor_x = 0;

    if (tmp < my_strlen(term->str)) {
        term->move_col--;
        cursor_x = term->min_col + my_strlen(term->str) + term->move_col;
        move_cursor(term->row, cursor_x);
    }
    return true;
}

bool handle_arrow_up(char **history, term_stru_t *term)
{
    int len = 0;

    if (history != NULL && history[0] != NULL) {
        if (term->up_row >= array_size(history))
            return true;
        term->up_row++;
        move_cursor(term->row, term->min_col + my_strlen(term->str));
        clean_term(term);
        move_cursor(term->row, term->min_col);
        term->str = my_strdup(history[array_size(history) - term->up_row]);
        len = advance_in_history(term->str);
        term->str = term->str + len;
        my_putstr(term->str);
        term->move_col = 0;
    }
    return true;
}

bool handle_arrow_down(char **history, term_stru_t *term)
{
    int len = 0;

    if (history != NULL && history[0] != NULL) {
        if (term->up_row > array_size(history) || term->up_row == 0)
            return true;
        term->up_row--;
        move_cursor(term->row, term->min_col + my_strlen(term->str));
        clean_term(term);
        move_cursor(term->row, term->min_col);
        term->str = my_strdup(history[array_size(history) - term->up_row]);
        len = advance_in_history(term->str);
        term->str = term->str + len;
        my_putstr(term->str);
        term->move_col = 0;
    }
    return true;
}
