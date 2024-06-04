/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Write a function that counts and returns
** the number of characters found in the string
** passed as parameter. It must be prototyped as follows:
*/

#include "../include/my_project.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
