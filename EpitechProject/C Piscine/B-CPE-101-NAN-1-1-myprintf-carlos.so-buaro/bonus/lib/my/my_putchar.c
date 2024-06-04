/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** My_putchar
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}
