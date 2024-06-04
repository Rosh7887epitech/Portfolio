/*
** EPITECH PROJECT, 2024
** atoi
** File description:
** atoi
*/

#include "my.h"

int my_atoi(char *charnombre)
{
    int nombre = 0;
    int i = 0;

    while (charnombre[i] != '\0') {
        if (charnombre[i] >= '0' && charnombre[i] <= '9') {
            nombre = nombre * 10 + (charnombre[i] - '0');
            i = i + 1;
        } else {
            return (-1);
        }
    }
    return (nombre);
}

int my_atoi_one(char charnombre)
{
    int nombre = 0;
    int i = 0;

    if (charnombre >= '0' && charnombre <= '9') {
        nombre = nombre * 10 + (charnombre - '0');
        i = i + 1;
    } else {
        return (-1);
    }
    return (nombre);
}
