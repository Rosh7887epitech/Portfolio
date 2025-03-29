/*
** EPITECH PROJECT, 2023
** put_p
** File description:
** Print Adress of any type
*/
#include "my.h"

void *put_p(const char *format, va_list args, int i)
{
    char *base = "0123456789abcdef";
    void *value = va_arg(args, void *);

    my_putstr("0x");
    convertion((long int) value, base);
    i++;
    return 0;
}
