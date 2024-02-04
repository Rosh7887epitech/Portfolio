/*
** EPITECH PROJECT, 2023
** load_file_in_mem
** File description:
** load_file_in_mem
*/

#include "include/include.h"
#include "include/my.h"
#include "include/bsq.h"

char *load_file_in_mem(char const *filepath)
{
    int sizefile = stat_of_file(filepath);
    char *buff = malloc(sizeof(char) * sizefile);
    int fd = open(filepath, O_RDONLY);
    struct stat file_stat;

    if (stat(filepath, &file_stat) < 0){
        return "error";
    }
    read(fd, buff, sizefile);
    close(fd);
    return buff;
}
