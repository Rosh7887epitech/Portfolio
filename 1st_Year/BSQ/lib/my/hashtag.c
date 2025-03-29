/*
** EPITECH PROJECT, 2023
** hashtag
** File description:
** put 0 or 0x or 0X behind o,x,X
*/

#include "my.h"
#include <stdarg.h>

static int hashtag_oct(const char *format, va_list args, int i)
{
    if (format[i + 1] == 'o') {
        if (format[i] == '#') {
            my_putchar('0');
            i++;
            put_octal(format, args, i);
            i++;
        }
    }
    return i;
}

static int hashtag_hexa_upper(const char *format, va_list args, int i)
{
    if (format[i + 1] == 'X') {
        if (format[i] == '#') {
            my_putstr("0X");
            i++;
            put_hexa_upper(format, args, i);
            i++;
        }
    }
    return i;
}

static int hashtag_hexa(const char *format, va_list args, int i)
{
    if (format[i + 1] == 'x') {
        if (format[i] == '#') {
            my_putstr("0x");
            i++;
            put_hexa(format, args, i);
            i++;
        }
    }
    return i;
}

int hashtag(const char *format, va_list args, int i)
{
    hashtag_hexa(format, args, i);
    hashtag_hexa_upper(format, args, i);
    hashtag_oct(format, args, i);
}
