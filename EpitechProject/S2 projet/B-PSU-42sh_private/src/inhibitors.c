/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** inhibitors
*/
#include "my_project.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void modify_q_status(char line, bool *sq, bool *dq)
{
    if (line == '\'' && *sq == false && *dq == false) {
        *sq = true;
        return;
    }
    if (line == '\'' && *sq == true) {
        *sq = false;
        return;
    }
    if (line == '\"' && *dq == false && *sq == false) {
        *dq = true;
        return;
    }
    if (line == '\"' && *dq == true)
        *dq = false;
}

static void print_quote_error(char *line, int pos)
{
    my_printerror("Unmatched '", 0);
    write(2, &line[pos], 1);
    my_printerror("'.\n", 0);
}

static int check_close_quote(char *line, int pos, int *skip)
{
    if (line[pos] != '\'' && line[pos] != '\"')
        return 0;
    if (pos == *skip) {
        *skip = -1;
        return 0;
    }
    for (int i = pos + 1; line[i] != '\0'; i++) {
        if (line[i] == line[pos]) {
            *skip = i;
            return 0;
        }
    }
    print_quote_error(line, pos);
    if (!isatty(STDOUT_FILENO))
        exit(1);
    return 1;
}

int check_inhibitors(info_t *line, envp_info_t *infos)
{
    bool dq = false;
    bool sq = false;
    int skip_quote_pos = -1;

    for (int i = 0; line->line_getted[i] != '\0'; i++) {
        if ((line->line_getted[i] == '\'' && dq == true) ||
        (line->line_getted[i] == '\"' && sq == true))
            continue;
        modify_q_status(line->line_getted[i], &sq, &dq);
        if (check_close_quote(line->line_getted, i, &skip_quote_pos) != 0) {
            infos->return_status = 1;
            infos->status = 1;
            return 1;
        }
    }
    return 0;
}

quotes_t is_pos_in_quotes(char *str, int pos)
{
    bool sq = false;
    bool dq = false;

    if (!str)
        return NO_QUOTES;
    for (int i = 0; str[i] != '\0'; i++) {
        modify_q_status(str[i], &sq, &dq);
        if (i == pos && sq)
            return SINGLE_QUOTES;
        if (i == pos && dq)
            return DOUBLE_QUOTES;
        if (i == pos)
            return NO_QUOTES;
    }
    return NO_QUOTES;
}

static void count_quotes_occ(char line, bool *sq, bool *dq, int *occ)
{
    if (line == '\'' && *sq == false) {
        *sq = true;
        *occ = *occ + 1;
        return;
    }
    if (line == '\'' && *sq == true) {
        *sq = false;
        return;
    }
    if (line == '\"' && *dq == false) {
        *dq = true;
        *occ = *occ + 1;
        return;
    }
    if (line == '\"' && *dq == true)
        *dq = false;
}

int count_quotes(char *str)
{
    bool sq = false;
    bool dq = false;
    int quote_occ = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        count_quotes_occ(str[i], &sq, &dq, &quote_occ);
    return quote_occ;
}

static char *alloc_new_str(char *str)
{
    int j = 0;
    char *new_str = NULL;

    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '\"' && is_pos_in_quotes(str, i) != SINGLE_QUOTES) ||
        (str[i] == '\'' && is_pos_in_quotes(str, i) != DOUBLE_QUOTES))
            continue;
        j++;
    }
    new_str = malloc(sizeof(char) * (j + 1));
    return new_str;
}

char *remove_quotes(char *str)
{
    char *new_str = alloc_new_str(str);
    int j = 0;

    if (str == NULL || new_str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '\"' && is_pos_in_quotes(str, i) != SINGLE_QUOTES) ||
        (str[i] == '\'' && is_pos_in_quotes(str, i) != DOUBLE_QUOTES))
            continue;
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    return new_str;
}
