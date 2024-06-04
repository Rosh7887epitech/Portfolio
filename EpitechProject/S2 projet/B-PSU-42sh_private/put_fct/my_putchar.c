/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** put a char in a terminal
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
