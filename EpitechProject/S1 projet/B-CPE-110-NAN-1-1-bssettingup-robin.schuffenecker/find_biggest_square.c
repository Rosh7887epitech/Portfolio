/*
** EPITECH PROJECT, 2023
** find_biggest_square
** File description:
** find_biggest_square
*/

#include <stdio.h>
#include <stdlib.h>
#include "array_2D.h"

static int condition(char **map, int i, int j)
{
    if (map[i][j] == 'o') {
        return 84;
    }
}

int find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int max_square = 0;
    int compt = 0;

    printf("\n");
    for (int i = row; i < nb_rows; i++) {
        for (int j = col; j < nb_cols; i++) {
            condition(map, i, j);
            max_square++;
        }
    }
    printf("%i", max_square);
    return max_square;
}
