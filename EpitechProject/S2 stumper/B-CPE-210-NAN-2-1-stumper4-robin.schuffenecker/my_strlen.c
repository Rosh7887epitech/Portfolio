/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function that counts and returns the number of
** characters found in the string passed as parameter.
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_str_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            str[i] == '.' || str[i] == '*' ||
            str[i] == '_') {
                continue;
        } else {
            return 1;
        }
    }
    return 0;
}

int nb_of_char(char *str, char c)
{
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            k++;
    }
}
