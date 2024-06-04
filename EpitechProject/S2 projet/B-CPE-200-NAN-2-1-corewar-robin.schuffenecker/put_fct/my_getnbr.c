/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** trouver les chiffres
*/

#include "my.h"

static int cond(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            j++;
        }
        i++;
    }
    if (j > 10) {
        return 1;
    } else {
        return 0;
    }
}

static int is_nbr(char a)
{
    if ((a >= '0') && (a <= '9')) {
        return 1;
    } else {
        return 0;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = cond(str);
    int neg = 0;

    if (result == 1)
        return 0;
    while (is_nbr(str[i]) != 1) {
        if ((str[i] == '-') && (is_nbr(str[i + 1]) == 1)) {
            neg = -1;
        }
        i++;
    }
    while (is_nbr(str[i]) == 1) {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    if (neg == -1)
        result = result * neg;
    return result;
}
