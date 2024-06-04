/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/
#include "my.h"

int max_value(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return 0;
}

int my_put_nbr(int nb)
{
    int i;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        i = nb % 10;
        if (nb > 9) {
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar('0' + i);
        } else {
            my_putchar(nb + '0');
        }
    } else {
        max_value();
    }
    return 0;
}
