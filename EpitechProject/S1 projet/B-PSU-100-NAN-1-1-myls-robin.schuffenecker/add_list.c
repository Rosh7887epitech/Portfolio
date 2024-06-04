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
#include "include/my.h"
#include <dirent.h>
#include <stdio.h>

list *node_creator(infos_st *p)
{
    list *node = malloc(sizeof(list));

    node->var_ucd = malloc(sizeof(infos_st));
    node->var_ucd->name = p->name;
    node->var_ucd->size = p->size;
    node->next = NULL;
    return node;
}

list *add_list(list *l, infos_st *p, int pos)
{
    list *prev = l;
    list *av = l;
    list *node = node_creator(p);

    if (is_empty(l)) {
        return node;
    }
    if (pos == 0) {
        node->next = l;
        return node;
    }
    for (int i = 0; i < pos; i++) {
        prev = av;
        av = av->next;
    }
    prev->next = node;
    node->next = av;
    return l;
}
