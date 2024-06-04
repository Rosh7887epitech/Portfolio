/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** function who take a nb as parameter and print this one
*/

#include "../include/my_project.h"

static void execute(int numb, int o, int p)
{
    for (int start = 1000000000; start >= 1; start /= 10) {
        p = numb / start;
        numb = numb % start;
        if (o == 8 && p != 0) {
            o = 9;
        }
        if (o == 9) {
            my_putchar(p + '0');
        }
    }
}

int my_put_nbr(int nb)
{
    int v = 0;
    int x = 8;

    if (nb == 0) {
        my_putchar('0');
        return nb;
    }
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    execute(nb, x, v);
    return nb;
}
