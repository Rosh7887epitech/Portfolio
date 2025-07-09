/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** display_text
*/

#include <stdio.h>
#include "text.h"
#include "utils.h"

void display_text(sfRenderWindow *window, sfText *text, sfVector2f pos,
    sfVector2f scale)
{
    sfText_setPosition(text, pos);
    sfText_setScale(text, scale);
    sfRenderWindow_drawText(window, text, NULL);
}

void display_text_on_screen(sfView *view, sfRenderWindow *window,
    info_text_t info_text)
{
    sfVector2f pos = sfView_getCenter(view);
    sfVector2f scale = info_text.scale;
    sfText *text = (sfText *)info_text.text;

    pos = vector_edition(pos, info_text.off_set.x, info_text.off_set.y);
    display_text(window, text, pos, scale);
}
