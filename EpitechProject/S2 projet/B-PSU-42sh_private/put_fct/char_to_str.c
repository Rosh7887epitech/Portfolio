/*
** EPITECH PROJECT, 2024
** char_to_str.c
** File description:
** that file should tranform char into str
*/
#include <stdlib.h>

char *char_to_str(char character)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = character;
    str[1] = '\0';
    return str;
}
