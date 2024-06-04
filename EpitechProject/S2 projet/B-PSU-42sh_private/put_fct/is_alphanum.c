/*
** EPITECH PROJECT, 2024
** is_alphanum.c
** File description:
** that function should return 0 if str only contain alphanum char
** and 1 otherwise
*/
#include <stdlib.h>
#include <stdbool.h>

int is_charalphanum(char str)
{
    if ((str >= '0' && str <= '9') ||
    (str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
        return 0;
    return 1;
}

int is_alphanum(char *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9')
        && (str[i] < 'a' || str[i] > 'z')
        && (str[i] < 'A' || str[i] > 'Z'))
            return 1;
    }
    return 0;
}

bool is_char_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}
