/*
** EPITECH PROJECT, 2023
** id sort
** File description:
** sort
*/

#include "../shell/shell.h"
#include "../include/org.h"

static int integration_id(list **start, list *new_node)
{
    list *current = *start;

    if (start == NULL || new_node == NULL)
        return 84;
    if (*start == NULL || my_intcmp((*start)->id, new_node->id) >= 0) {
        new_node->next = *start;
        *start = new_node;
    } else {
        while (current->next != NULL &&
        my_intcmp(current->next->id, new_node->id) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return 0;
}

int sort_id_rev(void *data, char **args)
{
    list **start = (list **)data;
    list *sorted = NULL;
    list *current = *start;
    list *next_node;

    if (*start == NULL)
        return 84;
    while (current != NULL) {
        next_node = current->next;
        integration_id(&sorted, current);
        current = next_node;
    }
    *start = sorted;
    *start = my_rev_list(start);
    return 0;
}

int sort_id(void *data, char **args)
{
    list **start = (list **)data;
    list *sorted = NULL;
    list *current = *start;
    list *next_node;

    if (*start == NULL)
        return 84;
    while (current != NULL) {
        next_node = current->next;
        integration_id(&sorted, current);
        current = next_node;
    }
    *start = sorted;
    return 0;
}
