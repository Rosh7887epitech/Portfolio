/*
** EPITECH PROJECT, 2023
** put list
** File description:
** put list for linked list
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "include/ls.h"
#include <stdio.h>

int del_list(void* l, int pos)
{
    list **dup = (list **)l;
    list *current = *dup;
    list *previous = NULL;
    list *temp;

    if (*dup == NULL) {
        return 84;
    }
    if (pos == 0) {
        temp = *dup;
        *dup = (*dup)->next;
        free(temp);
        return 0;
    }
    for (int count = 0; current != NULL && count != pos; count++) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return 84;
    }
    previous->next = current->next;
    free(current);
}