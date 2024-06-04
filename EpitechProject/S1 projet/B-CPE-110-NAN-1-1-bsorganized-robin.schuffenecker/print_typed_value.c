/*
** EPITECH PROJECT, 2023
** print
** File description:
** print
*/

#include "include/bootstrap.h"
#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int print_typed_value(void *data, type_t type)
{
    int nb = 0;
    player_t test;

    if (type == CHAR) {
        write(1, data, 1);
        my_putstr("\n");
    }
    if (type == STRING) {
        write(1, data, my_strlen(data));
    }
    if (type == INTEGER) {
        nb = *(int*)data;
        my_put_nbr(nb);
        my_putstr("\n");
    }
    if (type == PLAYER) {
        test = *(player_t*)data;
        my_putstr("\n");
        my_putstr(test.name);
        my_putstr(": lvl.");
        my_put_nbr(test.lvl);
        my_putstr("\n");
    }
}
