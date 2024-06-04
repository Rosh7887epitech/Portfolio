/*
** EPITECH PROJECT, 2024
** export_all.c
** File description:
** that function should handle the export
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_project.h"
#include <string.h>
#include <dirent.h>
#include <unistd.h>

static void show_export_file(file_t *file, sfRenderWindow *win)
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

static void init_text_zone(sfVector2f pos, struct input_s *input, char **envp)
{
    input->input = malloc(sizeof(char) * 30);
    input->pwd = find_pwd(envp);
    input->input[0] = '\0';
    pos.y += 3;
    input->text = create_text("Enter your file name", pos, "img/roboto.ttf");
    sfText_setCharacterSize(input->text, 25);
    sfText_setFillColor(input->text, sfWhite);
    input->shape = sfRectangleShape_create();
    pos = (sfVector2f){pos.x - 10, pos.y - 3};
    sfRectangleShape_setPosition(input->shape, pos);
    sfRectangleShape_setFillColor(input->shape, (sfColor){155, 155, 155, 255});
    sfRectangleShape_setSize(input->shape, (sfVector2f){450, 40});
    input->send = init_button((sfVector2f){480, pos.y + 2},
    (sfVector2f){100, 35}, (sfColor){98, 121, 204, 255}, NULL);
    input->send_text = create_text("Export",
    (sfVector2f){495, pos.y + 5}, "img/calibri.ttf");
    input->go_back = init_button((sfVector2f){10, 10},
        (sfVector2f){500, 30}, (sfColor){155, 155, 155, 255}, NULL);
    input->back_img = init_button((sfVector2f){13, 13}, (sfVector2f){25, 25},
        sfGreen, "img/back_arrow.png");
}

static char *navigate_file(file_t **file, sfEvent *event, char *pwd)
{
    file_t *new = NULL;
    file_t *cpy = *file;
    sfVector2f pos;

    while (cpy) {
        pos = sfRectangleShape_getPosition(cpy->butt[0]->rect);
        if (file_is_pressed(*event, cpy->butt[0])
            && pos.y < 500 && pos.y > 0) {
            event->type = sfEvtMouseButtonReleased;
            pwd = my_strcat(pwd, my_strcat("/", (cpy)->filename));
            open_export_file(&new, pwd);
            *file = new;
            return pwd;
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
        open_export_file(&new, input->pwd);
        *file = new;
    }
}

sfBool send_export(sfEvent event, input_t *input, sfRenderWindow *win,
    canva_t *canva)
{
    char *tmp = NULL;

    if (file_is_pressed(event, input->send)) {
        if (input->input[0] == '\0' || input->input == NULL) {
            sfRectangleShape_setOutlineColor(input->shape, sfRed);
            sfRectangleShape_setOutlineThickness(input->shape, 2);
            return sfFalse;
        } else {
            sfRectangleShape_setOutlineThickness(input->shape, 0.0);
            tmp = my_strcat(input->pwd, my_strcat("/", input->input));
            all_my_concat(canva, tmp);
            free(tmp);
            sfRenderWindow_close(win);
            return sfTrue;
        }
    }
    return sfFalse;
}

static void all_draw(sfRenderWindow *window, file_t *file, input_t *input,
    sfRectangleShape *back)
{
    sfRenderWindow_drawRectangleShape(window, back, NULL);
    sfRenderWindow_drawRectangleShape(window, input->shape, NULL);
    show_export_file(file, window);
    sfRenderWindow_drawRectangleShape(window, input->send->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, input->go_back->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, input->back_img->rect, NULL);
    sfRenderWindow_drawText(window, input->text, NULL);
    sfRenderWindow_drawText(window, input->send_text, NULL);
}

int evenement_export(sfRenderWindow *window, sfEvent *event, input_t *input,
    file_t *file)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        text_input(*event, input);
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

win_t *init_export_win(int size)
{
    win_t *win = malloc(sizeof(win_t));
    sfVideoMode mode = {size, size, 1};

    win->win = sfRenderWindow_create(mode, "Export", sfClose, NULL);
    win->background = init_rectshape((sfVector2f){0, 0},
    (sfVector2f){size, size}, (sfColor){85, 91, 97, 255}, NULL);
    sfRenderWindow_setPosition(win->win, (sfVector2i){0, 0});
    return win;
}

void export_all(char **envp, canva_t *canva, menu_t *menu)
{
    input_t *input = malloc(sizeof(input_t));
    file_t *file = NULL;
    win_t *win = init_export_win(600);

    init_text_zone((sfVector2f){20, 550}, input, envp);
    sfRectangleShape_setOutlineColor(input->back_img->rect, sfTransparent);
    open_export_file(&file, input->pwd);
    while (sfRenderWindow_isOpen(win->win)) {
        evenement_export(win->win, &win->event, input, file);
        sfRenderWindow_clear(win->win, sfBlack);
        input->pwd = navigate_file(&file, &win->event, input->pwd);
        nav_back(&file, input, &win->event, input->go_back);
        if (send_export(win->event, input, win->win, canva))
            break;
        all_draw(win->win, file, input, win->background);
        sfRenderWindow_display(win->win);
    }
    free_new_all(input, win->win, &file, win->background);
    menu->state = RELEASED;
    menu->options->button->state = RELEASED;
}
