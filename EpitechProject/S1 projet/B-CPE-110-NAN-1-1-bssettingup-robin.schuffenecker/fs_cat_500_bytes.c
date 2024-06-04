/*
** EPITECH PROJECT, 2023
** fs_cat
** File description:
** cat 500 byte of file
*/

#include <fcntl.h>
#include <unistd.h>

void fs_cat_500_bytes
(char const *filepath)
{
    char buff = malloc(sizeof(char) * 501);
    int fd = open(filepath, O_RDONLY);

    read(fd, &buff, 500);
    write(1, &buff, 500);
    close(fd);
}
