/*
** EPITECH PROJECT, 2024
** dup
** File description:
** env
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char **mem_dup_2d_array(char **arr)
{
    int nb_rows = 0;
    char **dup;

    while (arr[nb_rows] != NULL) {
        nb_rows++;
    }
    dup = malloc(sizeof(char *) * (nb_rows + 1));
    if (dup == NULL)
        return NULL;
    for (int i = 0; i < nb_rows; i++) {
        dup[i] = malloc(strlen(arr[i]) + 1);
        if (dup[i] == NULL) {
            return NULL;
        }
        my_strcpy(dup[i], arr[i]);
    }
    dup[nb_rows] = NULL;
    return dup;
}
