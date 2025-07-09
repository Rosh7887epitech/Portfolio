/*
** EPITECH PROJECT, 2023
** change_var
** File description:
** change
*/

#include "include/include.h"
#include "include/bsq.h"
#include "include/my.h"

base_t *change_char(base_t *var)
{
    var->cop = mem_dup_2d_array(var->map, var);
    for (int i = var->rows; i < var->rows  + var->max_size; i++) {
        for ( int j = var->cols; j < var->cols + var->max_size; j++) {
            var->cop[i][j] = 'x';
        }
    }
    return var;
}
