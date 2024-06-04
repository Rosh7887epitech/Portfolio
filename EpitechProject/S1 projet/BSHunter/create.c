/*
** EPITECH PROJECT, 2023
** create
** File description:
** create windows
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y,
    unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfDefaultStyle, NULL));
}
