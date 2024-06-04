/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** first part mini_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "include/mprintf.h"

static int mini_printf_special_flag(const char *format, int i)
{
    if (format[i] == '%') {
        my_putchar('%');
        i++;
    }
    return (0);
}

static int mini_printf_basic_flag(const char *format, va_list args, int i)
{
    if (format[i] == 'c') {
        my_putchar(va_arg(args, int));
        i++;
    }
    if (format[i] == 's') {
        my_putstr(va_arg(args, char *));
        i++;
    }
    if (format[i] == 'i' || format[i] == 'd') {
        my_put_nbr(va_arg(args, int));
        i++;
    }
    return (i);
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int length = my_strlen(format);

    va_start(args, format);
    for (int i = 0; i < length; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else {
            i++;
            mini_printf_basic_flag(format, args, i);
            mini_printf_special_flag(format, i);
        }
        va_end(args);
    }
    return (0);
}
