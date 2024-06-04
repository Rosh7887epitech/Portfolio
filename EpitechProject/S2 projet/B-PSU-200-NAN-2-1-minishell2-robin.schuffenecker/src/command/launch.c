/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** ex_com
*/

#include "command.h"

int verif_name(char **name)
{
    if (my_char_isalphanum(name[1][0]) == 1) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        if (!isatty(0))
            exit(1);
        return 1;
    }
    if (my_str_isalphanum(name[1]) == 1) {
        my_putstr("setenv: Variable name must");
        my_putstr(" contain alphanumeric characters.\n");
        if (!isatty(0))
            exit(1);
        return 1;
    }
    return 0;
}

int cond_error(char *result, char *line, base_t *var)
{
    int res = 0;

    if (result == NULL) {
        my_putstr(var->command[0]);
        my_putstr(": Command not found.\n");
        res = 1;
    } else
        res = exec_command(var, line, result);
    return res;
}

int cond_launch(base_t *var, char *line)
{
    char *result;

    var->command = my_str_to_word_array(line, ' ');
    if (nb_of_slash(var->command[0]) < 1 && my_strncmp(line, "./", 2) != 0)
        result = search_command(var, line);
    else
        result = my_strdup(var->command[0]);
    return cond_error(result, line, var);
}

int launch_command(base_t *var, char *line)
{
    int t = 0;

    if (var->status == 1)
        return 1;
    if (line[0] == '\0')
        return 0;
    if (my_strcmp(line, "exit") == 0 || my_strncmp(line, "exit ", 5) == 0) {
        var->status = 1;
        t = cond_exit(line);
        if (t != 0)
            return t;
    }
    t = my_put_command(var, line);
    if (var->status != 1) {
        return cond_launch(var, line);
    } else
        return t;
}
