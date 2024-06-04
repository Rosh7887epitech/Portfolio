/*
** EPITECH PROJECT, 2024
** import_all.c
** File description:
** that function should handle the import
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_project.h"
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

static void show_import_file(file_t *file, sfRenderWindow *win)
{
    sfVector2f pos;

    while (file) {
        pos = sfRectangleShape_getPosition(file->butt[0]->rect);
        if (pos.y < 500 && pos.y > 0) {
            sfRenderWindow_drawRectangleShape(win, file->butt[0]->rect, NULL);
            sfRenderWindow_drawRectangleShape(win, file->butt[1]->rect, NULL);
            sfRenderWindow_drawText(win, file->text, NULL);
        }
        file = file->next;
    }
}

static sfBool file_is_pressed(sfEvent event, obj_t *button)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (button->is_clicked(button, &event.mouseButton)) {
            sfSleep(sfSeconds(0.2));
            return sfTrue;
        }
    }
    return sfFalse;
}

static input_t *init_input(char **envp)
{
    input_t *input = malloc(sizeof(input_t));

    input->pwd = find_pwd(envp);
    input->go_back = init_button((sfVector2f){10, 10},
    (sfVector2f){500, 30}, (sfColor){155, 155, 155, 255}, NULL);
    input->back_img = init_button((sfVector2f){13, 13}, (sfVector2f){25, 25},
        sfGreen, "img/back_arrow.png");
    sfRectangleShape_setOutlineColor(input->back_img->rect, sfTransparent);
    return input;
}

static char *move_file(sfEvent *event, file_t *cpy, char *pwd, file_t **file)
{
    sfVector2f pos = sfRectangleShape_getPosition(cpy->butt[0]->rect);
    file_t *new = NULL;

    if (file_is_pressed(*event, (cpy)->butt[0]) && pos.y < 500 && pos.y > 0
    && !is_image(cpy->filename)) {
        event->type = sfEvtMouseButtonReleased;
        pwd = my_strcat(pwd, my_strcat("/", (cpy)->filename));
        open_file(&new, pwd);
        *file = new;
        return pwd;
    }
    return pwd;
}

static char *nav_impo(file_t **file, sfEvent *event, char *pwd, canva_t *canva)
{
    file_t *cpy = *file;
    sfVector2f pos;
    char *tmp = NULL;

    while (cpy) {
        pos = sfRectangleShape_getPosition(cpy->butt[0]->rect);
        tmp = move_file(event, cpy, pwd, file);
        if (my_strcmp(tmp, pwd) != 0)
            return tmp;
        if (file_is_pressed(*event, cpy->butt[0]) && pos.y < 500 && pos.y > 0
        && is_image(cpy->filename)) {
            import_my(canva, my_strcat(pwd, my_strcat("/", (cpy)->filename)));
            return NULL;
        }
        cpy = cpy->next;
    }
    return pwd;
}

static void nav_back(file_t **file, input_t *input, sfEvent *event, obj_t *but)
{
    file_t *new = NULL;

    if (file_is_pressed(*event, but)) {
        if (is_home(input->pwd))
            return;
        for (int i = my_strlen(input->pwd); i > 0 && input->pwd[i] != '/'; i--)
            input->pwd[i] = '\0';
        if (input->pwd[my_strlen(input->pwd) - 1] == '/')
            input->pwd[my_strlen(input->pwd) - 1] = '\0';
        while (*file) {
            new = (*file)->next;
            free(*file);
            *file = new;
        }
        new = NULL;
        open_file(&new, input->pwd);
        *file = new;
    }
}

static void all_draw(sfRenderWindow *window, file_t *file, input_t *input,
    sfRectangleShape *back)
{
    sfRenderWindow_drawRectangleShape(window, back, NULL);
    show_import_file(file, window);
    sfRenderWindow_drawRectangleShape(window, input->go_back->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, input->back_img->rect, NULL);
}

int evenement_import(sfRenderWindow *window, sfEvent *event, file_t *file)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    if (event->type == sfEvtMouseWheelScrolled && len_list(file) > 12) {
        if (event->mouseWheelScroll.delta > 0) {
            modify_position(file, 1);
        } else {
            modify_position(file, -1);
        }
        event->type = sfEvtLostFocus;
        return 0;
    }
    return 1;
}

win_t *import_init_window(int size)
{
    win_t *win = malloc(sizeof(win_t));
    sfVideoMode mode = {size, size, 1};

    win->win = sfRenderWindow_create(mode, "Import", sfClose, NULL);
    win->background = init_rectshape((sfVector2f){0, 0},
    (sfVector2f){size, size}, (sfColor){85, 91, 97, 255}, NULL);
    sfRenderWindow_setPosition(win->win, (sfVector2i){0, 0});
    return win;
}

void import_all(char **envp, canva_t *canva, menu_t *menu)
{
    int size = 600;
    input_t *input = init_input(envp);
    file_t *file = NULL;
    win_t *win = import_init_window(size);

    open_file(&file, input->pwd);
    while (sfRenderWindow_isOpen(win->win)) {
        evenement_import(win->win, &win->event, file);
        sfRenderWindow_clear(win->win, sfBlack);
        input->pwd = nav_impo(&file, &win->event, input->pwd, canva);
        if (input->pwd == NULL)
            break;
        nav_back(&file, input, &win->event, input->go_back);
        all_draw(win->win, file, input, win->background);
        sfRenderWindow_display(win->win);
    }
    free_import(win, &file, input);
    menu->state = RELEASED;
    menu->options->button->state = RELEASED;
}
