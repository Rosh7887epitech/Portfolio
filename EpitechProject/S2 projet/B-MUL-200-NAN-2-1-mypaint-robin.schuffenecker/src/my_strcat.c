/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** that function concat two string
*/
#include "my_project.h"
#include <string.h>

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int b = 0;

    b = my_strlen(src);
    dest[b] = '\0';
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

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
