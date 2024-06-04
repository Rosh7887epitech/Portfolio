/*
** EPITECH PROJECT, 2024
** itoa
** File description:
** itoa
*/

#include "../include/hashtable.h"

int case_length(int score, int length, int temp_score)
{
    if (score < 0) {
        length++;
        temp_score = -score;
    } else
        temp_score = score;
    if (temp_score == 0)
        length++;
    else {
        while (temp_score != 0) {
            temp_score /= 10;
            length++;
        }
    }
    return length;
}

char *push_str(char *str, int score, int i, int nb)
{
    if (score == 0)
        str[i] = '0';
    else {
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
    int temp_score = score < 0 ? -score : score;
    char *str;

    length = case_length(score, length, temp_score);
    str = (char *)malloc(length * sizeof(char));
    if (str == NULL)
        return NULL;
    str[length - 1] = '\0';
    if (score < 0) {
        str[0] = '-';
        score = -score;
    }
    push_str(str, score, length - 2, 0);
    return str;
}
