/*
** EPITECH PROJECT, 2024
** menu_tools.c
** File description:
** parameter of tools menu
*/

#include "my_project.h"

void action_menu_filter(win_t *win, canva_t *canva, menu_t *menu)
{
    opt_t *cpy = menu->options;

    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button))
        xray_filter(canva);
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button))
        invert_color(canva);
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button))
        black_and_white(canva);
    cpy = cpy->next;
}

void action_menu_help(win_t *win, canva_t *canva, menu_t *menu)
{
    opt_t *cpy = menu->options;

    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button))
        doc_loop(menu);
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button)) {
        sfRenderWindow_setMouseCursorVisible(win->win, sfTrue);
        aboutus_loop(menu, win);
        sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
    }
}

static int fonction_tool_size(int count)
{
    if (count == 1)
        return 1;
    if (1 < count && count <= 5)
        return 2 * count - 1;
    if (count < 5 && count <= 8)
        return 5 * count - 10;
    return 5 * count - 20;
}

void action_menu(win_t *win, canva_t *canva, menu_t *menu)
{
    opt_t *cpy = menu->options;

    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button))
        export_all(win->envp, canva, menu);
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && is_button_pressed(win->event, cpy->button))
        import_all(win->envp, canva, menu);
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && (is_button_pressed(win->event, cpy->button)
    || cpy->button->state == PRESSED))
        new_file(canva, 1536, 864);
}

static void action_two_menu_tool(menu_t *menu, canva_t *canva, win_t *win,
    opt_t *cpy)
{
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && (is_button_pressed(win->event, cpy->button)
    || cpy->button->state == PRESSED)) {
        menu->state = RELEASED;
        canva->tool = HAND;
        switch_crossair(win, win->crossair_tab, canva);
        return;
    }
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && (is_button_pressed(win->event, cpy->button)
    || cpy->button->state == PRESSED)) {
        menu->state = RELEASED;
        canva->tool = PIPETTE;
        switch_crossair(win, win->crossair_tab, canva);
        return;
    }
}

void action_menu_tool(win_t *win, canva_t *canva, menu_t *menu)
{
    opt_t *cpy = menu->options;

    if (menu->state == PRESSED && canva->tool == NONE
    && (is_button_pressed(win->event, cpy->button)
    || cpy->button->state == PRESSED)) {
        menu->state = RELEASED;
        canva->tool = PENCIL;
        switch_crossair(win, win->crossair_tab, canva);
        return;
    }
    cpy = cpy->next;
    if (menu->state == PRESSED && canva->tool == NONE
    && (is_button_pressed(win->event, cpy->button)
    || cpy->button->state == PRESSED)) {
        menu->state = RELEASED;
        canva->tool = RUBBER;
        switch_crossair(win, win->crossair_tab, canva);
        return;
    }
    action_two_menu_tool(menu, canva, win, cpy);
}

void action_size_tool(win_t *win, canva_t *canva, menu_t *menu, button_t *but)
{
    opt_t *cpy = menu->options;
    int count = 1;
    sfVector2f pos;

    while (cpy) {
        if (menu->state == PRESSED && canva->tool == NONE
        && (is_button_pressed(win->event, cpy->button)
        || cpy->button->state == PRESSED)) {
            menu->state = RELEASED;
            canva->tools_size = fonction_tool_size(count);
            pos = but->slide_size->start_pos;
            pos.x = (but->slide_size->start_pos.x - 5) +
                ((140 * canva->tools_size) / but->slide_size->max_value);
            pos.y -= 3;
            sfRectangleShape_setPosition(but->slide_size->cross, pos);
            return;
        }
        cpy = cpy->next;
        count++;
    }
}
