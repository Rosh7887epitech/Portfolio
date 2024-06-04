/*
** EPITECH PROJECT, 2024
** BSminishell1
** File description:
** main
*/

#include "my.h"

char **search_path(char **env)
{
    char **my_path;

    if (env == NULL)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            my_path = my_str_to_word_array(env[i] + 5, ':');
            return my_path;
        }
    }
    return NULL;
}

int my_access_denied(char *line, base_t *var)
{
    if (access(line, R_OK | X_OK) == -1) {
        var->status = 1;
        my_putstr(line);
        write(2, ": Permission denied.\n", 22);
        return 1;
    }
}

int main_loop(base_t *var)
{
    char *line = NULL;
    size_t bufsize = 0;
    int read = 0;
    int res = 0;

    while (1) {
        if (isatty(0) == 1)
            my_putstr("$> ");
        read = getline(&line, &bufsize, stdin);
        if (read < 0)
            exit(res);
        line[my_strlen(line) - 1] = '\0';
        line = clean_line(line);
        var->path = search_path(var->env);
        res = launch_command(var, line);
        var->status = 0;
        var->exit = res;
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    base_t *var = malloc(sizeof(base_t));

    if (env != NULL)
        var->env = mem_dup_2d_array(env);
    else
        var->env = NULL;
    main_loop(var);
    return 0;
}
