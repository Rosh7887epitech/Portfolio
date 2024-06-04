/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** split string and supp spaces
*/

#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char **my_str_to_word_tok(char *str, char *sep)
{
    int count = 0;
    char *temp = NULL;
    char **array = NULL;
    char *base_str = NULL;

    base_str = my_strdup(str);
    temp = strtok(base_str, sep);
    while (temp != NULL) {
        count++;
        temp = strtok(NULL, sep);
    }
    array = malloc(sizeof(char *) * (count + 1));
    temp = strtok(str, sep);
    for (int i = 0; i < count; i++) {
        array[i] = my_strdup(temp);
        temp = strtok(NULL, sep);
    }
    array[count] = NULL;
    return array;
}
