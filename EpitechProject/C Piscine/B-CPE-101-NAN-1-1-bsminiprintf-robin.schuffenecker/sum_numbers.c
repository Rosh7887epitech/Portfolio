/*
** EPITECH PROJECT, 2023
** sum_number
** File description:
** return the sum of the numbers passed as parameters after n
*/

#include <stdarg.h>

int sum_numbers(int n, ...)
{
    va_list args;
    int i;
    int x = 0;

    va_start(args, n);
    for (i = 0; i < n; i++) {
        x = x + va_arg(args, int);
    }
    va_end(args);
    return (x);
}
