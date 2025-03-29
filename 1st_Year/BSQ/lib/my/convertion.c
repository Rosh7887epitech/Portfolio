/*
** EPITECH PROJECT, 2023
** Convertion
** File description:
** Return a convert value
*/
#include <unistd.h>
#include "my.h"

static unsigned int rec_convertion(int len, long int nb, char *base)
{
    if (nb > len) {
            convertion(nb / len, base);
            my_putchar(base[nb % len]);
        } else {
            convertion(nb / len, base);
            my_putchar(base[nb]);
        }
        return 0;
}

unsigned int convertion(long int nb, char *base)
{
    int len = my_strlen(base);
    unsigned int result = 0;

    if (nb == len) {
        convertion(nb / len, base);
        my_putchar('0');
        return result;
    }
    if (nb == 0) {
        return result;
        my_putchar('0');
    } else {
        rec_convertion(len, nb, base);
    }
    return 0;
}
