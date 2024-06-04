/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** env
*/

#pragma once

    #include "my.h"
    #include "cd.h"
    #include "command.h"

int disp_env(char **env);
int err_env(char **name);
char **unset_env(base_t *var);
char **set_env(base_t *var, char *line);
int size_tab(base_t *var, int nb_rows);
char **unset_cond(base_t *var, char **new_env);
char **write_and_error(char *new_var, char **data,
    char **new_env, int nb_rows);
int setenv_err(base_t *var, char *line, char **name);
int my_setenv_command(base_t *var, char *line, char **name);
