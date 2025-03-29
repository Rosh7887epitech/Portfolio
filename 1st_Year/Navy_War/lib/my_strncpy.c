/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** cpy str
*/

#include "my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (i < n) {
        if (i < my_strlen(src)) {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
        i++;
    }
    return (dest);
}
