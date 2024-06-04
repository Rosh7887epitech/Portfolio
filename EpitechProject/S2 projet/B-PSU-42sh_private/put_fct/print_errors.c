/*
** EPITECH PROJECT, 2024
** print_error.c
** File description:
** that function should print in error
*/
#include "../include/my_project.h"
#include <unistd.h>

int my_printerror(char *str, int return_status)
{
    write(2, str, my_strlen(str));
    return return_status;
}
