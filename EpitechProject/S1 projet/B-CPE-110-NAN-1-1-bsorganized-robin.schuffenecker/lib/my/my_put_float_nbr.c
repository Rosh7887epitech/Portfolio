/*
** EPITECH PROJECT, 2023
** my_put_float_nbr
** File description:
** Display a float number
*/
#include "my.h"
int aro(int i, int j)
{
    if (j >= 5)
        i++;
    return i;
}

double my_put_float_nbr(double nb)
{
    int i = 0;

    my_put_nbr((int) nb);
    my_putchar('.');
    nb -= (int) nb;
    for (int j = 0; j != 6; j++) {
        nb *= 10;
        i = i * 10 + (int) nb;
        if (i == 0)
            my_putchar('0');
        nb -= (int) nb;
    }
    i = aro(i, i % 10);
    my_put_nbr(i);
    return 0;
}
