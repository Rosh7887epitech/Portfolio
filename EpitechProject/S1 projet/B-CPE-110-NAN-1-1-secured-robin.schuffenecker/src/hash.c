/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/hashtable.h"

int hash(char *key)
{
    int value = 0;
    int p = 1;
    int len = my_strlen(key);

    if (key == NULL)
        return 1;
    for (int i = 0; i < len; ++i) {
        value = (value + (key[i] * p));
        p = (p * 3);
    }
    if (value < 0)
        value = value * -1;
    return value;
}
