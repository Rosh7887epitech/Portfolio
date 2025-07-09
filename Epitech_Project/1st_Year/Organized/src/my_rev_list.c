/*
** EPITECH PROJECT, 2023
** my_rev_list
** File description:
** rev list
*/

#include "../shell/shell.h"
#include "../include/org.h"

list *my_rev_list(list **first)
{
    list *prev = NULL;
    list *current = *first;
    list *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *first = prev;
    return *first;
}
