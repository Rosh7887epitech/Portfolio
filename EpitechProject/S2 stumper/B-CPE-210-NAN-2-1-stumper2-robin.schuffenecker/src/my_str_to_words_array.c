/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** split string and supp spaces
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

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

int count(char *str, char sep)
{
    int a = 0;
    int count = 0;

    while (str[a] != '\0') {
        if (sep == str[a]) {
            count++;
        }
        a++;
    }
    return count;
}

int len(char *str, int i, char sep)
{
    int length = 0;

    while (str[i] != '\0' && str[i] != sep) {
        length++;
        i++;
    }
    return length;
}

char **my_str_to_word_array(char *str, char sep)
{
    int y = count(str, sep) + 1;
    char **array = malloc(sizeof(char *) * (y + 1));
    int a = 0;
    int b = 0;
    int c = 0;
    int lenght = 0;

    while (b < y) {
        lenght = len(str, a, sep);
        array[b] = malloc(sizeof(char) * (lenght + 1));
        for (c = 0; str[a] != '\0' && sep != str[a]; c++) {
            array[b][c] = str[a];
            a++;
        }
        array[b][c] = '\0';
        a++;
        b++;
    }
    array[b] = NULL;
    return array;
}
