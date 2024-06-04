/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** that file permit to compare two str
*/
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strcmp(char *s1, char *s2)
{
    int j = 0;

    for (; ((s1[j] == s2[j]) && (s1[j] != '\0') && (s2[j] != '\0'));)
        j++;
    return (s1[j] - s2[j]);
}

int my_strncmp(char *s1, char *s2, int n)
{
    if (n > my_strlen(s1) || n > my_strlen(s2))
        return my_strcmp(s1, s2);
    for (int j = 0; s1[j] != '\0' && s2[j] != '\0' && j < n; j++) {
        if (s1[j] != s2[j])
            return -1;
    }
    return 0;
}

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *alloc = malloc(sizeof(char) * (size + 1));
    int compt = 0;

    while (compt < size) {
        alloc[compt] = src[compt];
        compt++;
    }
    alloc[compt] = '\0';
    return alloc;
}
