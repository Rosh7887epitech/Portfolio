/*
** EPITECH PROJECT, 2024
** create_drop_menu.c
** File description:
** that function should initialize drop menu
*/

#include "../include/my_project.h"
static void modify_option_hover(obj_t *button, win_t *win)
{
    sfColor color = (sfColor){255, 255, 255, 255};

    if (is_button_hover(button, &win->event.mouseMove)) {
        color = (sfColor) {200, 200, 200, 255};
        sfRectangleShape_setFillColor(button->rect, color);
    } else
        sfRectangleShape_setFillColor(button->rect, color);
    return;
}

sfBool is_option_clicked(sfEvent event, opt_t *option)
{
    while (option) {
        if (option->button->is_clicked(option->button, &event.mouseButton)) {
            option->button->state = PRESSED;
            return sfTrue;
        }
        option = option->next;
    }
    return sfFalse;
}

void add_menu_option(opt_t **option, sfVector2f pos, sfVector2f size,
    char *text)
{
    opt_t *new = malloc(sizeof(opt_t));

    new->button = init_button(pos, size, sfGreen, NULL);
    sfRectangleShape_setFillColor(new->button->rect, sfWhite);
    new->next = NULL;
    pos.x += 3;
    new->text = create_text(text, pos, "img/font.ttf");
    sfText_setFillColor(new->text, sfBlack);
    if (*option != NULL)
        new->next = *option;
    *option = new;
    return;
}

menu_t *init_menu(sfVector2f pos, sfVector2f size, char *text)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfColor gris = sfColor_fromRGBA(74, 77, 81, 255);

    menu->button = init_button(pos, size, gris, NULL);
    menu->options = NULL;
    pos.x += 10;
    pos.y -= 3;
    menu->text = create_text(text, pos, "img/font.ttf");
    menu->state = RELEASED;
    return menu;
}

void show_option(win_t *win, opt_t *option, int state, canva_t *canva)
{
    if (state == PRESSED && canva->tool == NONE) {
        while (option) {
            modify_option_hover(option->button, win);
            sfRenderWindow_drawRectangleShape(win->win, option->button->rect,
                sfFalse);
            sfRenderWindow_drawText(win->win, option->text, NULL);
            option = option->next;
        }
    }
}

static void reset_option_state(menu_t *menu)
{
    opt_t *cpy = menu->options;

    while (cpy) {
        cpy->button->state = RELEASED;
        cpy = cpy->next;
    }
}

static void reset_menu_state(menu_t **menu)
{
    for (int i = 0; i < 4; i++) {
        menu[i]->state = RELEASED;
        reset_option_state(menu[i]);
    }
}

static sfBool clic_menu(int status, menu_t **tab, int index, win_t *win)
{
    if (status && tab[index]->state == PRESSED) {
        win->event.type = sfEvtMouseButtonReleased;
        tab[index]->state = RELEASED;
        reset_option_state(tab[index]);
        return sfTrue;
    }
    return sfFalse;
}

static void hide_menu(int status, menu_t **tab, int index, win_t *win)
{
    sfColor color = (sfColor){74, 77, 81, 255};

    if (sfMouse_isButtonPressed(sfMouseLeft) && !status
        && tab[index]->state == PRESSED) {
        win->event.type = sfEvtMouseButtonReleased;
        tab[index]->state = RELEASED;
        reset_option_state(tab[index]);
    }
    if (tab[index]->state == RELEASED) {
        sfRectangleShape_setFillColor(tab[index]->button->rect, color);
        sfText_setCharacterSize(tab[index]->text, 20);
    }
}

void modify_menu_state(menu_t **tab, canva_t *canva, win_t *win, int index)
{
    sfBool status = is_button_pressed(win->event, tab[index]->button);

    if (status && tab[index]->state != PRESSED) {
        canva->tool = NONE;
        reset_menu_state(tab);
        win->event.type = sfEvtMouseButtonReleased;
        tab[index]->state = PRESSED;
        sfRectangleShape_setFillColor(tab[index]->button->rect,
            (sfColor){48, 48, 48, 255});
        sfText_setCharacterSize(tab[index]->text, 18);
        switch_crossair(win, win->crossair_tab, canva);
        return;
    }
    if (clic_menu(status, tab, index, win))
        return;
    hide_menu(status, tab, index, win);
    return;
}
