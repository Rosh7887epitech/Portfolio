/*
** EPITECH PROJECT, 2023
** pos_of_square
** File description:
** pos_of_square
*/

#include "include/include.h"
#include "include/bsq.h"
#include "include/my.h"

static base_t *compare(base_t *var)
{
    if (var->size_tmp > var->max_size) {
        var->max_size = var->size_tmp;
        var->cols = var->x;
        var->rows = var->y;
    }
    return var;
}

base_t *pos_of_square(base_t *var)
{
    var->size_tmp = 0;
    var->max_size = 0;
    var->cols = 0;
    var->rows = 0;
    for (var->y = 0; var->y < var->nb_rows; var->y++) {
        for (var->x = 0; var->x < var->nb_cols; var->x++) {
            var->size_tmp = find_biggest_square(var);
            compare(var);
        }
    }
    return var;
}
