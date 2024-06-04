/*
** EPITECH PROJECT, 2024
** redirection_quotes.c
** File description:
** that file should handle the clean of the redirection when redirect a command
*/
#include "my_project.h"

static char **remove_quotes_and_advance(char **array, int i)
{
    int index = 0;

    if (array[i + 1] != NULL
        && is_pos_in_quotes(array[i + 1], 0) != NO_QUOTES) {
        array[i + 1] = remove_quotes(array[i + 1]);
        array[i] = my_strcat(array[i], array[i + 1]);
        for (index = i + 1; array[index] != NULL; index++)
            array[index] = array[index + 1];
        array[index] = NULL;
        index = 0;
    }
    return array;
}

char **remove_quotes_before_list(char **array, char *del1, char *del2)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (strcmp(array[i], del1) == 0 || strcmp(array[i], del2) == 0) {
            array = remove_quotes_and_advance(array, i);
        }
    }
    return array;
}
