/*
** EPITECH PROJECT, 2024
** tail
** File description:
** tail_c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int tail_c(char *name_file, int nb_byte)
{
    int fd = 0;
    size_t size = 1024;
    char *buffer = NULL;
    int len_print = 0;

    fd = open(name_file, O_RDONLY);
    if (fd == -1 || name_file == NULL)
        return 84;
    buffer = malloc(sizeof(char) * (size + 1));
    fd = read(fd, buffer, size);
    close(fd);
    len_print = my_strlen(buffer) - nb_byte;
    if (len_print < 0)
        len_print = 0;
    for (int i = len_print; buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
    free(buffer);
}
