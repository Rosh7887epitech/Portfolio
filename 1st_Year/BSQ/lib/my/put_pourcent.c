/*
** EPITECH PROJECT, 2023
** put_pourcent
** File description:
** put an pourcent
*/

#include "my.h"
#include <stdarg.h>

int put_pourcent(const char *format, va_list args, int i)
{
    if (format[i] == '%') {
        my_putchar('%');
        i++;
    }
    return 0;
}
