/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** that function compare two string and return 0 if is the same
*/
#include "my_project.h"
#include <stdlib.h>

int my_strcmp(char *s1, char *s2)
{
    int j = 0;

    if (s1 == NULL || s2 == NULL)
        return -1;
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
