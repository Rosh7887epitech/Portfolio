/*
** EPITECH PROJECT, 2024
** correct_inhibitors.c
** File description:
** that file should correct inhibitors info
*/
#include "my_project.h"
// prends en parametre la str que tu veux analyser, puis la str que tu
// veux remplacer et enfin la str par lequel tu vas remplacer
void replace_strings(char *str, char *cramptes, char *space)
{
    char *temp = NULL;
    char *result = NULL;
    int length = 0;
    int cramptes_length = 0;
    int space_length = 0;

    if (str == NULL || cramptes == NULL || space == NULL)
        return;
    result = strstr(str, cramptes);
    if (result == NULL)
        return;
    length = my_strlen(str);
    cramptes_length = my_strlen(cramptes);
    space_length = my_strlen(space);
    temp = malloc(length - cramptes_length + space_length + 1);
    strncpy(temp, str, result - str);
    strcpy(temp + (result - str), space);
    strcat(temp, result + cramptes_length);
    strcpy(str, temp);
    free(temp);
}

static void puts_space_in_str(char **array, int i, int j)
{
    if (my_strncmp(array[i] + j, "#cramptes#", 10) == 0) {
        replace_strings(array[i], "#cramptes#", " ");
        clean_esperluette(array[i]);
    }
}

void correct_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i]; i++) {
        for (int j = 0; array[i][j] != '\0'; j++)
            puts_space_in_str(array, i, j);
    }
}

void correct_str(char *str)
{
    if (str == NULL)
        return;
    for (int j = 0; str[j] != '\0'; j++) {
        replace_strings(str, "#cramptes#", " ");
    }
}
