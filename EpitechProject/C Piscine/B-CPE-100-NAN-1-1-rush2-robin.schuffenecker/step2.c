/*
** EPITECH PROJECT, 2023
** step2.c
** File description:
** step2
*/

#include "my.h"

static int letter(char c)
{
    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
        return (1);
    } else {
        return (0);
    }
}

void my_putmonchar(char **argv, int f, int k)
{
            my_putchar(argv[f][0]);
            my_putchar(':');
            my_put_nbr(k);
            my_putchar('\n');
}

int main(int argc, char **argv)
{
    int i = 0;
    int f = 2;
    int k = 0;

    while (argc > f) {
        k = 0;
        while (argv[1][i] != '\0') {
            if ((letter(argv[1][i]) == 1) && ((argv[1][i] == argv[f][0])
            || (argv[1][i] == argv[f][0] + 32) ||
            (argv[1][i] == argv[f][0] - 32))) {
                k++;
                i++;
            } else
                i++;
        }
        my_putmonchar(argv, f, k);
        i = 0;
        f++;
    }
    return 1;
}
