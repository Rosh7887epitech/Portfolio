/*
** EPITECH PROJECT, 2023
** main
** File description:
** main graphical
*/

#include "../include/game.h"
#include "../include/my.h"
#include "../include/include.h"

static int error_case(int argc, char const **argv)
{
    if (argc < 2) {
        my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
        my_putstr("retry with -h\n");
        return 84;
    }
    if (argv[2] != NULL) {
        my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
        my_putstr("retry with -h\n");
        return 84;
    }
}

int filereader(base_st *var, char const **argv)
{
    struct stat sb;
    char *buff;
    int fd = open(argv[1], O_RDONLY);

    if (stat(argv[1], &sb) == -1) {
        my_putstr("error wrong file\n");
        return 84;
    }
    buff = malloc(sizeof(char) * sb.st_size + 2);
    if (buff == NULL || fd == -1 || read(fd, buff, sb.st_size) != sb.st_size) {
        close(fd);
        return 84;
    }
    buff[sb.st_size] = '\0';
    var->path.row = length(buff);
    var->path.map = load_2d_arr_from_file(buff, var);
    return 0;
}

sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y,
    unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize |
            sfClose, NULL));
}

int game_init(base_st *var, tower_st **tow,
    circle_st **shape, char const **argv)
{
    var->l_touch = 0;
    var->s_touch = 0;
    var->temps = sfClock_create();
    if (filereader(var, argv) == 84)
        return 84;
    init_search(var, shape, tow);
    var->window = create_renderwindow(1920, 1080, 32, "RADAR");
    var->back = background();
    for (int i = 0; i < var->nb_c; i++) {
        circle_init(var, shape);
    }
    for (int i = 0; i < var->nb_t; i++) {
        tower_circle_init(var, tow);
    }
    pos_search(var, shape, tow);
    sfRenderWindow_setFramerateLimit(var->window, 60);
    return 0;
}

int game_base(char const **argv)
{
    base_st *var = malloc(sizeof(base_st));
    circle_st *shape = NULL;
    tower_st *tow = NULL;
    quad_st *dir;
    sfEvent event;

    srand(time(NULL));
    if (game_init(var, &tow, &shape, argv) == 84)
        return 84;
    while (sfRenderWindow_isOpen(var->window)) {
        sfRenderWindow_clear(var->window, sfTransparent);
        close_window(var, shape, event);
        sfRenderWindow_drawSprite(var->window, var->back, NULL);
        game(var, tow, shape);
        sfRenderWindow_display(var->window);
    }
    return 0;
}

int main(int argc, char const **argv)
{
    if (error_case(argc, argv) == 84)
        return 84;
    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Air traffic simulation panel\n\nUSAGE\n");
        my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
        my_putstr("   path_to_script\tThe path to the script file.\n\n");
        my_putstr("OPTION\n  -h\t\t\tprint the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr("  'L' key\t\tenable/disable hitboxes and areas.\n");
        my_putstr("  'S' key\t\tenable/disable sprites.\n");
    }
    if (argc >= 2 && argv[1][0] != '-' && argv[1][1] != 'h') {
        if (game_base(argv) == 84)
            return 84;
        return 0;
    }
    return 0;
}
