/*
** EPITECH PROJECT, 2023
** put_c
** File description:
** put all character
*/

#include "my.h"
#include <stdarg.h>

int put_c(const char *format, va_list args, int i)
{
    if (format[i] == 'c') {
        my_putchar(va_arg(args, int));
        i++;
    }
    return 0;
}
