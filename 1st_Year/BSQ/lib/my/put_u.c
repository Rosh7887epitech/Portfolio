/*
** EPITECH PROJECT, 2023
** put_udi
** File description:
** put unsigned int
*/

#include "my.h"
#include <stdarg.h>

int put_u(const char *format, va_list args, int i)
{
    if (format[i] == 'u') {
        my_put_unsigned_nbr(va_arg(args, unsigned int));
        i++;
    }
    return 0;
}
