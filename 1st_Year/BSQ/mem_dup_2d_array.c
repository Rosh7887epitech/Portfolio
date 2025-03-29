/*
** EPITECH PROJECT, 2023
** mem_dup_2d_array
** File description:
** mem_dup_2d_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/bsq.h"
#include "include/my.h"

char **mem_dup_2d_array(char **arr, base_t *var)
{
    char **cop = malloc(sizeof(char *) * var->nb_rows);

    for (int i = 0; i < var->nb_rows; i++) {
        cop[i] = malloc(sizeof(char) * var->nb_cols);
        my_strcpy(cop[i], arr[i]);
    }
    return cop;
}
