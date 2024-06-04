/*
** EPITECH PROJECT, 2023
** bsprintf
** File description:
** lib for va_arg
*/

#ifndef MPRINTF_H_
    #define MPRINTF_H_

int sum_numbers(int n, ...);

int sum_strings_length(int n, ...);

void disp_stdarg(char *s, ...);

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_put_nbr_two(int n);

void my_put_nbr(int n);
#endif
