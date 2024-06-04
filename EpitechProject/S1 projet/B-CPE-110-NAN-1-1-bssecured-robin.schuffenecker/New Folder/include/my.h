/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** SECURED
*/

#pragma once

    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "secured.h"
    #include <stdio.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strdup(char *src);
int main(void);
