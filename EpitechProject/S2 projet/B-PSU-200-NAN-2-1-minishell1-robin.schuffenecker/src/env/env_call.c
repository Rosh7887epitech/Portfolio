/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** env_call
*/

#include "env.h"

int my_unsetenv_command(base_t *var, char *line, char **name)
{
    if (my_strlen(line) == 8) {
        my_putstr("unsetenv: Too few arguments.\n");
        if (!isatty(0))
            exit(1);
        return 1;
    }
    name = my_str_to_word_array(line, ' ');
    var->n = my_strdup(name[1]);
    var->env = unset_env(var);
    return 0;
}

int error_setenv(base_t *var, char **name, char *line)
{
    if (verif_name(name) == 1) {
        if (!isatty(0))
            exit(1);
        return 1;
    } else {
        var->env = set_env(var, line);
        return 0;
    }
}

int my_setenv_command(base_t *var, char *line, char **name)
{
    int fd = 0;

    if (my_strlen(line) == 6) {
        disp_env(var->env);
        return 0;
    }
    name = my_str_to_word_array(line, ' ');
    return error_setenv(var, name, line);
}

int my_env_command(base_t *var, char *line, char **name)
{
    int h = 0;

    if (my_strncmp(line, "unsetenv", 8) == 0) {
        var->status = 1;
        return my_unsetenv_command(var, line, name);
    }
    if (my_strncmp(line, "setenv", 6) == 0) {
        var->status = 1;
        return setenv_err(var, line, name);
    }
    if (my_strncmp(line, "env", 3) == 0) {
        var->status = 1;
        name = my_str_to_word_array(line, ' ');
        if (my_strlen(line) > 3)
            return err_env(name);
        return disp_env(var->env);
    }
}
