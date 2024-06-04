/*
** EPITECH PROJECT, 2023
** sum_strings_length
** File description:
** return the sum of the length of every
** string passed as parameter after n
*/

#include <stdarg.h>

static int my_strlen(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0' ) {
        i++;
    }
    return (i);
}

int sum_strings_length(int n, ...)
{
    va_list args;
    int x = 0;

    va_start(args, n);
    for (int i = 0; i < n; i++) {
        x += my_strlen(va_arg(args, char *));
    }
    va_end(args);
    return (x);
}
