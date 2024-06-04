/*
** EPITECH PROJECT, 2023
** main
** File description:
** main graphical
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y,
    unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize |
            sfClose, NULL));
}

void game_init(base_st *var, circle_st **shape)
{
    var->ship.speed = 15;
    var->nb_c = 100;
    var->window = create_renderwindow(1920, 1080, 32, "RADAR");
    (*shape)->c = NULL;
    for (int i = 0; i < var->nb_c; i++)
        circle_init(var, shape, rand() % 1870, rand() % 980);
    sfRenderWindow_setFramerateLimit(var->window, 60);
}

int game_base(void)
{
    base_st *var = malloc(sizeof(base_st));
    circle_st *shape = malloc(sizeof(circle_st));
    sfEvent event;

    srand(time(NULL));
    game_init(var, &shape);
    while (sfRenderWindow_isOpen(var->window)) {
        close_window(var, event);
        sfRenderWindow_display(var->window);
        sfRenderWindow_clear(var->window, sfTransparent);
        draw_circle(shape, var);
        verif_collision(shape);
    }
    return 0;
}

int main(int argc, char const **argv)
{
    if (argc == 1) {
        game_base();
        return 0;
    }
    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("My radar est une simulation de vol en temp réel\n");
        my_putstr("Les positions de départ son aléatoire\n");
    } else {
        return 84;
    }
    return 0;
}
