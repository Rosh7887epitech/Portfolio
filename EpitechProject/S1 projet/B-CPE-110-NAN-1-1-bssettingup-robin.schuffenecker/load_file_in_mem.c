/*
** EPITECH PROJECT, 2023
** load_file_in_mem
** File description:
** load_file_in_mem
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>

char *load_file_in_mem(char const *filepath)
{
    char buff[10000];
    char *str = malloc(sizeof(char) * sizeof(buff));
    int fd = open(filepath, O_RDONLY);
    struct stat file_stat;

    if (stat(filepath, &file_stat) < 0){
        return "error";
    }
    read(fd, str, sizeof(buff));
    close(fd);
    return str;
}
