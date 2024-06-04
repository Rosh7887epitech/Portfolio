/*
** EPITECH PROJECT, 2023
** My Get Number
** File description:
** this function convert a number from a string in an int
*/

#include "my.h"

int check_negative(char const *str, int number)
{
    int i2 = 0;

    while (str[i2] != '\0') {
        if (str[i2] == '-') {
            number = 0 - number;
            i2++;
        }
        i2++;
    }
    return (number);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + str[i] - 48;
        }
        i++;
    }
    number = check_negative(str, number);
    return (number);
}
