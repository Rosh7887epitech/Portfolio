/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** put string automaticly
*/
#include "../include/my_project.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    if (str == NULL)
        my_putstr("null pointeur (normaly segfault)\n");
    else
        write(1, str, my_strlen(str));
    return;
}
