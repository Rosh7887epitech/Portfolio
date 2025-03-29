/*
** EPITECH PROJECT, 2023
** get number from first line
** File description:
** get number hard mod
*/

#include "include/include.h"
#include "include/bsq.h"
#include "include/my.h"

int fs_get_number_from_first_line(char const *filepath)
{
    int size_of_path = stat_of_file(filepath);
    char *buff = malloc(sizeof(char) * size_of_path);
    char *temp = malloc(sizeof(char) * size_of_path);
    int fd = open(filepath, O_RDONLY);

    if (fd != 1) {
        read(fd, buff, sizeof(buff));
        for (int i = 0; buff[i] != '\n'; i++) {
            temp[i] = buff[i];
        }
    } else {
        return 84;
    }
    close(fd);
    return my_getnbr(temp);
}
