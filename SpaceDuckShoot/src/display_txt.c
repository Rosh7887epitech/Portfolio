/*
** EPITECH PROJECT, 2023
** txt
** File description:
** txt
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

void display_txt(base_st *var)
{
    sfFont *font;
    sfColor color;

    font = sfFont_createFromFile("content/sakana.ttf");
    color.r = 151;
    color.b = 155;
    color.g = 115;
    color.a = 100;
    var->score_l.pos.x = 540;
    var->score_l.pos.x = 540;
    var->str = my_itoa(var->score);
    sfText_setPosition(var->text, var->score_l.pos);
    sfText_setCharacterSize(var->text, 20);
    sfText_setColor(var->text, color);
    sfText_setString(var->text, var->str);
    sfText_setFont(var->text, font);
    sfRenderWindow_drawText(var->window, var->text, NULL);
}
