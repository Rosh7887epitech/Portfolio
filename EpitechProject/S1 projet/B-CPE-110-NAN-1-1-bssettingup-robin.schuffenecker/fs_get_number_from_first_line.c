/*
** EPITECH PROJECT, 2023
** get number from first line
** File description:
** get number hard mod
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static int reader(char const *str)
{
    int m = 0;
    int j = 0;

    while (str[m] != '\0') {
        if ((str[m] >= '0') && (str[m] <= '9')) {
            j++;
        }
        m++;
    }
    if (j > 10) {
        return 1;
    } else {
        return 0;
    }
}

static int is_alpha_for_nbr(char a)
{
    if ((a >= '0') && (a <= '9')) {
        return 1;
    } else {
        return 0;
    }
}

static int my_getnbr(char const *str)
{
    int i = 0;
    int k = reader(str);
    int n = 0;

    if (k == 1)
        return 0;
    while (is_alpha_for_nbr(str[i]) != 1) {
        if ((str[i] == '-') && (is_alpha_for_nbr(str[i + 1]) == 1)) {
            n = -1;
        }
        i++;
    }
    while (is_alpha_for_nbr(str[i]) == 1) {
        k *= 10;
        k += str[i] - 48;
        i++;
    }
    if (n == -1)
        k = k * n;
    return k;
}

int fs_get_number_from_first_line(char const *filepath)
{
    char buff[1000];
    char temp[1000];
    int fd = open(filepath, O_RDONLY);
    int readfd = read(fd, buff, sizeof(buff));

    for (int i = 0; buff[i] != '\n' && readfd != -1; i++) {
        write(1, &buff[i], 1);
        temp[i] = buff[i];
    }
    close(fd);
    return my_getnbr(temp);
}
