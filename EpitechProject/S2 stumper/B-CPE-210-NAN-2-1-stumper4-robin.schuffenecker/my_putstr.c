/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays,
** one-by-one, the characters of a string.
*/

#include "include/my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
