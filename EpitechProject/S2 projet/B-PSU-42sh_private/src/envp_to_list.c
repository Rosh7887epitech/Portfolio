/*
** EPITECH PROJECT, 2024
** envp_to_list.c
** File description:
** that function should return the linked list of the envp
*/

#include "../include/my_project.h"
#include <stdlib.h>

static char **cpy_w_delete(path_t *list, char *value, char **array)
{
    int index = 0;

    for (; list != NULL; list = list->next) {
        if (my_strncmp(list->value, value, my_strlen(value)) != 0) {
            array[index] = my_strdup(list->value);
            index++;
        }
    }
    array[index] = NULL;
    return array;
}

path_t *envp_to_list(char **envp)
{
    path_t *list = NULL;

    if (!envp)
        return list;
    for (int i = 0; envp[i] != NULL; i++)
        add_end(&list, envp[i]);
    return list;
}

char **list_to_array(path_t *list, char *value)
{
    int lenght = lenght_list(list);
    char **array = malloc(sizeof(char *) * (lenght + 1));
    int index = 0;

    if (array == NULL)
        return NULL;
    if (value != NULL) {
        return cpy_w_delete(list, value, array);
    } else {
        for (; list != NULL; list = list->next) {
            array[index] = my_strdup(list->value);
            index++;
        }
        array[index] = NULL;
        return array;
    }
}
