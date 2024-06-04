/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** env_error
*/


#include "env.h"

int err_env(char **name)
{
    my_putstr("env: '");
    my_putstr(name[1]);
    my_putstr("': No such file or directory\n");
    return 1;
}

int setenv_err(base_t *var, char *line, char **name)
{
    if (nb_of_char(line, ' ') >= 3) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    return my_setenv_command(var, line, name);
}
