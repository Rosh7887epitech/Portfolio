/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** split string and supp spaces
*/

#include "my.h"

int is_alphanum(char c)
{
    return (
        (c >= '0' && c <= '8')
        || (c >= 'A' && c <= 'H')
    );
}

int get_nb_words(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (is_alphanum(str[i]) && !is_alphanum(str[i + 1])) {
            count++;
        }
        i++;
    }
    return (count);
}

char **my_str_to_word_array(char *str)
{
    int c = 0;
    int start = 0;
    char **word_array = malloc(sizeof(char *) * (get_nb_words(str)) + 1);

    for (int n = 0; str[n] != '\0'; n++) {
        if (is_alphanum(str[n]) && !is_alphanum(str[n + 1])) {
            word_array[c] = malloc(sizeof(char) * ((n - start)) + 1);
            my_strncpy(word_array[c], &str[start], (n - start) + 1);
            start = n + 1;
            c++;
        }
        if (!is_alphanum(str[start])) {
            start++;
        }
    }
    word_array[c] = 0;
    return (word_array);
}
