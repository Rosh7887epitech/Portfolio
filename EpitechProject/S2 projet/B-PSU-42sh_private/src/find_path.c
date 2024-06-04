/*
** EPITECH PROJECT, 2024
** find_path.c
** File description:
** that function should search and return where an given fct is in a path
*/
#include "../include/my_project.h"
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>

static char *extract_path(path_t *list)
{
    while (list) {
        if (my_strncmp(list->value, "PATH=", 5) == 0)
            return my_strdup(list->value);
        list = list->next;
    }
    return NULL;
}

static char *find_filepath(char *filepath, char *function)
{
    DIR *dir = opendir(filepath);
    struct dirent *entry = NULL;

    if (dir == NULL)
        return NULL;
    entry = readdir(dir);
    while (entry != NULL) {
        if (my_strcmp(entry->d_name, function) == 0) {
            closedir(dir);
            return my_strdup(filepath);
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return NULL;
}

char *find_path(path_t *list, char *function)
{
    char **args = NULL;
    char *filed = NULL;

    if (list == NULL)
        return NULL;
    filed = extract_path(list);
    if (filed == NULL)
        return NULL;
    args = my_strtok(filed + 5, ":");
    for (int i = 0; args[i] != NULL; i++) {
        free(filed);
        filed = find_filepath(args[i], function);
        if (filed != NULL) {
            return filed;
        }
    }
    return NULL;
}

bool is_slash(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i] != '\0' && str[i] != ' '; i++) {
        if (str[i] == '/')
            return true;
    }
    return false;
}
