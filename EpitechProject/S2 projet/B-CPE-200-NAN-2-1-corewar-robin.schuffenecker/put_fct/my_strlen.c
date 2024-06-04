/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function that counts and returns the number of
** characters found in the string passed as parameter.
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

int my_char_isalphanum(char str)
{
    if ((str >= 'A' && str <= 'Z') ||
        (str >= 'a' && str <= 'z')) {
        return 0;
    } else {
        return 1;
    }
}

int my_str_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
                continue;
        } else {
            return 1;
        }
    }
    return 0;
}

int my_str_num(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if ((str[i] >= '0' && str[i] <= '9')) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}
