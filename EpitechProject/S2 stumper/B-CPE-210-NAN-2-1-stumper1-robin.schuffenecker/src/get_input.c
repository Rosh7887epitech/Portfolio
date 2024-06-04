/*
** EPITECH PROJECT, 2024
** boggle
** File description:
** get input and display grid
*/

#include "boggle.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *get_input(void)
{
    size_t bufsize = 0;
    char *input = NULL;
    int read = getline(&input, &bufsize, stdin);

    if (read < 0) {
        return NULL;
    }
    input[read - 1] = '\0';
    return input;
}

void display_boggle(infos_t *infos)
{
    for (int j = 0; j < (infos->size + 4 + (infos->size - 1)); j++) {
        my_putchar('+');
    }
    my_putchar('\n');
    for (int i = 0; i < infos->size; i++) {
        my_putstr("| ");
        for (int k = 0; infos->grid[i][k] != '\0'; k++) {
            my_putchar(infos->grid[i][k]);
            my_putchar(' ');
        }
        my_putstr("|\n");
    }
    for (int f = 0; f < (infos->size + 4 + (infos->size - 1)); f++) {
        my_putchar('+');
    }
    my_putchar('\n');
}

int main_loop(int ac, char **av, infos_t *infos)
{
    char *input = NULL;

    display_boggle(infos);
    while (1) {
        my_putstr("> ");
        input = get_input();
        if (input == NULL) {
            return 1;
        }
        if (strcmp(input, "") == 0) {
            continue;
        }
        infos->word = input;
        if (find_word(infos) == 1) {
            return 1;
        }
    }
    return 0;
}
