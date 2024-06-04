/*
** EPITECH PROJECT, 2024
** my_strtok.c
** File description:
** that function should make the strtok function
*/

#include "my_project.h"
#include <string.h>
#include <stdlib.h>

char **my_strtok(char const *str, char *delimiter)
{
    char *cpy_str = my_strdup(str);
    int size = 0;
    char **tab = NULL;
    char *token = strtok(cpy_str, delimiter);

    while (token != NULL) {
        size++;
        token = strtok(NULL, delimiter);
    }
    free(token);
    tab = malloc(sizeof(char *) * (size + 1));
    free(cpy_str);
    cpy_str = my_strdup(str);
    token = strtok(cpy_str, delimiter);
    for (int i = 0; token != NULL && i < size; i++) {
        tab[i] = my_strdup(token);
        token = strtok(NULL, delimiter);
    }
    tab[size] = NULL;
    return tab;
}
