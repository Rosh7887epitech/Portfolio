/*
** EPITECH PROJECT, 2023
** my_count_nbr
** File description:
** my_count_nbr
*/
#include "my.h"

int my_count_nbr(int nb)
{
    int count = 1;

    while (nb / 10 != 0) {
        count++;
        nb = nb / 10;
    }
    return count;
}
