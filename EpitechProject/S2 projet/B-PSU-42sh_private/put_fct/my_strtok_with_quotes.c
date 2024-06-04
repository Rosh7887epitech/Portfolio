/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_strtok_with_quotes
*/

#include "my_project.h"

static bool is_delim(char *str, char *delim, int pos)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (str[pos] == delim[i] && is_pos_in_quotes(str, pos) == NO_QUOTES)
            return true;
    }
    return false;
}

static int count_delim_occ(char *str, char *delim)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_delim(str, delim, i))
            count++;
    }
    return count;
}

static char **alloc_array(char *str, char *delim)
{
    int count = count_delim_occ(str, delim);
    char **array = malloc(sizeof(char *) * (count + 2));

    if (array == NULL)
        return NULL;
    for (int i = 0; i < count + 2; i++)
        array[i] = NULL;
    return array;
}

static char *get_next_word(char *str, char *delim)
{
    char *word = NULL;
    int i = 0;

    for (i = 0; str[i] != '\0' && !is_delim(str, delim, i); i++);
    word = malloc(sizeof(char) * (i + 1));
    if (word == NULL)
        return NULL;
    for (int j = 0; j < i; j++)
        word[j] = str[j];
    word[i] = '\0';
    return word;
}

static void clean_delim(char *str, char *delim)
{
    int len = my_strlen(str);
    int index = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int j = len - 1; is_delim(str, delim, j); j--)
        str[j] = '\0';
    for (int i = 0; i < len; i++) {
        if (is_pos_in_quotes(str, i) != NO_QUOTES) {
            newstr[index] = str[i];
            index++;
            continue;
        }
        if (!is_delim(str, delim, i) ||
        (i > 0 && !is_delim(str, delim, i - 1))) {
            newstr[index] = str[i];
            index++;
        }
    }
    newstr[index] = '\0';
    strcpy(str, newstr);
}

char **strtok_with_quotes(char *str, char *delim)
{
    char **array;
    int delim_occ;
    char *dup = my_strdup(str);

    clean_delim(dup, delim);
    delim_occ = count_delim_occ(dup, delim) + 1;
    array = alloc_array(dup, delim);
    for (int i = 0; i < delim_occ; i++) {
        array[i] = get_next_word(dup, delim);
        dup += my_strlen(array[i]) + 1;
    }
    array[delim_occ] = NULL;
    return array;
}
