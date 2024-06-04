/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-bscorewar-robin.schuffenecker
** File description:
** main
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
    name = malloc(sizeof(char) * sb.st_size);
    comment = malloc(sizeof(char) * sb.st_size);
    read(fd, buff, sb.st_size);
    for (int i = 0; buff[i + 4] != '\0'; i++) {
        name[index] = buff[i + 4];
        index++;
    }
    name[index] = '\0';
    printf("name : %s\n", name);
    index = 0;
    for (int i = 0; buff[i + 140] != '\0'; i++) {
        comment[index] = buff[i + 140];
        index++;
    }
    comment[index] = '\0';
    printf("comment : %s\n", comment);
    prog |= buff[128 + 8];
    prog <<= 8;
    prog |= buff[128 + 9];
    prog <<= 8;
    prog |= buff[128 + 10];
    prog <<= 8;
    prog |= buff[128 + 11];
    printf("size : %d\n", prog);
    close(fd);
    return 0;
}
