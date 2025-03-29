/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Write a function that concatenates two string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int lsrc = my_strlen(src);
    int ldest = my_strlen(dest);

    while (i != lsrc) {
        dest[ldest + i] = src[i];
        i++;
    }
    dest[ldest + lsrc] = '\0';
    return (dest);
}
