/*
** EPITECH PROJECT, 2024
** correct_array.c
** File description:
** that file should handle the clean of a tab
*/
#include "my_project.h"

static char **skip_char_in_tab(char **array, int i)
{
    int index = 0;

    for (index = i; array[index + 1]; index++)
        array[index] = array[index + 1];
    array[index] = NULL;
    return array;
}

char **remove_useless_char_tab(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i][0] == '\0') {
            array = skip_char_in_tab(array, i);
        }
    }
    return array;
}
