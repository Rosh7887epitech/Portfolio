/*
** EPITECH PROJECT, 2024
** kill
** File description:
** kill
*/

#include "../include/navy.h"

int kill_it(char const **argv)
{
    int pid = my_getnbr(argv[1]);

    kill(pid, 3);
    my_putstr("successful killed");
    return 0;
}