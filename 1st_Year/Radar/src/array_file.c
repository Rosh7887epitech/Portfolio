/*
** EPITECH PROJECT, 2024
** file to 2d array
** File description:
** array
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

int length(const char *buff)
{
    int line = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            line++;
        }
    }
    return line;
}

int my_len(int index, const char *buff)
{
    int len = 0;

    while (buff[index + len] != '\n' && buff[index + len] != '\0') {
        len++;
    }
    return len;
}

char **load_2d_arr_from_file(char *buff, base_st *var)
{
    int index = 0;
    int len = 0;
    int j;
    char **map;

    map = malloc(sizeof(char *) * var->path.row);
    for (int i = 0; i < var->path.row; i++) {
        len = my_len(index, buff);
        map[i] = malloc(sizeof(char) * (len + 1));
        for (j = 0; j < len; j++) {
            map[i][j] = buff[index];
            index ++;
        }
        map[i][j] = '\0';
        index++;
    }
    var->path.col = len;
    return map;
}
