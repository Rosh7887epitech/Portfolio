/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** This function is not done
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int lsrc = my_strlen(src);
    int ldest = my_strlen(dest);

    if (n <= i) {
        return (0);
    }
    while (i < n && i < ldest + lsrc) {
        dest[ldest + i] = src[i];
        i++;
    }
    dest[ldest + lsrc] = '\0';
    return (dest);
}
