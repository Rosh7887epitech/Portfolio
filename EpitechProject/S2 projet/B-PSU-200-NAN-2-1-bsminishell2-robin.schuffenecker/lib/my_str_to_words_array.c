/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** split string and supp spaces
*/

#include "my.h"

int is_char(char c, int status)
{
    if (status == 1) {
        if (c >= 33 && c <= 126)
            return 1;
    }
    if (status == 2) {
        if (c >= 33 && c <= 126 && c != 58)
            return 1;
    }
    return 0;
}

int count(char *str)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        if (is_char(str[a], 1) == 1 && is_char(str[a + 1], 1) != 1){
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

int len(char *str, int i)
{
    while (str[i] != '\0') {
            if (is_char(str[i], 1) != 1)
                    return (i);
            i++;
    }
    return (i);
}

char **my_str_to_word_array(char *str)
{
    int y = count(str);
    char **array = malloc(sizeof(char *) * y + 1);
    int a = 0;
    int b = 0;
    int c = 0;

    while (b < y){
        c = 0;
        array[b] = malloc(sizeof(char) * len(str, a));
        while (str[a] != '\0' && is_char(str[a], 1) != 0) {
            array[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        array[b][c] = '\0';
        a = a + 1;
        b = b + 1;
    }
    return (array);
}
