/*
** EPITECH PROJECT, 2024
** execute semicolon and pipe
** File description:
** that file should execute pipe and semicolon
*/
#include "struct.h"
#include "my_project.h"
#include <stdbool.h>
#include <stdlib.h>

static void execute_semicolon(envp_info_t *envp, info_t *line, int status)
{
    char **array = my_strtok(line->line_getted, ";");

    envp->is_semicolon = 1;
    for (int i = 0; array[i]; i++) {
        clean_esperluette(array[i]);
        line->line_getted = my_strdup(array[i]);
        our_sh(line, envp, status);
    }
}

bool is_semicolon(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ';' && is_pos_in_quotes(str, i) == NO_QUOTES)
            return true;
    }
    return false;
}

void execute_semicolon_pipe(info_t *line, envp_info_t *envp, int status)
{
    if (is_semicolon(line->line_getted)) {
        execute_semicolon(envp, line, status);
        envp->is_semicolon = 0;
        return;
    }
    if (replace_dollar(envp, line) == 1)
        return;
    if (execute_globbings(line, envp) == 1)
        return;
    make_pipe(line->line_getted, envp);
}
