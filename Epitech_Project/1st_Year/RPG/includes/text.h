/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** text
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "utils.h"

#define TEXT_SIZE 50
#define TEXT_COLOR sfWhite
#define PATH_FONT "assets/fonts/sedanfont.ttf"

typedef struct info_text_s {
    off_set_t off_set;
    sfVector2f scale;
    const sfText *text;
} info_text_t;

bool loadglobalfont(const char *fontPath);
void freeglobalfont(void);
sfText *create_text(const char *str);
void display_text(sfRenderWindow *window, sfText *text, sfVector2f pos,
    sfVector2f scale);
void destroy_text(sfText *text);
void display_text_on_screen(sfView *view, sfRenderWindow *window,
    info_text_t info_text);
