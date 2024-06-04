/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** env_unset
*/

#include "env.h"

char **unset_cond(base_t *var, char **new_env)
{
    int nb_rows = 0;
    int save = 0;

    while (var->env[nb_rows] != NULL) {
        if (my_strncmp(var->env[nb_rows], var->n, my_strlen(var->n)) != 0)
            save++;
        nb_rows++;
    }
    new_env = malloc(sizeof(char *) * (save + 1));
    if (new_env == NULL)
        return NULL;
    var->nb_rows = nb_rows;
    var->save = save;
    return new_env;
}

char **unset_env(base_t *var)
{
    char **new_env = unset_cond(var, new_env);
    int j = 0;

    for (int i = 0; i < var->nb_rows; i++) {
        if (my_strncmp(var->env[i], var->n, my_strlen(var->n)) != 0) {
            new_env[j] = malloc(my_strlen(var->env[i]) + 1);
            my_strcpy(new_env[j++], var->env[i]);
        }
    }
    new_env[var->save] = NULL;
    return new_env;
}
