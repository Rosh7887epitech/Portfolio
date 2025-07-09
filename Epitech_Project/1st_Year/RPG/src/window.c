/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** window
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"
#include "macro.h"

sfRenderWindow *create_window(char *title, sfVideoMode mode)
{
    sfRenderWindow *window = sfRenderWindow_create(mode, title,
    sfResize | sfClose, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}
