/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-robin.schuffenecker
** File description:
** aboutus
*/

#include "my_project.h"

static char *find_user(char **envp)
{
    if (envp == NULL)
        return NULL;
    for (int i = 0; envp[i] != NULL; i++)
        if (my_strncmp(envp[i], "USER=", 5) == 0)
            return my_strdup(envp[i] + 5);
    return NULL;
}

static int evenement_aboutus(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            sfRenderWindow_close(win->win);
            return 0;
        }
    }
    return 1;
}

static win_t *init_about_window(void)
{
    sfVideoMode win_size = {400, 100, 0};
    win_t *window = malloc(sizeof(win_t));

    window->win = sfRenderWindow_create(win_size, "About", sfClose, NULL);
    window->background = init_rectshape((sfVector2f){0, 0},
        (sfVector2f){400, 500}, (sfColor){67, 86, 156, 255}, NULL);
    sfRenderWindow_setFramerateLimit(window->win, 60);
    sfRenderWindow_setPosition(window->win, (sfVector2i){1920 / 3, 1080 / 3});
    return window;
}

static void free_about_us(win_t *win)
{
    free(win);
}

void aboutus_loop(menu_t *menu, win_t *windows_setting)
{
    char *user = find_user(windows_setting->envp);
    win_t *win = init_about_window();
    sfText *text;

    if (user == NULL)
        user = my_strdup("No user $variable set");
    text = create_text(user, (sfVector2f){50, 0}, "img/font.ttf");
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 100);
    while (sfRenderWindow_isOpen(win->win)) {
        sfRenderWindow_clear(win->win, sfTransparent);
        evenement_aboutus(win);
        sfRenderWindow_drawRectangleShape(win->win, win->background, sfFalse);
        sfRenderWindow_drawText(win->win, text, sfFalse);
        sfRenderWindow_display(win->win);
    }
    free_about_us(win);
    menu->state = RELEASED;
}
