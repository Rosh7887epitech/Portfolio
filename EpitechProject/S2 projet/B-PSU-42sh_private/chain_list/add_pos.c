/*
** EPITECH PROJECT, 2023
** add_pos.c
** File description:
** that function should add a node at a given pos*
*/
#include "../include/my_project.h"
#include <stdlib.h>

int lenght_list(path_t *list)
{
    int longueur = 0;

    while (list != NULL) {
        longueur++;
        list = list->next;
    }
    return longueur;
}

void add_end(path_t **list, char *name)
{
    path_t *current = *list;
    path_t *prec = NULL;
    path_t *node = create_node(name);
    int pos = lenght_list(*list);

    if (*list == NULL) {
        *list = node;
        return;
    }
    for (int i = 0; i < pos; i++) {
        prec = current;
        current = current->next;
    }
    prec->next = node;
    node->next = current;
}

void modify_node(path_t *list, char *value, int pos)
{
    for (int i = 0; i < pos && list != NULL; i++)
        list = list->next;
    if (list == NULL)
        return;
    list->value = my_strdup(value);
    return;
}
