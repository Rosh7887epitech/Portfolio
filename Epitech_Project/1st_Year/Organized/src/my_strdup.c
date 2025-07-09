/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Write a function that allocates memory and
** copies the string given as argument in it.
*/

#include "../shell/shell.h"
#include "../include/org.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
