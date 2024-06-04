/*
** EPITECH PROJECT, 2023
** setting up V1
** File description:
** search biggest square in a template or an generate template
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        my_putchar(str[i]);
        i = i + 1;
    }
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        i++;
    }
    return (i);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void bsq_cat_path
(char const *filepath, int x)
{
    char buff = malloc(sizeof(char) * x);
    int fd = open(filepath, O_RDONLY);

    read(fd, &buff, x);
    write(1, &buff, x);
    close(fd);
}

int bsq_generation(char const *path)
{
    return 0;
}

int bsq_file(int fd, char const *path, char *str)
{
    int size = 10000;
    int readfd = read(fd, str, size);

    printf("s");
    if (readfd == size) {
        printf("l");
        my_putstr("read completed the entire buffer\n");
        bsq_cat_path(path, size);
    } else {
        return 84;
    }
}

int setting_up(char const *path)
{
    int fd = open(path, O_RDONLY);
    char *str;

    printf("r");
    my_strcpy(str, path);
    if (fd != -1) {
        printf("g");
        bsq_file(fd, path, str);
    } else {
        bsq_generation(path);
    }
    close(fd);
    return fd;
}
