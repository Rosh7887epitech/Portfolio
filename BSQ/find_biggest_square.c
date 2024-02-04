/*
** EPITECH PROJECT, 2023
** find_biggest_square
** File description:
** find_biggest_square
*/

#include "include/include.h"
#include "include/bsq.h"
#include "include/my.h"

static int verification_of_char(base_t *var, int i, int size)
{
    int j = 0;

    while (j <= i) {
        if (var->map[var->y + i][var->x + j] == 'o' ||
            var->map[var->y + j][var->x + i] == 'o' ||
            var->map[var->y + i][var->x + i] == 'o' ||
            var->map[var->y + j][var->x + j] == 'o') {
                return 0;
        }
        j++;
    }
    size++;
    return size;
}

int find_biggest_square(base_t *var)
{
    int i = 0;
    int size = 0;
    int biggest_size = 0;

    while ((var->y + i < var->nb_rows) &&
            (var->x + i < var->nb_cols)) {
        size = verification_of_char(var, i, size);
        if (size > biggest_size) {
            biggest_size = size;
        }
        i++;
    }
    return biggest_size;
}
