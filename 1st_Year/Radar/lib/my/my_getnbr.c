/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** trouver les chiffres
*/

#include "my.h"

int is_nbr(char a)
{
    return (a >= '0' && a <= '9');
}

int search(int *number, char *str, int count, int nb)
{
    int neg = 0;

    for (int i = 0; str[i] != '\0';) {
        while (str[i] && !is_nbr(str[i]) && str[i] != '-')
            i++;
        if (str[i] == '\n')
            break;
        nb = 0;
        neg = (str[i] == '-') ? -1 : 1;
        if (neg == -1)
            i++;
        while (is_nbr(str[i])) {
            nb = nb * 10 + (str[i] - '0');
            i++;
        }
        number[count] = nb * neg;
        count++;
    }
    return count;
}

int *my_getnbr(char *str, int *size)
{
    int *number = malloc(sizeof(int) * 100);
    int count = 0;
    int nb = 0;

    count = search(number, str, count, nb);
    *size = count;
    return number;
}
