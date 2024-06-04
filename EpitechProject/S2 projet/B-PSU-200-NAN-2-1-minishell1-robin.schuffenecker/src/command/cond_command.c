/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** cond_command
*/

#include "command.h"

int my_put_command(base_t *var, char *line)
{
    char **name;

    if (my_strncmp(line, "unsetenv", 8) == 0 ||
        my_strncmp(line, "setenv", 6) == 0 ||
        my_strncmp(line, "env", 3) == 0) {
        return my_env_command(var, line, name);
    }
    if (my_strncmp(line, "cd", 2) == 0) {
        return cd_command(var, line);
    }
    if (my_strcmp(line, "echo $?") == 0) {
        var->status = 1;
        my_put_nbr(var->exit);
        my_putchar('\n');
        return 0;
    }
}
