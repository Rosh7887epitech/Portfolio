/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** print a word
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
}
