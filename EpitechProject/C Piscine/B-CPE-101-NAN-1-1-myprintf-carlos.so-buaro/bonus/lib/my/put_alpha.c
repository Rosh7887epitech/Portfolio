/*
 2** EPITECH PROJECT, 2023
 3** put_alpha
 4** File description:  
 5** put all alphabet base
 6*/

#include "my.h"
#include <stdarg.h>

int put_alpha(const char *format, va_list args, int i)
{
    char *b_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    convertion((va_arg(args, int)), b_alpha);
    i++;
}
