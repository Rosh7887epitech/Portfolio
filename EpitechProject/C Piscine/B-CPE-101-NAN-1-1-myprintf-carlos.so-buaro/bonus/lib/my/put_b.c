/*
** EPITECH PROJECT, 2023
** put_bin
** File description:
** put all int in bin base
*/

#include "my.h"
#include <stdarg.h>

int put_b(const char *format, va_list args, int i)
{
    char *b_bin = "01";

    if (format[i] == 'b') {
        convertion((va_arg(args, int)), b_bin);
        i++;
    }
}
