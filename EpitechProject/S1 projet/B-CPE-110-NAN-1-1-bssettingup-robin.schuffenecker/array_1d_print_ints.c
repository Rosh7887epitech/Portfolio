/*
** EPITECH PROJECT, 2023
** array_1d_print_ints
** File description:
** display int tab 1 per 1
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        my_putchar(str[i]);
        i = i + 1;
    }
}

static int my_put_nbr(int nb)
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

void array_1d_print_ints(int const *arr, int size)
{
    int array_nb = 0;

    for (int i = 0; i < size; i++) {
        array_nb = arr[i];
        my_put_nbr(array_nb);
        write(1, "\n", 1);
    }
}
