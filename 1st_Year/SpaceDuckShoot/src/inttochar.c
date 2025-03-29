/*
** EPITECH PROJECT, 2023
** intochar
** File description:
** inttochar
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

#include <stdlib.h>

char *my_itoa(int score)
{
    int length = 1;
    int i = 0;
    int nb = 0;
    int temp_score = 0;
    char *str = malloc(length * sizeof(char));

    if (score == 0) {
        length++;
    } else {
        temp_score = score;
        while (temp_score != 0) {
            temp_score /= 10;
            length++;
        }
    }
    if (str == NULL) {
        return NULL;
    }
    i = length - 2;
    str[length - 1] = '\0';

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

