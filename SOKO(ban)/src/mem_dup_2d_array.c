/*
** EPITECH PROJECT, 2023
** mem_dup_2d_array
** File description:
** mem_dup_2d_array
*/

#include "../include/soko.h"

char **mem_dup_2d_array(soko_t *var)
{
    char **cop = malloc(sizeof(char *) * var->row);

    for (int i = 0; i < var->row; i++) {
        cop[i] = malloc(sizeof(char) * my_strlen(var->map[i]));
        my_strcpy(cop[i], var->map[i]);
    }
    return cop;
}
