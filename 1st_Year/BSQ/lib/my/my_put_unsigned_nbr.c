/*
** EPITECH PROJECT, 2023
** put_unsigned_nbr
** File description:
** put unsigned nbr
*/
#include "my.h"

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    int i = nb % 10;

    if (nb > 9) {
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar('0' + i);
    } else {
        my_putchar(nb + '0');
    }
    return 0;
}
