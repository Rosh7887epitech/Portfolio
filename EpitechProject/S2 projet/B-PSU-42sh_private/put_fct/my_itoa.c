/*
** EPITECH PROJECT, 2023
** int_to_str.c
** File description:
** that function should take an integer as parameter and return an str
*/

#include "../include/my_project.h"
#include <stdlib.h>

static int my_intlen(int integer)
{
    int long_int = 0;

    if (integer < 0)
        integer *= -1;
    while (integer != 0) {
        integer /= 10;
        long_int++;
    }
    return long_int;
}

static char *my_negitoa(char *str)
{
    char *neg_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(neg_str, "-");
    return my_strcat(neg_str, str);
}

char *my_itoa(int score)
{
    char *str;
    int integer = score;
    int long_int = my_intlen(integer);
    int tmp_score = score;

    if (score == 0) {
        str = my_strdup("0");
        return str;
    }
    if (tmp_score < 0)
        score *= -1;
    str = malloc(sizeof(char) * (long_int + 1));
    for (int i = 0; i <= long_int; i++) {
        str[long_int - i - 1] = (score % 10) + '0';
        score = score / 10;
    }
    str[long_int] = '\0';
    if (tmp_score < 0)
        return my_negitoa(str);
    return str;
}
