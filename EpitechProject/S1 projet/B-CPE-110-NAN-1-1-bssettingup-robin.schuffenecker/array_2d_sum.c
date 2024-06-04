/*
** EPITECH PROJECT, 2023
** array_2d_sum
** File description:
** sum of 2D array
*/

#include <stdio.h>

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int array_nb = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            array_nb += arr[i][j];
        }
    }
    return array_nb;
}
