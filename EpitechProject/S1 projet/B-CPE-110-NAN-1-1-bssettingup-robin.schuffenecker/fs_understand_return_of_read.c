/*
** EPITECH PROJECT, 2023
** read
** File description:
** specific message
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

void fs_understand_return_of_read
(int fd, char *buffer, int size)
{
    int readfd = read(fd, buffer, size);

    if (readfd == -1) {
        my_putstr("read failed\n");
        return;
    }
    if (readfd == 0) {
        my_putstr("read has nothing more to read\n");
        return;
    }
    if (readfd < size) {
        my_putstr("read didn't complete the entire buffer\n");
        return;
    }
    if (readfd == size) {
        my_putstr("read completed the entire buffer\n");
        return;
    }
}
