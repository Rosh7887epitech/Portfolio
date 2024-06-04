/*
** EPITECH PROJECT, 2024
** free_array.c
** File description:
** that function should free an array
*/
#include <stdlib.h>

void free_array(char **array)
{
    int index = 0;

    if (!array)
        return;
    for (; array[index] != NULL; index++)
        free(array[index]);
    free(array);
    return;
}
