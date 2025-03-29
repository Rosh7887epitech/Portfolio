/*
** EPITECH PROJECT, 2023
** mem_alloc_2d_array
** File description:
** mem_alloc_2d_array
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/bsq.h"
#include "include/my.h"

char **mem_alloc_2d_array(base_t *var)
{
    char **tableau = malloc(var->nb_rows * sizeof(char *));

    for (int i = 0; i < var->nb_rows; i++) {
        tableau[i] = malloc(var->nb_cols * sizeof(char));
    }
    for (int i = 0; i < var->nb_rows; i++) {
        for (int j = 0; j < var->nb_cols; j++) {
            tableau[i][j] = 1 + 2 * 2;
        }
    }
    return tableau;
}
