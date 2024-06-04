/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** Write a function that copies n characters from a string into another.
** The destination string will already
** have enough memory to contain n characters.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n <= i) {
        return (0);
    }
    while (i < n && i < my_strlen(dest)) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
