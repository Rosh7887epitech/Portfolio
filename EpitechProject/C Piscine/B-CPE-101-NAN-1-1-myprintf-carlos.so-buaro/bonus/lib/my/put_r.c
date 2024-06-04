/*
** EPITECH PROJECT, 2023
** put_r
** File description:
** put all int in luffy base
*/

#include "my.h"
#include <stdarg.h>

int put_r(const char *format, va_list args, int i)
{
    char *b_r = "baluffy";

    if (format[i] == 'r') {
        convertion((va_arg(args, int)), b_r);
        i++;
    }
}