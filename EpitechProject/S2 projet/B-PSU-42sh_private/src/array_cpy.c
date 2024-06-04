/*
** EPITECH PROJECT, 2024
** copy_env.c
** File description:
** that function should copy the env
*/
#include "../include/my_project.h"
#include <stdlib.h>

int array_size(char **environ)
{
    int size = 0;

    if (environ == NULL)
        return 0;
    for (; environ[size] != NULL; size++);
    return size;
}

char **array_cpy(char **environ)
{
    char **copied = malloc(sizeof(char *) * ((array_size(environ)) + 1));
    int index = 0;

    for (index = 0; environ[index] != NULL; index++)
        copied[index] = my_strdup(environ[index]);
    copied[index] = NULL;
    return copied;
}
