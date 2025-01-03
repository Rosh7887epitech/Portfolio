/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "my.h"

int filereader(base_t *var, char *file_pos)
{
    char *buff;
    int fd = open(file_pos, O_RDONLY);

    if (file_pos == NULL) {
        my_putstr("error wrong file\n");
        return 84;
    }
    buff = malloc(sizeof(char) * 32 + 2);
    if (buff == NULL || fd == -1 || read(fd, buff, 32) != 32) {
        close(fd);
        return 84;
    }
    var->buff = buff;
    return 0;
}

int filereader_ptwo(base_t *var, char *file_pos)
{
    char *buff;
    int fd = open(file_pos, O_RDONLY);

    if (file_pos == NULL) {
        my_putstr("error wrong file\n");
        return 84;
    }
    buff = malloc(sizeof(char) * 32 + 2);
    if (buff == NULL || fd == -1 || read(fd, buff, 32) != 32) {
        close(fd);
        return 84;
    }
    var->buff_two = buff;
    return 0;
}
