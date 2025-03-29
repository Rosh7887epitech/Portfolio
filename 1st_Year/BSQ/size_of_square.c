/*
** EPITECH PROJECT, 2023
** size
** File description:
** size
*/

#include "include/include.h"
#include "include/bsq.h"
#include "include/my.h"

base_t *size_of_square(base_t *var, char const *filepath)
{
    char *tmp = load_file_in_mem(filepath);
    int i = 0;

    var->nb_rows = -1;
    var->nb_cols = 0;
    for (i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] == '\n')
        var->nb_rows = var->nb_rows + 1;
    }
    for (i = 0; tmp[i] != '\n'; i++)
        i = i;
    i++;
    for (var->nb_cols = 0; tmp[i] != '\n'; i++) {
        var->nb_cols = var->nb_cols + 1;
    }
    return var;
}
