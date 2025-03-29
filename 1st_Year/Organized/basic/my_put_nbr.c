/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../shell/shell.h"
#include "../include/org.h"

int my_put_nbr(int nb)
{
    int i;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        i = nb % 10;
        if (nb < 10) {
            my_putchar(nb + '0');
        } else {
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar('0' + i);
        }
    } else {
        my_putstr("2147483648");
    }
    return 0;
}
