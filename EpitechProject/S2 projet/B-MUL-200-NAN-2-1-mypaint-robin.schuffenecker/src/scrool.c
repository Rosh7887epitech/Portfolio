/*
** EPITECH PROJECT, 2024
** scrool.c
** File description:
** that file should permit to scrool into the file for export
*/
#include "my_project.h"

static sfBool is_modifiable(int mult, file_t *file)
{
    sfVector2f pos;

    if (mult == -1) {
        pos = sfRectangleShape_getPosition(file->butt[0]->rect);
        if (pos.y < 100)
            return sfTrue;
        return sfFalse;
    } else {
        while (file->next != NULL)
            file = file->next;
        pos = sfRectangleShape_getPosition(file->butt[0]->rect);
        if (pos.y >= 50)
            return sfTrue;
        return sfFalse;
    }
}

void modify_position(file_t *file, int mult)
{
    sfVector2f pos;

    if (is_modifiable(mult, file))
        return;
    while (file) {
        pos = sfRectangleShape_getPosition(file->butt[0]->rect);
        pos.y += (mult * 40);
        sfRectangleShape_setPosition(file->butt[0]->rect, pos);
        pos = sfText_getPosition(file->text);
        pos.y += (mult * 40);
        sfText_setPosition(file->text, pos);
        pos = sfRectangleShape_getPosition(file->butt[1]->rect);
        pos.y += (mult * 40);
        sfRectangleShape_setPosition(file->butt[1]->rect, pos);
        file = file->next;
    }
}
