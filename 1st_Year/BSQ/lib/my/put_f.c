/*
** EPITECH PROJECT, 2023
** put_i_d
** File description:
** Print a float or double
*/
#include "my.h"

int put_f(const char *format, va_list args, int i)
{
    if (format[i] == 'f' || format[i] == 'F') {
        my_put_float_nbr(va_arg(args, double));
        i++;
    }
    return 0;
}
