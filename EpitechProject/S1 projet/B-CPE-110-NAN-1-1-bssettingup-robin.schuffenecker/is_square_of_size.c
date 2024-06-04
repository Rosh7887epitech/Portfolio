/*
** EPITECH PROJECT, 2023
** is_square_of_size
** File description:
** is_square_of_size
*/

#include <stdio.h>
#include <stdlib.h>

static int condition(char **map, int i, int j, int square_size)
{
    int error = 0;

    if (map[i][j] == 'o') {
        printf("\nerror");
        error = 84;
        return error;
    }
    return error;
}

static int lenght_of_square(char **map, int row, int col, int square_size)
{
    int lenght_col = 0;

    for (int i = 0; map[0][i] != '\n'; i++) {
        lenght_col++;
    }
    printf("\n%i", lenght_col);
}

static int widht_of_square(char **map, int row, int col, int square_size)
{
    int lenght_row = 0;
    int i = 0;

    for (int j = 0; map[j][i] == '.' || map[j][i] == 'o' || map[j][i] == '\n'; j++) {
            printf("estestes\n");
            for (i = 0; map[j][i] == '.' || map[j][i] == 'o'; i++) {
                printf("97\n");
                i = i;
            }
            printf("\n");
            lenght_row++;
        }
    printf("    %i", lenght_row);
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int i;
    int j;
    int error = 0;

    lenght_of_square(map, row, col, square_size);
    widht_of_square(map, row, col, square_size);
    for (i = row; i < square_size && error != 84; i++) {
        for (j = col; (j < square_size) && error != 84; j++) {
            error = condition(map, i, j, square_size);
        }
    }
    if (i == square_size && j == square_size && error != 84) {
        printf("%i  %i", i, j);
        printf("success");
        return 1;
    }
}