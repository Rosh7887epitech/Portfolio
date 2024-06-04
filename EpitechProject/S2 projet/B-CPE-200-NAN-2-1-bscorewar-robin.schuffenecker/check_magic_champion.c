/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-bscorewar-robin.schuffenecker
** File description:
** check_magic_champion
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "op.h"

int main(int ac, char **av)
{
    struct stat sb;
    int fd = 0;
    char *buff = NULL;
    char *name = NULL;
    char *comment = NULL;
    int index = 0;
    int prog = 0;

    if (av[1] == NULL)
        return 84;
    fd = open(av[1], O_RDONLY, 0644);
    if (stat(av[1], &sb) == -1)
        return 84;
    buff = malloc(sizeof(char) * sb.st_size);
    comment = malloc(sizeof(char) * 4);
    read(fd, buff, sb.st_size);
    prog |= buff[1];
    prog <<= 8;
    prog |= buff[2];
    prog <<= 8;
    prog |= buff[3];
    for (int i = 1; i < 3; i++) {
        comment[index] = buff[i];
        index++;
    }
    comment[index] = '\0';
    printf("comment : %s\n", comment);
    printf("size : %d\n", prog);
    close(fd);
    return 0;
}