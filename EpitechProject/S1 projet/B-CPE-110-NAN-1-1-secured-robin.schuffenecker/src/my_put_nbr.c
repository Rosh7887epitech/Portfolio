/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../include/hashtable.h"

char *my_put_nbr(int nb)
{
    char *nombre = my_itoa(nb);

    my_putstr(nombre);
    return nombre;
}
