/*
** EPITECH PROJECT, 2023
** my
** File description:
** my h
*/
#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <stdio.h>
    #include <time.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdlib.h>

void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);

#endif
