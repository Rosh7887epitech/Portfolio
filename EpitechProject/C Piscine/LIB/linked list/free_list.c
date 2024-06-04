/*
** EPITECH PROJECT, 2023
** free_list
** File description:
** free_list
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "include/ls.h"
#include <dirent.h>
#include <stdio.h>

list *free_list(list *l)
{
    list *tmp = l;

    while (l) {
        tmp = l - tmp->next;
        free(l);
        l = tmp;
    }
    return l;
}
