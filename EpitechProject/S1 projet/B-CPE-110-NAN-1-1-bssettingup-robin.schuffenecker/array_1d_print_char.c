/*
** EPITECH PROJECT, 2023
** array_1d_print_char
** File description:
** display array value
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void array_1d_print_char(char const *arr)
{
    for (int i = 0; arr[i] != '\0'; i++) {
        write(1, &arr[i], 1);
        write(1, "\n", 1);
    }
}
