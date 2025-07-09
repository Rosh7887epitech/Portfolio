/*
** EPITECH PROJECT, 2025
** my_strcat.c
** File description:
** that function should concate two str
*/
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int len_src = 0;
    char *destination = NULL;

    if (dest == NULL && src == NULL)
        return destination;
    if (dest != NULL && src != NULL) {
        len_src = my_strlen(src) + 1;
        destination = malloc(sizeof(char) * (my_strlen(dest) + len_src));
        if (destination == NULL)
            return NULL;
        my_strcpy(destination, dest);
        my_strcpy(destination + my_strlen(dest), src);
        free(dest);
        return destination;
    }
    if (dest == NULL)
        return my_strdup(src);
    if (src == NULL)
        return my_strdup(dest);
    return destination;
}
