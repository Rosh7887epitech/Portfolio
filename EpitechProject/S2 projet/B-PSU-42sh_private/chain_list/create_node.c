/*
** EPITECH PROJECT, 2023
** create_node.c
** File description:
** that function should create a new node
*/
#include "../include/my_project.h"
#include <stdlib.h>

path_t *create_node(char *value)
{
    path_t *cell = malloc(sizeof(path_t));

    cell->value = my_strdup(value);
    cell->next = NULL;
    return cell;
}
