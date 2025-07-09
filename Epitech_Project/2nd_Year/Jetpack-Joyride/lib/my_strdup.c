/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** that function duplicate a string
** into a other one create by this function
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *alloc = malloc(sizeof(char) * (size + 1));
    int compt = 0;

    if (alloc == NULL || size == 0 || src == NULL)
        return NULL;
    while (compt < size) {
        alloc[compt] = src[compt];
        compt++;
    }
    alloc[compt] = '\0';
    return alloc;
}
