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
#include "include/my.h"
#include <dirent.h>
#include <stdio.h>

void put_list(list *l)
{
    while (l != NULL) {
        my_printf("%i\n", l->var_ucd);
        l = l->next;
    }
}
