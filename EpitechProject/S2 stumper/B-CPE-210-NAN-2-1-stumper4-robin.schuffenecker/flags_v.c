/*
** EPITECH PROJECT, 2024
** flag_v
** File description:
** function of flag_v
*/

#include "include/my.h"

int flag_v(char **file)
{
    for (int i = 0; file[i] != NULL; i++) {
        if (my_strlen(file[i]) > i) {
            my_putstr("==>");
            my_putstr(file[i]);
            my_putstr("<==");
        }
    }
    return 0;
}
