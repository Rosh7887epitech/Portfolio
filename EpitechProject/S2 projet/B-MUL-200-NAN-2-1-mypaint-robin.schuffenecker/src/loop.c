/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** that function should be the main of our program
*/

#include "my_project.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

static void free_tab_list(layer_t *layer, win_t *win)
{
    sfRectangleShape_destroy(win->background);
    sfSprite_destroy(win->crosshair);
    sfRenderWindow_destroy(win->win);
    if (layer)
        free(layer);
    for (int i = 0; win->crossair_tab[i] != NULL; i++)
        free(win->crossair_tab[i]);
    free(win->crossair_tab);
    free(win);
}

static void free_all(win_t *win, canva_t *canva, button_t *button)
{
    layer_t *layer = NULL;

    while (canva->layer) {
        layer = canva->layer->next;
        free(canva->layer->uint_tab);
        for (int i = 0; i <= 1; i++) {
            sfRectangleShape_destroy(canva->layer->button[i]->rect);
            free(canva->layer->button[i]);
        }
        free(canva->layer->button);
        sfSprite_destroy(canva->layer->screen_sprite);
        sfTexture_destroy(canva->layer->texture);
        free(canva->layer);
        canva->layer = layer;
    }
    free(canva);
    free_tab_list(layer, win);
    free_button(button);
}

static int sec_action(win_t *win, canva_t *canva, button_t *button)
{
    if (canva->tool == PENCIL) {
        modify_sfuint8(win, canva);
        return 0;
    }
    if (canva->tool == RUBBER) {
        our_eraser(win, canva);
        return 0;
    }
    if (canva->tool == COLOR) {
        change_color(win, canva, button);
        button->slide_trans->start_pos.y = 188 - 5;
        sfRectangleShape_setPosition(button->slide_trans->cross,
            button->slide_trans->start_pos);
        return 0;
    }
    return 1;
}

void tools_action(win_t *win, canva_t *canva, button_t *button)
{
    if (sec_action(win, canva, button) != 1)
        return;
    if (canva->tool == HAND) {
        move_canva(win, canva);
        return;
    }
    if (canva->tool == PIPETTE) {
        our_pipette(win, canva, button);
        return;
    }
}

static void draw_menu(win_t *win, button_t *butt, canva_t *canva, int index)
{
    sfRenderWindow_drawRectangleShape(win->win,
        butt->menu[index]->button->rect, NULL);
    sfRenderWindow_drawText(win->win, butt->menu[index]->text, NULL);
    show_option(win, butt->menu[index]->options,
        butt->menu[index]->state, canva);
}

static void draw_menus(win_t *win, button_t *butt, canva_t *canva)
{
    for (int i = 0; i < 7; i++)
        draw_menu(win, butt, canva, i);
}

static void change_over_state(button_t *butt, win_t *win)
{
    sfColor color = (sfColor){74, 77, 81, 255};

    for (int i = 0; i < 5; i++) {
        if (butt->menu[i]->button->state == PRESSED) {
            color = (sfColor){74, 77, 81, 255};
            sfRectangleShape_setFillColor(butt->menu[i]->button->rect, color);
        }
        if (is_button_hover(butt->menu[i]->button, &win->event.mouseMove)) {
            color = (sfColor) {24, 27, 31, 255};
            sfRectangleShape_setFillColor(butt->menu[i]->button->rect, color);
            color = (sfColor){74, 77, 81, 255};
            continue;
        }
        if (butt->menu[i]->state != PRESSED) {
            sfRectangleShape_setFillColor(butt->menu[i]->button->rect, color);
            sfText_setCharacterSize(butt->menu[i]->text, 20);
        }
    }
}

static void all_menu_action(button_t *butt, win_t *win, canva_t *canva)
{
    if (win->event.type == sfEvtMouseButtonPressed) {
        action_menu(win, canva, butt->menu[0]);
        action_menu_tool(win, canva, butt->menu[1]);
        action_size_tool(win, canva, butt->menu[3], butt);
        action_menu_help(win, canva, butt->menu[2]);
        action_menu_filter(win, canva, butt->menu[4]);
        for (int i = 0; i <= 4; i++)
            modify_menu_state(butt->menu, canva, win, i);
    }
    if (win->event.type == sfEvtMouseMoved) {
        change_over_state(butt, win);
    }
}

static void all_my_draw(win_t *win, canva_t *canva, button_t *butt)
{
    sfRenderWindow_drawRectangleShape(win->win, win->background, NULL);
    draw_canva(canva, win);
    sfRenderWindow_drawRectangleShape(win->win, win->gui, NULL);
    sfRenderWindow_drawRectangleShape(win->win, win->gui_left, NULL);
    sfRenderWindow_drawRectangleShape(win->win, win->gui_canva, NULL);
    sfRenderWindow_drawRectangleShape(win->win, win->gui_right, NULL);
    draw_tools_button(win, butt);
    draw_canva_layer(win, canva->layer);
    draw_palette(butt->palette_couleur, butt->contour, win, canva->tool);
    draw_menus(win, butt, canva);
}

int windows_loop(char **envp)
{
    win_t *win = init_window();
    canva_t *canva = init_canva(1536, 864, (sfVector2f){1740, 500});
    button_t *butt = create_buttons(win->crossair_tab);

    win->envp = envp;
    while (sfRenderWindow_isOpen(win->win)) {
        sfRenderWindow_clear(win->win, sfBlack);
        evenement_user(win, canva, butt);
        all_my_draw(win, canva, butt);
        all_menu_action(butt, win, canva);
        all_slide(win, canva, butt);
        move_crosshair(win);
        sfRenderWindow_display(win->win);
    }
    free_all(win, canva, butt);
    return 0;
}
