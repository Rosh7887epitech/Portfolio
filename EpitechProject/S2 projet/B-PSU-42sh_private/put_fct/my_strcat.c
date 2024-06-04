/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** that function should concate two str
*/
#include "../include/my_project.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int len_dest = 0;
    int len_src = 0;
    char *destination = NULL;

    if (dest == NULL && src == NULL)
        return destination;
    if (dest != NULL && src != NULL) {
        len_dest = my_strlen(dest);
        len_src = my_strlen(src) + 1;
        destination = malloc(sizeof(char) * (len_dest + len_src));
        my_strcpy(destination, dest);
        my_strcpy(destination + len_dest, src);
        return destination;
    }
    if (dest == NULL)
        return my_strdup(src);
    if (src == NULL)
        return my_strdup(dest);
    return destination;
}
