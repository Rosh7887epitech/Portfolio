/*
** EPITECH PROJECT, 2024
** clean_str.c
** File description:
** that file should clear the str
*/
#include "my_project.h"

static void replace_multiple(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_pos_in_quotes(str, i) != NO_QUOTES)
            continue;
        if (str[i] == '\n')
            str[i] = '\0';
        if (str[i] == ';')
            str[i] = ' ';
        if (str[i] == '\t')
            str[i] = ' ';
    }
}

void clean_str(char *str)
{
    int index = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    replace_multiple(str);
    for (int j = my_strlen(str) - 1; str[j] == ' ' || str[j] == '\t'; j--)
        str[j] = '\0';
    for (int i = 0; i < my_strlen(str); i++) {
        if (is_pos_in_quotes(str, i) != NO_QUOTES) {
            newstr[index] = str[i];
            index++;
            continue;
        }
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            newstr[index] = str[i];
            index++;
        }
    }
    newstr[index] = '\0';
    strcpy(str, newstr);
}

static void replace_esperluette(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_pos_in_quotes(str, i) != NO_QUOTES)
            continue;
        if (str[i] == '\n')
            str[i] = ' ';
        if (str[i] == '\t')
            str[i] = ' ';
    }
}

void clean_esperluette(char *str)
{
    int index = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    replace_esperluette(str);
    for (int j = my_strlen(str) - 1; str[j] == ' ' || str[j] == '\t'; j--)
        str[j] = '\0';
    for (int i = 0; i < my_strlen(str); i++) {
        if (is_pos_in_quotes(str, i) != NO_QUOTES) {
            newstr[index] = str[i];
            index++;
            continue;
        }
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            newstr[index] = str[i];
            index++;
        }
    }
    newstr[index] = '\0';
    strcpy(str, newstr);
}
