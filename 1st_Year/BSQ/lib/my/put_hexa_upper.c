/*
** EPITECH PROJECT, 2023
** Put_hexa_X
** File description:
** Return a hexadeimal value upper
*/
#include "my.h"
#include <stdarg.h>

int put_hexa_upper(const char *format, va_list args, int i)
{
    char *b_hexa_X = "0123456789ABCDEF";

    if (format[i] == 'X') {
        convertion(va_arg(args, unsigned int), b_hexa_X);
        i++;
    }
    return 0;
}
