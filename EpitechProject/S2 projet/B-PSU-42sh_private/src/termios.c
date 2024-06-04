/*
** EPITECH PROJECT, 2024
** termios.c
** File description:
** that file should init termios functionnality
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "my_project.h"
#include <sys/types.h>
#include <dirent.h>

static void init_termios(struct termios *old, struct termios *new)
{
    tcgetattr(STDIN_FILENO, old);
    memcpy(new, old, sizeof(struct termios));
    new->c_lflag &= ~(ICANON | ECHO);
    new->c_cc[VMIN] = 3;
    new->c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, new);
}

static char *remove_char(term_stru_t *term, int index)
{
    int i = 0;
    int len = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(term->str)));

    for (i = 0; term->str[i] != '\0' && i < index; i++)
        newstr[i] = term->str[i];
    for (len = i + 1; term->str[len] != '\0'; len++) {
        newstr[i] = term->str[len];
        i++;
    }
    newstr[i] = '\0';
    return newstr;
}

static bool handle_backspace(term_stru_t *term)
{
    int index = my_strlen(term->str) + term->move_col - 1;
    char *newstr = NULL;
    int cursor_x = 0;

    if (term->c == 127) {
        if (term->str == NULL || term->str[0] == '\0' || index < 0)
            return true;
        move_cursor(term->row, term->min_col + my_strlen(term->str));
        clean_term(term);
        move_cursor(term->row, term->min_col);
        newstr = remove_char(term, index);
        my_putstr(newstr);
        cursor_x = term->min_col + my_strlen(newstr) + term->move_col;
        move_cursor(term->row, cursor_x);
        term->str = my_strdup(newstr);
        return true;
    }
    return false;
}

/*  A = haut, B =  bas, C = droite, D = gauche */
static bool handle_arrow(term_stru_t *term, char **history)
{
    if (term->c == 27) {
        read(STDIN_FILENO, &term->c, 1);
        if (term->c != '[')
            return false;
        read(STDIN_FILENO, &term->c, 1);
        if (term->c == '3') {
            read(STDIN_FILENO, &term->c, 1);
            return true;
        }
        if (term->c == 'A')
            return handle_arrow_up(history, term);
        if (term->c == 'B')
            return handle_arrow_down(history, term);
        if (term->c == 'D')
            return handle_arrow_left(term);
        if (term->c == 'C')
            return handle_arrow_right(term);
    }
    return false;
}

static term_stru_t init_structure(void)
{
    term_stru_t term;

    term.tab_cmpletion = NULL;
    term.c = '\0';
    term.index_str = 0;
    term.move_col = 0;
    term.up_row = 0;
    term.col = 0;
    term.row = 0;
    term.str = NULL;
    term.is_history = false;
    term.is_autocompletion = false;
    init_termios(&term.old_settings, &term.new_settings);
    get_cursor_position(&term.row, &term.col);
    term.min_col = term.col;
    return term;
}

static char **read_from_history(envp_info_t *envp)
{
    char *buffer = NULL;
    char **history = NULL;

    if (envp == NULL)
        return NULL;
    buffer = search_history_data(envp);
    history = my_strtok(buffer, "\n");
    free(buffer);
    if (history == NULL)
        return NULL;
    for (int i = 0; history[i]; i++)
        clean_esperluette(history[i]);
    return history;
}

static void handle_add_char(term_stru_t *term, envp_info_t *info)
{
    char *tmp = my_strdup(term->str);
    int index = 0;
    int cursor_x = 0;

    if (term->c == '\t') {
        if (handle_tabulation(info, term))
            return;
    }
    for (int i = 0; term->str != NULL && term->str[i] != '\0'; i++)
        my_putstr("\b");
    term->up_row = 0;
    index = my_strlen(term->str) + term->move_col;
    term->str = add_char_str(tmp, term->c, index);
    move_cursor(term->row, term->min_col);
    my_putstr(term->str);
    cursor_x = term->min_col + my_strlen(term->str) + term->move_col;
    move_cursor(term->row, cursor_x);
}

static void restore_old_command(term_stru_t *term, envp_info_t *envp)
{
    if (envp->tmp_line != NULL) {
        term->str = my_strdup(envp->tmp_line);
        envp->tmp_line = NULL;
        my_putstr(term->str);
    } else
        term->str = NULL;
}

static void save_old_command(term_stru_t *term, info_t *info)
{
    if (term->str == NULL) {
        info->line_getted = my_strdup("\n");
        return;
    }
    if (term->str[0] == '\0' || term->str[0] == '\n')
        info->line_getted = my_strdup("\n");
    else
        info->line_getted = my_strdup(term->str);
}

void get_input(envp_info_t *envp, info_t *info)
{
    term_stru_t term = init_structure();
    char **history = read_from_history(envp);

    restore_old_command(&term, envp);
    while (term.c != '\n') {
        read(STDIN_FILENO, &term.c, 1);
        if (term.c == '\n')
            break;
        if (handle_arrow(&term, history))
            continue;
        if (handle_backspace(&term))
            continue;
        handle_add_char(&term, envp);
    }
    my_putchar('\n');
    tcsetattr(STDIN_FILENO, TCSANOW, &term.old_settings);
    save_old_command(&term, info);
}
