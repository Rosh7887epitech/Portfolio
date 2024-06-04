/*
** EPITECH PROJECT, 2023
** mem_alloc
** File description:
** alloc mem for 2 array
*/

#include <stdio.h>
#include <stdlib.h>

static char *my_strncat(char *dest, char const *src, int n)
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

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        i++;
    }
    return (i);
}

char *mem_alloc(char const *a, char const *b)
{
    int l_a = my_strlen(a);
    int l_b = my_strlen(b);
    int size = l_a + l_b;
    char *str = malloc(sizeof(char)*size);

    my_strncat(str, a, l_a);
    my_strncat(str, b, l_b);
}