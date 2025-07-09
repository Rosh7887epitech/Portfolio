/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** that function compare two string and return 0 if is the same
*/
#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int j = 0;

    if (!s1 || !s2)
        return -1;
    for (; ((s1[j] == s2[j]) && (s1[j] != '\0') && (s2[j] != '\0'));)
        j++;
    return (s1[j] - s2[j]);
}
