/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell2-robin.schuffenecker
** File description:
** separator_cond
*/

#include "command.h"

int is_red(char *com)
{
    if (nb_of_char(com, '<') > 0 ||
        nb_of_char(com, '>') > 0)
        return 1;
    return 0;
}

int pipe_err(char *line)
{
    int g = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '|')
            g = i;
        if (line[g + 1] == '\0' || line[0] == '|') {
            my_putstr("Invalid null command.\n");
            return 1;
        }
    }
}

char **search_pipe(base_t *var, char **com)
{
    char *result = NULL;

    for (int i = 0; com[i] != NULL; i++) {
        com[i] = clean_line(com[i]);
        var->command = my_str_to_word_array(com[i], ' ');
        if (nb_of_slash(var->command[0]) < 1 &&
            my_strncmp(com[i], "./", 2) != 0)
            result = search_command(var, com[i]);
        else
            result = my_strdup(var->command[0]);
        if (result == NULL)
            com[i] = my_strdup(com[i]);
        else {
            result = my_strcat(result, "/");
            com[i] = my_strcat(result, com[i]);
        }
    }
    return com;
}
