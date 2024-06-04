/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Write a function that copies a string into another.
** The destination string will already have enough memory
** to copy the source string.
*/

#include "../include/my_project.h"

char *my_strcpy(char *dest, char const *src)
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
