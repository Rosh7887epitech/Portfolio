/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** str_cat_at_pos
*/

#include "my_project.h"

char *str_cat_at_pos(char *dest, char *src, int pos)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    char *tmp2 = my_strdup(dest + pos);
    int i = 0;

    if (!dest || !src || !tmp || !tmp2)
        return NULL;
    my_strncpy(tmp, dest, pos + 1);
    while (src[i] != '\0') {
        tmp[pos + i] = src[i];
        i++;
    }
    tmp[pos + i] = '\0';
    tmp = my_strcat(tmp, tmp2);
    return my_strdup(tmp);
}
