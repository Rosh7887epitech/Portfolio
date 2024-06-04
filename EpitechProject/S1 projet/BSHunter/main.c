/*
** EPITECH PROJECT, 2023
** main
** File description:
** main graphical
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

int main(void)
{
    sfRenderWindow *window = create_renderwindow(800, 600, 32, "SPRITE");
    sfEvent event;
    sfTexture *my_texture = sfTexture_createFromFile("spritesheet.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f my_pos = {20, 20};
    sfVector2f scale = {0.5, 0.5};
    sfIntRect rect;

    set_sprite(my_texture, my_sprite, my_pos, scale);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event);
            display(window, my_sprite, rect, my_texture);
        }
    }
    return 0;
}
