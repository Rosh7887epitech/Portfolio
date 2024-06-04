/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** my_putchar
*/

#include "../shell/shell.h"
#include "../include/org.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
