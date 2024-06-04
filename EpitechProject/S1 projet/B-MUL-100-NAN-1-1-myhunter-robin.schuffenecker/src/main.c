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

void game_init(base_st *var)
{
    var->score = 0;
    var->ship.speed = 15;
    var->ship_two.speed_two = 8;
    var->bool = 0;
    var->music = sfMusic_createFromFile("content/main_music.wav");
    var->shoot = sfMusic_createFromFile("content/shoot.wav");
    var->window = create_renderwindow(1920, 1080, 32, "HUNTER");
    sprite_init(var);
    var->text = sfText_create();
    var->clock_ship = sfClock_create();
    sfRenderWindow_setFramerateLimit(var->window, 60);
    music_init(var);
}

void end_game(base_st *var)
{
    if (var->life.rect.left >= 1500) {
        var->bool = 2;
    }
}

int game_base(void)
{
    base_st *var = malloc(sizeof(base_st));
    sfEvent event;

    srand(time(NULL));
    game_init(var);
    while (sfRenderWindow_isOpen(var->window)) {
        mouse_event(var, event);
        close_window(var, event);
        sfRenderWindow_clear(var->window, sfBlack);
        run_menu(var);
        run_game(var);
        aim_init(&var->aim, var);
        end_game(var);
        run_end(var);
        sfRenderWindow_display(var->window);
        printf("%i\n", var->score);
    }
    destroy_texture(var);
    destroy_sprite(var);
    return 0;
}

int main(int argc, char const **argv)
{
    if (argc == 1) {
        game_base();
        return 0;
    }
    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Hunter est un jeu basé uniquement sur la précision.\n");
        my_putstr("Appuyez sur [CLIQUE GAUCHE] pour tirer.\n");
        my_putstr("Appuyez sur [ECHAP] pour quitter.\n");
    } else {
        return 84;
    }
    return 0;
}
