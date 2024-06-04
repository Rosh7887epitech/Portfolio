/*
** EPITECH PROJECT, 2024
** free_pos.c
** File description:
** that function should free a node at a given pos
*/
#include "../include/my_project.h"
#include <stdlib.h>

path_t *free_pos(path_t *list, char *value)
{
    char **array = NULL;

    if (list == NULL || value == NULL)
        return list;
    array = list_to_array(list, value);
    if (!array)
        return 0;
    list = envp_to_list(array);
    return list;
}
