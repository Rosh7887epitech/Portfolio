/*
** EPITECH PROJECT, 2023
** mem_dup_2d_array
** File description:
** mem_dup_2d_array
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}


int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        i++;
    }
    return (i);
}

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **dup = malloc(sizeof(char*) * nb_rows);

    for (int i = 0; i < nb_rows; i++) {
        dup[i] = malloc(sizeof(char) * nb_cols);
        my_strcpy(dup[i], arr[i]);
    }
    return dup;
}