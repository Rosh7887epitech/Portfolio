/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** first part mini_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int (*int_fonc[15])(const char *format, va_list args, int i) = {put_c, put_s,
    put_i_d, put_f, put_e, put_pourcent, put_hexa, put_hexa_upper, put_octal,
    put_u, hashtag};

static int print_fonc(const char *format, va_list args, int i)
{
    for (int j = 0; j < 11; j++)
        int_fonc[j](format, args, i);
    if (format[i] == 'p')
        put_p(format, args, i);
}

int my_printf(const char *format, ...)
{
    va_list args;
    int length = my_strlen(format);

    va_start(args, format);
    for (int i = 0; i < length; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else {
            i++;
            print_fonc(format, args, i);
        }
        va_end(args);
    }
    return (0);
}
