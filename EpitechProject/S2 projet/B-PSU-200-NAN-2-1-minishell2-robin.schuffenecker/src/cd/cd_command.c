/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** cd_command
*/

#include "cd.h"

char *search_home(base_t *var)
{
    char *my_path;

    for (int i = 0; var->env[i] != NULL; i++) {
        if (my_strncmp(var->env[i], "HOME", 4) == 0) {
            my_path = malloc(sizeof(char) * my_strlen(var->env[i]));
            my_path = my_strdup(var->env[i] + 5);
            return my_path;
        }
    }
    return NULL;
}

int cond_normal_cd(base_t *var, char old_path[], char **where)
{
    struct stat sb;

    if (chdir(where[1]) == 0) {
        var->old_path = my_strdup(old_path);
        return 0;
    } else {
        return cd_error(var, where, &sb);
    }
    return 0;
}

int normal_cd(base_t *var, char *line)
{
    char old_path[1024];
    char **where = my_str_to_word_array(line, ' ');

    getcwd(old_path, sizeof(old_path));
    if (my_strlen(var->command[1]) > 256) {
        my_putstr(var->command[1]);
        my_putstr(": File name too long.\n");
        if (!isatty(0))
            exit(1);
        return 1;
    }
    return cond_normal_cd(var, old_path, where);
}

int complet_cd(base_t *var, char *line)
{
    if (my_strncmp(line, "cd", 2) == 0 &&
        my_strcmp(var->command[1], "-") == 0) {
        var->status = 1;
        return old_cd(var);
    } else {
        var->status = 1;
        return normal_cd(var, line);
    }
}

int cd_command(base_t *var, char *line)
{
    char *res = NULL;
    char old_path[1024];

    var->command = my_str_to_word_array(line, ' ');
    getcwd(old_path, sizeof(old_path));
    if (my_strcmp(line, "cd") == 0 ||
        my_strcmp(var->command[1], "~") == 0) {
        var->status = 1;
        var->old_path = my_strdup(old_path);
        res = search_home(var);
        chdir(res);
        return 0;
    }
    return complet_cd(var, line);
}
