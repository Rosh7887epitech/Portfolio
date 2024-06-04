/*
** EPITECH PROJECT, 2024
** tail
** File description:
** tail
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char **tail(char *name_file)
{
    int fd = 0;
    size_t size = 1024;
    char *buffer = NULL;
    char **file = NULL;

    fd = open(name_file, O_RDONLY);
    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    fd = read(fd, buffer, size);
    file = my_str_to_word_array(buffer, '\n');
    free(buffer);
    close(fd);
    return file;
}

int normal_tail(char **file)
{
    int len_file = 0;
    int a = 0;

    while (file[len_file] != NULL)
        len_file++;
    a = len_file;
    len_file -= 11;
    if (len_file < 0)
        len_file = 0;
    for (int i = len_file; file[i] != NULL; i++) {
        my_putstr(file[i]);
        if (file[i + 1] != NULL)
            my_putstr("\n");
    }
}
