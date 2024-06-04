/*
** EPITECH PROJECT, 2024
** import.c
** File description:
** that function should import an image
*/

#include "my_project.h"
#include <stdio.h>

sfBool is_home(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '/')
            count++;
    }
    if (count >= 2)
        return sfFalse;
    return sfTrue;
}

sfSprite *create_new_sprite(sfTexture *texture, int width, int height)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setOrigin(sprite, (sfVector2f){width / 2, height / 2});
    sfSprite_setPosition(sprite, (sfVector2f){1920 / 2, 1080 / 2});
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    return sprite;
}

static void cpy_tab(canva_t *canva, sfUint8 *tab_sf)
{
    int width = canva->width;
    int height = canva->height;

    free(canva->layer->uint_tab);
    canva->layer->uint_tab = malloc(sizeof(sfUint8) * (width * height * 4));
    for (int i = 0; i < (width * height * 4); i++)
        canva->layer->uint_tab[i] = tab_sf[i];
    canva->scale = (sfVector2f){1, 1};
    canva->sprite_rect = sfSprite_getGlobalBounds(canva->layer->screen_sprite);
}

static void modify_canva_value(canva_t *canva, int wi, int hei,
    sfSprite *sprite)
{
    sfSprite_destroy(canva->layer->screen_sprite);
    sfTexture_destroy(canva->layer->texture);
    canva->width = wi;
    canva->height = hei;
    canva->layer->screen_sprite = sprite;
}

void import_my(canva_t *canva, char *filepath)
{
    sfImage* image = sfImage_createFromFile(filepath);
    sfSprite *sprite;
    sfTexture *texture;
    int width = 0;
    int height = 0;
    sfUint8 *tab_sf;

    if (image) {
        width = sfImage_getSize(image).x;
        height = sfImage_getSize(image).y;
        texture = sfTexture_create(width, height);
        tab_sf = malloc(sizeof(sfUint8) * (width * height * 4));
        tab_sf = (sfUint8 *)sfImage_getPixelsPtr(image);
        sprite = create_new_sprite(texture, width, height);
        sfTexture_updateFromPixels(texture, tab_sf, width, height, 0, 0);
        modify_canva_value(canva, width, height, sprite);
        canva->layer->texture = texture;
        cpy_tab(canva, tab_sf);
        sfImage_destroy(image);
    }
}

void free_import(win_t *win, file_t **file, input_t *input)
{
    file_t *new = NULL;

    sfRenderWindow_close(win->win);
    sfRenderWindow_destroy(win->win);
    sfRectangleShape_destroy(win->background);
    free(win);
    while (*file) {
        new = (*file)->next;
        free(*file);
        *file = new;
    }
    if (new)
        free(new);
    if (input->pwd)
        free(input->pwd);
    sfRectangleShape_destroy(input->go_back->rect);
    free(input->go_back);
    free(input);
}
