/*
** EPITECH PROJECT, 2024
** create_crossair.c
** File description:
** that function should modify the crossair
*/
#include "my_project.h"
#include <string.h>

char **create_crossair_tab(void)
{
    char **array = malloc(sizeof(char *) * 7);

    array[0] = my_strdup("img/cursor.png");
    array[1] = my_strdup("img/pencil.png");
    array[2] = my_strdup("img/rubber.png");
    array[3] = my_strdup("img/bucket.png");
    array[4] = my_strdup("img/grab.png");
    array[5] = my_strdup("img/pipette_cross.png");
    array[6] = NULL;
    return array;
}

void modify_crosshair(win_t *win, char *filename, sfVector2f origin)
{
    sfTexture *text = NULL;
    sfSprite *new_sprite = NULL;

    if (filename == NULL)
        return;
    text = sfTexture_createFromFile(filename, NULL);
    new_sprite = sfSprite_create();
    sfSprite_setTextureRect(new_sprite, (sfIntRect){0, 0, 320, 320});
    sfSprite_setTexture(new_sprite, text, sfFalse);
    sfSprite_setOrigin(new_sprite, origin);
    sfSprite_setScale(new_sprite, (sfVector2f){0.1, 0.1});
    win->crosshair = new_sprite;
}

void move_crosshair(win_t *win)
{
    sfVector2f mouse_pos;

    mouse_pos.x = sfMouse_getPositionRenderWindow(win->win).x;
    mouse_pos.y = sfMouse_getPositionRenderWindow(win->win).y;
    sfSprite_setPosition(win->crosshair, mouse_pos);
    sfRenderWindow_drawSprite(win->win, win->crosshair, NULL);
}

static int sec_switch_crossair(win_t *win, char **crossair, canva_t *canva)
{
    if (canva->tool == BUCKET) {
        modify_crosshair(win, crossair[canva->tool], (sfVector2f){50, 300});
        return 0;
    }
    if (canva->tool == HAND) {
        modify_crosshair(win, crossair[canva->tool], (sfVector2f){150, 120});
        return 0;
    }
    if (canva->tool == PIPETTE) {
        modify_crosshair(win, crossair[5], (sfVector2f){150, 170});
        return 0;
    }
    return 1;
}

void switch_crossair(win_t *win, char **crossair, canva_t *canva)
{
    if (canva->tool == COLOR || canva->tool == NONE) {
        modify_crosshair(win, crossair[0], (sfVector2f){100, 50});
        return;
    }
    if (canva->tool == PENCIL) {
        modify_crosshair(win, crossair[canva->tool], (sfVector2f){330, 320});
        return;
    }
    if (canva->tool == RUBBER) {
        modify_crosshair(win, crossair[canva->tool], (sfVector2f){50, 300});
        return;
    }
    sec_switch_crossair(win, crossair, canva);
}
