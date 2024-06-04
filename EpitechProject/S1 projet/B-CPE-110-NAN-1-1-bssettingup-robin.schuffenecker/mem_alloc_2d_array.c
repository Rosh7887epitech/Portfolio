/*
** EPITECH PROJECT, 2023
** mem_alloc_2d_array
** File description:
** mem_alloc_2d_array
*/

#include <stdio.h>
#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int **tableau = malloc(nb_rows * sizeof(int*));

    for (int i = 0; i < nb_rows; i++) {
        tableau[i] = malloc(nb_cols * sizeof(int));
    }
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            tableau[i][j] = 1 + 2 * 2;
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
    return tableau;
}
