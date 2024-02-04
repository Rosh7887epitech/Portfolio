/*
** EPITECH PROJECT, 2023
** my_rev_list
** File description:
** rev list
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
