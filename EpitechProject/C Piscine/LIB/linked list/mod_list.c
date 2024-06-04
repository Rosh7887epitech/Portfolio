/*
** EPITECH PROJECT, 2023
** mod_list
** File description:
** mod_list
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "include/ls.h"
#include <dirent.h>
#include <stdio.h>

void mod_list(list *l, infos_st *p, int pos)
{
    int c = 0;

    if (is_empty(l)) {
        return;
    }
    while (i != pos) {
        if (l->next == NULL)
            return;
        i++;
    }
    l->p = p;
}
