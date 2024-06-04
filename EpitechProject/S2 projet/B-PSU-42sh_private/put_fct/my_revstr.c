/*
** EPITECH PROJECT, 2023
** My revstr
** File description:
** this function reverses a string.
*/
#include "my_project.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    int inv = 0;
    int a;
    int arret = length / 2;

    while (length != arret) {
        length = length -1;
        a = str[length];
        str[length] = str[inv];
        str[inv] = a;
        inv = inv + 1;
        }
    return (str);
}
