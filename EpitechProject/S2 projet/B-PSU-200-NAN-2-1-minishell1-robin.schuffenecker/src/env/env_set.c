/*
** EPITECH PROJECT, 2024
** env
** File description:
** env command
*/

#include "env.h"

char **size_newenv(base_t *var, int nb_rows)
{
    char **new_env;

    new_env = malloc(sizeof(char *) * (nb_rows + 2));
    if (new_env == NULL)
        return NULL;
    for (int i = 0; i < nb_rows; i++) {
        new_env[i] = malloc(sizeof(char) * my_strlen(var->env[i]) + 1);
        my_strcpy(new_env[i], var->env[i]);
    }
    return new_env;
}

char **write_and_error(char *new_var, char **data,
    char **new_env, int nb_rows)
{
    if (new_var == NULL)
        return NULL;
    my_strcpy(new_var, data[1]);
    new_var = my_strcat(new_var, "=");
    if (data[2] != NULL)
        new_var = my_strcat(new_var, data[2]);
    if (new_var == NULL)
        return NULL;
    new_env[nb_rows] = new_var;
    new_env[nb_rows + 1] = NULL;
    return new_env;
}

int size_tab(base_t *var, int nb_rows)
{
    while (var->env[nb_rows] != NULL)
        nb_rows++;
    return nb_rows;
}

char **set_env(base_t *var, char *line)
{
    char **data = my_str_to_word_array(line, ' ');
    int nb_rows = 0;
    char *new_var;
    char **new_env;

    nb_rows = size_tab(var, nb_rows);
    new_env = size_newenv(var, nb_rows);
    if (data[2] != NULL) {
        new_var = malloc(sizeof(char)*
            (my_strlen(data[1]) + my_strlen(data[2]) + 2));
    } else
        new_var = malloc(sizeof(char)* (my_strlen(data[1]) + 2));
    return write_and_error(new_var, data, new_env, nb_rows);
}

int disp_env(char **env)
{
    while (*env) {
        my_putstr(*env);
        my_putchar('\n');
        env++;
    }
    return 0;
}
