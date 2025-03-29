/*
** EPITECH PROJECT, 2023
** Put_hexa
** File description:
** Return a hexadeimal value
*/
#include "my.h"
#include <stdarg.h>

int put_hexa(const char *format, va_list args, int i)
{
    char *b_hexa = "0123456789abcdef";

    if (format[i] == 'x') {
        convertion(va_arg(args, unsigned int), b_hexa);
        i++;
    }
    return 0;
}
