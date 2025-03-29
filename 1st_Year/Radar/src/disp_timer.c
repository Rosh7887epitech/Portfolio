/*
** EPITECH PROJECT, 2024
** timer
** File description:
** timer
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

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

void timer(base_st *var)
{
    int time = sfTime_asSeconds(sfClock_getElapsedTime(var->temps));
    char *second;
    sfFont *font = sfFont_createFromFile("content/Technology.ttf");
    sfText *horloge = sfText_create();

    second = my_itoa(time);
    sfText_setString(horloge, second);
    sfText_setFont(horloge, font);
    sfText_setCharacterSize(horloge, 80);
    sfText_setColor(horloge, sfWhite);
    sfText_setPosition(horloge, (sfVector2f){1830.0, 0.0});
    sfRenderWindow_drawText(var->window, horloge, NULL);
}
