/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** clean_line
*/

#include "command.h"

char *cond_clean(char *str)
{
    char *dest = NULL;

    if (str == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (dest == NULL)
        return NULL;
    return dest;
}

char *end_clean(char *dest, int j)
{
    if (j > 0 && dest[j - 1] == ' ')
        j--;
    dest[j] = '\0';
    return dest;
}

char *clean_line(char *str)
{
    char *dest = NULL;
    int i = 0;
    int j = 0;
    int space = 0;

    dest = cond_clean(str);
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t') {
            dest[j] = str[i];
            j++;
            space = 0;
        }
        if ((str[i] == ' ' || str[i] == '\t') && !space && j > 0) {
            dest[j] = ' ';
            j++;
            space = 1;
        }
        i++;
    }
    return end_clean(dest, j);
}
