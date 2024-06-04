/*
** EPITECH PROJECT, 2024
** flag_n
** File description:
** function of falg_n
*/

#include <stddef.h>
#include "include/my.h"

int flag_n(char **file, int nb_line)
{
    int len_file = 0;

    while (file[len_file] != NULL)
        len_file++;
    len_file -= nb_line + 1;
    if (len_file < 0)
        len_file = 0;
    for (int i = len_file; file[i] != NULL; i++) {
        my_putstr(file[i]);
        if (file[i + 1] != NULL)
            my_putstr("\n");
    }
}
