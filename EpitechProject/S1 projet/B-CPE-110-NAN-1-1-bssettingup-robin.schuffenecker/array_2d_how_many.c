/*
** EPITECH PROJECT, 2023
** array_2d_how_many
** File description:
** how many time number appear
*/

#include <stdio.h>
#include "array_2D.h"

int compt(int **arr, struct array_2D *var, int number)
{
    if (arr[var->i][var->j] == number) {
        var->k++;
    }
    return var->k;
}

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    struct array_2D var;
    var.k = 0;
    var.i = 0;
    var.j = 0;

    for (var.i = 0; var.i < nb_rows; var.i++) {
        for (var.j = 0; var.j < nb_cols; var.j++) {
            printf("%d ", arr[var.i][var.j]);
            compt(arr, &var, number);
        }
        printf("\n");
    }
    printf("\n");
    printf("%i", var.k);
    return var.k;
}