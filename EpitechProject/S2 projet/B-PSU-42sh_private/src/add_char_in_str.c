/*
** EPITECH PROJECT, 2024
** add_char_in_str?c
** File description:
** that file should permit to add a charactere into an str
*/
#include "my_project.h"

char *add_char_str(char *str, char c, int index)
{
    char *new_str = NULL;
    int i = 0;
    int j = 0;

    if (str == NULL || str[0] == '\0') {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = c;
        new_str[1] = '\0';
        return strdup(new_str);
    }
    new_str = malloc(sizeof(char) * (strlen(str) + 2));
    for (i = 0; i < index; i++)
        new_str[i] = str[i];
    new_str[index] = c;
    new_str[index + 1] = '\0';
    for (j = index + 1; str[j - 1] != '\0'; j++)
        new_str[j] = str[j - 1];
    new_str[j] = '\0';
    return strdup(new_str);
}

char *remove_char_str(char *str, int index)
{
    char *new_str = NULL;
    int i = 0;

    if (str == NULL || str[0] == '\0' || my_strlen(str) == 1){
        new_str = malloc(sizeof(char) * 1);
        new_str[0] = '\0';
        return my_strdup(new_str);
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; i < index && str[i] != '\0'; i++)
        new_str[i] = str[i];
    i++;
    for (; str[i] != '\0'; i++)
        new_str[i - 1] = str[i];
    new_str[i] = '\0';
    return my_strdup(new_str);
}
