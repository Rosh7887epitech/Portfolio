/*
** EPITECH PROJECT, 2024
** add_env.c
** File description:
** that function should add something to our env
*/

#include <stdlib.h>
#include "../include/my_project.h"

int search_list(path_t *list, char *value)
{
    int count = 0;

    if (list == NULL)
        return -1;
    while (list != NULL) {
        if (my_strncmp(value, list->value, my_strlen(value)) == 0)
            return count;
        count++;
        list = list->next;
    }
    return -1;
}

int modify_envp(path_t **list, char *value, char *name)
{
    int status = search_list(*list, value);

    if (status == -1) {
        if (name == NULL)
            add_end(list, my_strcat(value, "="));
        else
            add_end(list, my_strcat(value, my_strcat("=", name)));
        return 0;
    }
    if (name == NULL)
        modify_node(*list, my_strcat(value, "="), status);
    else
        modify_node(*list, my_strcat(value, my_strcat("=", name)), status);
    return 0;
}

int remove_envp(path_t **list, char *value)
{
    int status = 0;

    if (!*list || !value)
        return 0;
    status = search_list(*list, value);
    if (status == -1)
        return 0;
    *list = free_pos(*list, value);
    return 0;
}
