/*
** EPITECH PROJECT, 2023
** gmae
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>

void set_sprite(sfTexture *my_texture, sfSprite *my_sprite,
    sfVector2f my_pos, sfVector2f scale);
void display(sfRenderWindow *window, sfSprite *my_sprite,
    sfIntRect rect, sfTexture *my_texture);
void set_sprite(sfTexture *my_texture, sfSprite *my_sprite,
    sfVector2f my_pos, sfVector2f scale);
sfRenderWindow *create_renderwindow(unsigned int x,
    unsigned int y, unsigned int bpp, char *title);
void analyse_events(sfRenderWindow *window, sfEvent event);
void close_window(sfRenderWindow *window, sfEvent event);
void manage_mouse_click(sfMouseButtonEvent event, sfRenderWindow *window);
void size_of_sprite(sfIntRect rect, sfSprite *my_sprite,
    sfTexture *my_texture);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);


#endif /* !game */
