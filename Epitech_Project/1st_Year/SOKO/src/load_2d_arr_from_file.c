/*
** EPITECH PROJECT, 2023
** load_2d_arr_from_file
** File description:
** load_2d_arr_from_file
*/

#include "../include/soko.h"

int my_len(int index, char *buff)
{
    int col = index;
    int test = 0;

    while (buff[col] != '\n') {
        test++;
        col++;
    }
    return test;
}

char **load_2d_arr_from_file(char *buff, soko_t *var)
{
    int i = 0;
    int j = 0;
    int index = 0;
    int len = 0;
    char **map;

    map = malloc(sizeof(char *) * var->row);
    for (i = 0; i < var->row; i++) {
        len = my_len(index, buff);
        map[i] = malloc(sizeof(char) * len + 1);
        for (j = 0; j < len; j++) {
            map[i][j] = buff[index];
            index++;
        }
        index++;
        map[i][j] = '\n';
        map[i][j + 1] = '\0';
        var->col = len;
    }
    return map;
}
