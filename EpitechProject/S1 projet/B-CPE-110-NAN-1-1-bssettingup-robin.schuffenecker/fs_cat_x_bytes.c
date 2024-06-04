/*
** EPITECH PROJECT, 2023
** fs_cat
** File description:
** cat 500 byte of file
*/

#include <fcntl.h>
#include <unistd.h>

void fs_cat_x_bytes
(char const *filepath, int x)
{
    char buff = malloc(sizeof(char) * x);
    int fd = open(filepath, O_RDONLY);

    read(fd, &buff, x);
    write(1, &buff, x);
    close(fd);
}
