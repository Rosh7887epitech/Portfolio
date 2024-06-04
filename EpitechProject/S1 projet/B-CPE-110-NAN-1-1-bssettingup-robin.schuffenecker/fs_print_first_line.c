/*
** EPITECH PROJECT, 2023
** fs_print_first_line
** File description:
** print only the first line
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void fs_print_first_line(char const *filepath)
{
    char buff[100];
    int fd = open(filepath, O_RDONLY);
    int readfd = read(fd, buff, sizeof(buff));

        for (int i = 0; buff[i] != '\n' && readfd != -1; i++) {
            write(1, &buff[i], 1);
        }
    close(fd);
    return;
}
