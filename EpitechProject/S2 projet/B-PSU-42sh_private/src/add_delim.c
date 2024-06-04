/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** add_delim
*/
#include "my_project.h"

static char *add_char_to_pos(char *str, char c, int pos)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (i == pos) {
            new_str[j] = c;
            j++;
        }
        new_str[j] = str[i];
        i++;
        j++;
    }
    new_str[j] = '\0';
    free(str);
    return new_str;
}

static char *add_to_double_quotes(char *str, char *delim)
{
    char *new_str = my_strdup(str);
    bool sq = false;
    bool dq = false;

    for (int i = 0; new_str[i] != '\0'; i++) {
        modify_q_status(new_str[i], &sq, &dq);
        if ((new_str[i] == '\"' && sq) || (new_str[i] == '\'' && dq))
            continue;
        if (new_str[i] == '\"' && dq) {
            new_str = add_char_to_pos(new_str, delim[0], i);
            i++;
        }
        if (new_str[i] == '\"' && !dq) {
            new_str = add_char_to_pos(new_str, delim[0], i + 1);
            i++;
        }
    }
    return new_str;
}

static char *add_to_single_quotes(char *str, char *delim)
{
    char *new_str = my_strdup(str);
    bool sq = false;
    bool dq = false;

    for (int i = 0; new_str[i] != '\0'; i++) {
        modify_q_status(new_str[i], &sq, &dq);
        if ((new_str[i] == '\"' && sq) || (new_str[i] == '\'' && dq))
            continue;
        if (new_str[i] == '\'' && sq) {
            new_str = add_char_to_pos(new_str, delim[0], i);
            i++;
        }
        if (new_str[i] == '\'' && !sq) {
            new_str = add_char_to_pos(new_str, delim[0], i + 1);
            i++;
        }
    }
    return new_str;
}

char *add_delim_to_quotes(char *str, char *delim)
{
    char *new_str = my_strdup(str);

    if (count_quotes(str) == 0)
        return new_str;
    new_str = add_to_double_quotes(new_str, delim);
    new_str = add_to_single_quotes(new_str, delim);
    return new_str;
}
