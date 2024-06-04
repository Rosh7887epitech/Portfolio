/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL) {
        my_putstr("NULL");
        return 0;
    }
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}
