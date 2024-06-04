/*
** EPITECH PROJECT, 2023
** add_list
** File description:
** add list for link list
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "include/ls.h"
#include <dirent.h>
#include <stdio.h>

int add_list(void *l, int data)
{
    list *prev = l;
    list *av = l;
    list *node = malloc(sizeof(list));

    if (is_empty(l)) {
        return 84;
    }
    node->data = data;
    node->next = *(list **)l;
    *(list **)l = node;
    return 0;
}
