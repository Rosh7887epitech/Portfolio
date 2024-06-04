/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function that counts and returns the number of
** characters found in the string passed as parameter.
*/

#include "boggle.h"
#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL) {
        return -1;
    }
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
