/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putsterr(char const *str)
{
    write(2, str, my_strlen(str));
}

int nb_of_slash(char *str)
{
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            k++;
    }
    return k;
}

int nb_of_char(char *str, char c)
{
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            k++;
    }
    return k;
}
