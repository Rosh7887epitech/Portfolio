/*
** EPITECH PROJECT, 2023
** put_octal
** File description:
** put all int in octal base
*/

#include "my.h"
#include <stdarg.h>

int put_octal(const char *format, va_list args, int i)
{
    char *b_oct = "01234567";

    if (format[i] == 'o') {
        convertion((va_arg(args, unsigned int)), b_oct);
        i++;
    }
    return 0;
}
