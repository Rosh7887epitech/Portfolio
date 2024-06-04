/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include "boggle.h"
#include <unistd.h>

char *my_putstr(char *str)
{
    if (str == NULL) {
        return NULL;
    }
    write(1, str, my_strlen(str));
}
