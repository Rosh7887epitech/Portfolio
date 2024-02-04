/*
** EPITECH PROJECT, 2023
** put_i_d
** File description:
** put all integer
*/

#include "my.h"
#include <stdarg.h>

int put_i_d(const char *format, va_list args, int i)
{
    if (format[i] == 'i' || format[i] == 'd') {
        my_put_nbr(va_arg(args, int));
        i++;
    }
    return 0;
}
