/*
** EPITECH PROJECT, 2023
** concat_params
** File description:
** Write a function that turns the command-line
** given arguments into a single string.
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int i = 0;
    char *dest = 0;
    int lenfinal = 0;

    while (i < argc) {
        lenfinal = lenfinal + my_strlen(argv[i]);
        i++;
    }
    dest = malloc(sizeof(char) * lenfinal);
    i = 0;
    while ( i < argc) {
        my_strcat(dest, argv[i]);
        my_strcat(dest, "\n");
        i++;
    }
    return (dest);
}
