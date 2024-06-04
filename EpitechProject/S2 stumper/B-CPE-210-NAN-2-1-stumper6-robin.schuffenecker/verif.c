/*
** EPITECH PROJECT, 2024
** B-CPE-210-NAN-2-1-stumper6-robin
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>

int is_a_flag(char *str)
{
    if (str[0] == '-' && my_strlen(str) != 2)
        return (84);
    if (strcmp(str, "-f") != 0 && strcmp(str, "-s") != 0)
        return (84);
    return (0);
}

int parcing_error(char **argv)
{
    int nb_flags = 0;

    for (int i = 1; argv[i] != NULL; i = i + 1) {
        if (is_a_flag(argv[i]) == 0)
            nb_flags = nb_flags + 1;
    }
    if (nb_flags != 1)
        return (84);
    if (is_a_flag(argv[1]) != 0)
        return (84);
    if (argv[3][0] == '-') {
        if (atoi(argv[3]) == 0)
            return (84);
    } else if (my_str_isnum(argv[3]) == 1)
        return (84);
    return (0);
}

char decalage(char c, int key)
{
    if (c < 65 && my_is_maj(c + key) == 1)
        c = c + 26;
    if (c > 90 && my_is_maj(c - key) == 1)
        c = c - 26;
    if (c < 97 && my_is_maj(c + key) == 0)
        c = c + 26;
    if (c > 122 && my_is_maj(c - key) == 0)
        c = c - 26;
    return (c);
}

int negatif_to_pos(int key)
{
    while (key < 0)
        key = key + 26;
    return (key);
}
