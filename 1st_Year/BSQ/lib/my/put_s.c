/*
** EPITECH PROJECT, 2023
** put_s
** File description:
** put all string
*/

#include "my.h"
#include <stdarg.h>

int put_s(const char *format, va_list args, int i)
{
    if (format[i] == 's') {
        my_putstr(va_arg(args, char *));
        i++;
    }
    return 0;
}
