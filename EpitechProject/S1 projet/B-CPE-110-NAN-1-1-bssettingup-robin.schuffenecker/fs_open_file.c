/*
** EPITECH PROJECT, 2023
** open_file
** File description:
** open read only file
*/

#include <fcntl.h>
#include <unistd.h>

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

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd != -1) {
        my_putstr("SUCCESS\n");
    } else {
        my_putstr("FAILURE\n");
    }
    close(fd);
    return fd;
}
