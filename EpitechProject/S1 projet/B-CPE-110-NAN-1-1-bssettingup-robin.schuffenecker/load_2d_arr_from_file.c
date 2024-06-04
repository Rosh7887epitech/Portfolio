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

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char **tableau = malloc(sizeof(char*) * nb_rows);
    int fd = open(filepath, O_RDONLY);
    struct stat file_stat;

    if (stat(filepath, &file_stat) < 0){
        return tableau;
    }
    for (int i = 0; i < nb_rows; i++) {
        tableau[i] = malloc(sizeof(char) * nb_cols);
        read(fd, tableau[i], nb_cols + 1);
        printf("%s", tableau[i]);
    }
    close(fd);
    return tableau;
}
