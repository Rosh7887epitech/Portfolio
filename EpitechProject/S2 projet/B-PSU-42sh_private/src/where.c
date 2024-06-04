/*
** EPITECH PROJECT, 2024
** where.c
** File description:
** that file should handle where
*/

#include "my_project.h"
#include <dirent.h>
#include <sys/types.h>

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

static bool handle_error_where(envp_info_t *info, char **array)
{
    if (array_size(array) < 2) {
        info->return_status = 1;
        my_printerror("where: Too few arguments.\n", true);
        if (!isatty(STDIN_FILENO))
            exit(1);
        return true;
    }
    return false;
}

static bool find_file_in_folder(char *folder, char *command, bool find)
{
    DIR *file = opendir(folder);
    struct dirent *dir;

    if (file == NULL)
        return find;
    dir = readdir(file);
    while (dir != NULL) {
        if (my_strcmp(dir->d_name, command) == 0) {
            my_putstr(my_strcat(folder, my_strcat("/", dir->d_name)));
            my_putchar('\n');
            find = true;
        }
        dir = readdir(file);
    }
    return find;
}

static bool handle_aliases_to(char *command, envp_info_t *info)
{
    char *value = is_alias_existing(info->alias, command);

    if (value != NULL) {
        my_putstr(command);
        my_putstr(" is aliased to ");
        my_putstr(value);
        my_putstr("\n");
        return true;
    }
    return false;
}

void find_all_folder(envp_info_t *info, char *command)
{
    char *path = find_in_envp(info->l_envp, "PATH=", 5);
    char **array = NULL;
    int find = false;

    if (handle_aliases_to(command, info) && info->return_status == 0)
        info->return_status = 0;
    if (path == NULL)
        return;
    path += 5;
    array = my_strtok(path, ":");
    for (int i = 0; array[i]; i++)
        find = find_file_in_folder(array[i], command, find);
    if (find == true && info->return_status == 0)
        return;
    info->return_status = 1;
}

static void boucle_where(envp_info_t *info, char **array, bool *error)
{
    info->return_status = 0;
    for (int i = 1; array[i]; i++) {
        if (is_slash(array[i])) {
            my_putstr("where: / in command makes no sense\n");
            *error = true;
            continue;
        }
        if ((is_buildin(array[i]) || my_strcmp(array[i], "echo") == 0)
        && my_strcmp(array[i], "env") != 0) {
            my_putstr(array[i]);
            my_putstr(" is a shell built-in\n");
        }
        array[i] = remove_quotes(array[i]);
        find_all_folder(info, array[i]);
    }
}

bool handle_where(envp_info_t *info, char *str)
{
    char **array = NULL;
    bool error = false;

    if (my_strncmp(str, "where", 5) != 0)
        return false;
    info->status = 1;
    array = str_to_word_array(str, " ");
    if (array == NULL || handle_error_where(info, array) || array[1] == NULL) {
        info->return_status = 1;
        return true;
    }
    boucle_where(info, array, &error);
    if (error == true)
        info->return_status = 1;
    return true;
}
