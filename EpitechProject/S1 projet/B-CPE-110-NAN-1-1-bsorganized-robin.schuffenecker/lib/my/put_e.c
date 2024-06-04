/*
** EPITECH PROJECT, 2023
** put_e
** File description:
** Print an exposant
*/
#include "my.h"

static int zero(double nb, int exp)
{
    while ((int)nb == 0)
    {
        nb = nb * 10;
        exp++;
    }
    my_put_float_nbr(nb);
    my_putchar('e');
    my_put_nbr(exp * (-1));
    return 0;
}

static int check_exp(int exp)
{
    if (my_count_nbr(exp) == 1)
        my_putchar('0');
    return 0;
}

static int positiv(double nb, int exp)
{
    while (my_count_nbr(nb) != 1)
    {
        nb = nb / 10;
        exp++;
    }
    my_put_float_nbr(nb);
    my_putstr("e+");
    check_exp(exp);
    my_put_nbr(exp);
    return 0;
}

int put_e(const char *format, va_list args, int i)
{
    double nb = 0;
    int exp = 0;

    if (format[i] == 'e')
    {
        nb = va_arg(args, double);
        if ((int)nb == 0)
        {
            zero(nb, exp);
        }
        else
        {
            positiv(nb, exp);
        }
        i++;
    }
    return exp;
}
