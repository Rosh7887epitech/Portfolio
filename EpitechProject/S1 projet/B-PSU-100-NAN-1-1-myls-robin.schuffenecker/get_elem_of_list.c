/*
** EPITECH PROJECT, 2023
** get elem
** File description:
** get elem
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

infos_st get_elem_of_list(list *l, int pos)
{
    if (is_empty(l))
        return *l->var_ucd;
    for (int i = 0; i != pos; i++) {
        if (l->next == NULL)
            return *l->var_ucd;
        l = l->next;
    }
    return *l->var_ucd;
}
