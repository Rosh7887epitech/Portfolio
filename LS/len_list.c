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

int len_list(list *l)
{
    int k = 0;

    while (l) {
        l = l->next;
        k++;
    }
    return k;
}
