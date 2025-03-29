/*
** EPITECH PROJECT, 2024
** msg
** File description:
** msg
*/

#include "my.h"

int receive_sig(void)
{
    int x = 0;

    var_sig.u2 = 0;
    var_sig.u1 = 0;
    while (var_sig.u2 == 0)
        pause();
    x = var_sig.u1;
    return x;
}
