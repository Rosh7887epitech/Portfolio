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

int put_list(void *l)
{
    list *current = *(list **)l;

    while (current != NULL) {
        printf("%i -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
