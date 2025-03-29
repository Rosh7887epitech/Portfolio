/*
** EPITECH PROJECT, 2024
** timer
** File description:
** timer
*/

#include "my.h"

int case_length(int score, int length, int temp_score)
{
    if (score == 0) {
        length++;
    } else {
        temp_score = score;
        while (temp_score != 0) {
            temp_score /= 10;
            length++;
        }
    }
    return length;
}

char *push_str(char *str, int score, int i, int nb)
{
    if (score == 0) {
        str[i] = '0';
    } else {
        while (score != 0) {
            nb = score % 10;
            str[i] = nb + '0';
            i--;
            score /= 10;
        }
    }
    return str;
}

char *my_itoa(int score)
{
    int length = 1;
    int i = 0;
    int nb = 0;
    int temp_score = 0;
    char *str = malloc(length * sizeof(char));

    length = case_length(score, length, temp_score);
    if (str == NULL)
        return NULL;
    i = length - 2;
    str[length - 1] = '\0';
    str = push_str(str, score, i, nb);
    return str;
}
