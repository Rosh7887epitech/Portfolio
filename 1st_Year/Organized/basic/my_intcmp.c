/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** stcmp
*/

#include "../include/org.h"
#include "../shell/shell.h"

int my_intcmp(int i1, int i2)
{
    int k = 0;

    k = i1 - i2;
    if (k < 0)
        return -1;
    if (k > 0)
        return 1;
    if (k == 0)
        return 0;
}
