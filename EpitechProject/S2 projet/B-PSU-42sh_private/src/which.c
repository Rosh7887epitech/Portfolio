/*
** EPITECH PROJECT, 2024
** which.c
** File description:
** that function should handle the which command
*/

#include "my_project.h"
#include "struct.h"
static char *is_alias_existing(alias_t *alias, char *name)
{
    if (alias == NULL)
        return NULL;
    while (alias) {
        if (my_strcmp(alias->name, name) == 0)
            return my_strdup(alias->value);
        alias = alias->next;
    }
    return NULL;
}

static bool handle_error_which(envp_info_t *info, char **array)
{
    if (array_size(array) < 2) {
        info->return_status = 1;
        return my_printerror("which: Too few arguments.\n", true);
    }
    return false;
}

static void handle_known_path(char **array, envp_info_t *info, int i,
    char *path_value)
{
    char *value = NULL;

    array[i] = shell_function(array[i]);
    value = is_alias_existing(info->alias, array[i]);
    if (value != NULL) {
        my_putstr(array[i]);
        my_putstr(":\t\t aliased to ");
        my_putstr(value);
        my_putstr("\n");
    } else {
        my_putstr(my_strcat(path_value, my_strcat("/", array[i])));
        my_putchar('\n');
    }
    info->return_status = 0;
}

static void handle_unknown_path(char **array, envp_info_t *info, int i)
{
    if (access(array[i], F_OK | X_OK) != -1) {
        my_putstr(array[i]);
        my_putchar('\n');
        info->return_status = 0;
    } else {
        my_putstr(array[i]);
        my_putstr(": Command not found.\n");
        info->return_status = 1;
    }
}

static void execute_which(char **array, envp_info_t *info, char *path_value)
{
    for (int i = 0; array[i]; i++) {
        clean_esperluette(array[i]);
        if ((is_buildin(array[i]) || my_strcmp(array[i], "echo") == 0)
        && my_strcmp(array[i], "env") != 0) {
            my_putstr(array[i]);
            my_putstr(": shell built-in command.\n");
            continue;
        }
        array[i] = remove_quotes(array[i]);
        path_value = find_path(info->l_envp, array[i]);
        if (path_value)
            handle_known_path(array, info, i, path_value);
        else
            handle_unknown_path(array, info, i);
    }
}

bool handle_which(char *line, envp_info_t *info)
{
    char **array = str_to_word_array(line, " ");
    char *path_value = NULL;

    if (line == NULL)
        return false;
    if (my_strncmp(line, "which", 5) == 0 && array != NULL) {
        info->status = 1;
        if (handle_error_which(info, array))
            return true;
        array += 1;
        info->return_status = 0;
        path_value = find_in_envp(info->l_envp, "PATH=", 5);
        if (path_value == NULL)
            return true;
        execute_which(array, info, path_value);
        return true;
    }
    return false;
}
