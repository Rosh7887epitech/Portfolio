/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_str_to_word_array
*/
#include "my_project.h"

static char *alloc_dup(char c, char *str)
{
    int i = 0;
    char *dup = NULL;

    c = str[i];
    if (c == '\'' || c == '\"') {
        i++;
        while (str[i] != c) {
            i++;
        }
            i++;
    } else
        return NULL;
    dup = malloc(sizeof(char) * (i + 1));
    return dup;
}

static char *my_strdup_quote(char *str)
{
    int i = 0;
    char *dup = NULL;
    char c = str[0];

    dup = alloc_dup(c, str);
    if (!dup)
        return NULL;
    dup[i] = str[i];
    i++;
    while (str[i] != c) {
        dup[i] = str[i];
        i++;
    }
    dup[i] = c;
    dup[i + 1] = '\0';
    return dup;
}

static bool is_delim(char c, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return true;
    }
    return false;
}

static char *cpy_dup_to_delim(char *tmp, char *dup, char *delim)
{
    int i = 0;

    for (i = 0; tmp[i] != '\0' && !is_delim(tmp[i], delim) &&
    is_pos_in_quotes(tmp, i) == NO_QUOTES; i++) {
        dup[i] = tmp[i];
    }
    dup[i] = '\0';
    return dup;
}

static char *my_strdup_to_delim(char *str, char *delim)
{
    char *dup = NULL;
    int delim_occ = 0;
    char *tmp = my_strdup(str);

    for (; tmp[delim_occ] != '\0' && is_delim(tmp[delim_occ], delim) &&
    is_pos_in_quotes(tmp, delim_occ) == NO_QUOTES; delim_occ++);
    tmp = tmp + delim_occ;
    str = str + delim_occ;
    delim_occ = 0;
    for (int a = 0; tmp[a] != '\0'; a++) {
        if (is_delim(tmp[a], delim) && is_pos_in_quotes(tmp, a) == NO_QUOTES)
            delim_occ++;
    }
    dup = malloc(sizeof(char) * (my_strlen(tmp) - delim_occ + 1));
    return cpy_dup_to_delim(tmp, dup, delim);
}

static void replace_delim(char *str, char *delim)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_pos_in_quotes(str, i) != NO_QUOTES)
            continue;
        if (str[i] == '\n')
            str[i] = delim[0];
        if (str[i] == '\t')
            str[i] = delim[0];
    }
}

static void clean_delim(char *str, char *delim)
{
    int len = 0;
    int index = 0;

    replace_delim(str, delim);
    len = my_strlen(str);
    for (int j = len - 1; is_delim(str[j], delim); j--)
        str[j] = '\0';
    for (int i = 0; i < len; i++) {
        if ((!is_delim(str[i], delim) ||
        (i > 0 && !is_delim(str[i - 1], delim)) ||
        is_pos_in_quotes(str, i) != NO_QUOTES)) {
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';
    return;
}

static char **alloc_array(char *new_str, char *delim, int *delim_occ)
{
    char **array = NULL;
    int occ = 1;

    for (int i = 0; new_str[i] != '\0'; i++) {
        if (is_delim(new_str[i], delim) &&
        is_pos_in_quotes(new_str, i) == NO_QUOTES) {
            occ++;
        }
    }
    array = malloc(sizeof(char *) * (occ + 1));
    *delim_occ = occ;
    for (int i = 0; i <= occ; i++)
        array[i] = NULL;
    return array;
}

static char *clean_new_str(char *new_str, char *str, char *delim)
{
    new_str = add_delim_to_quotes(str, delim);
    clean_delim(new_str, delim);
    clean_esperluette(new_str);
    if (is_delim(new_str[my_strlen(new_str) - 1], delim))
        new_str[my_strlen(new_str) - 1] = '\0';
    return new_str;
}

char **str_to_word_array(char *str, char *delim)
{
    char **array = NULL;
    char *tmp = NULL;
    char *new_str = my_strdup(str);
    int delim_occ = 0;

    new_str = clean_new_str(new_str, str, delim);
    array = alloc_array(new_str, delim, &delim_occ);
    for (int i = 0; i < delim_occ; i++) {
        tmp = my_strdup_quote(new_str);
        if (!tmp)
            array[i] = my_strdup_to_delim(new_str, delim);
        else
            array[i] = my_strdup(tmp);
        new_str = new_str + my_strlen(array[i]);
        if (is_delim(new_str[0], delim))
            new_str = new_str + 1;
    }
    array[delim_occ] = NULL;
    return array;
}
