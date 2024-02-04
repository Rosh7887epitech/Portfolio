/*
** EPITECH PROJECT, 2023
** load_2d_arr_from_file
** File description:
** load_2d_arr_from_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include "include/bsq.h"
#include "include/my.h"

base_t *load_2d_arr_from_file(char const *filepath, base_t *var)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file_stat;
    char tmp[1] = "";

    var->map = malloc(sizeof(char *) * var->nb_rows);
    if (stat(filepath, &file_stat) < 0) {
        var->map = NULL;
        return var;
    }
    for (int p = 0; tmp[0] != '\n'; p++) {
        read(fd, tmp, 1);
    }
    for (int i = 0; i < var->nb_rows; i++) {
        var->map[i] = malloc(sizeof(char) * var->nb_cols);
        read(fd, var->map[i], var->nb_cols + 1);
    }
    close(fd);
    return var;
}
