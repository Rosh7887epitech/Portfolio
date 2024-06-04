/*
** EPITECH PROJECT, 2024
** create_palette.c
** File description:
** that function should create the palette
*/
#include "my_project.h"

sfSprite *create_palette(sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/palette.png", NULL);

    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 493, 260});
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfRectangleShape *palette_rect(sfVector2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    pos.x -= 10;
    pos.y -= 10;
    sfRectangleShape_setFillColor(rect, (sfColor){74, 77, 81, 255});
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, (sfVector2f){493 + 20, 260 + 20});
    return rect;
}

void draw_palette(sfSprite *spri, sfRectangleShape *rec, win_t *win, int tool)
{
    if (tool == COLOR) {
        sfRenderWindow_drawRectangleShape(win->win, rec, NULL);
        sfRenderWindow_drawSprite(win->win, spri, NULL);
    }
}

void change_color(win_t *win, canva_t *canva, button_t *button)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->win);
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->palette_couleur);
    sfTexture const *texture;
    sfImage *image;
    int pos_x = (click_pos.x - bounds.left);
    int pos_y = (click_pos.y - bounds.top);

    if (sfFloatRect_contains(&bounds, click_pos.x, click_pos.y)
    && canva->tool == COLOR) {
        texture = sfSprite_getTexture(button->palette_couleur);
        image = sfTexture_copyToImage(texture);
        canva->tool_color = sfImage_getPixel(image, pos_x, pos_y);
        sfImage_destroy(image);
    } else if (!is_button_hover(button->color, &win->event.mouseMove)) {
        canva->tool = NONE;
        switch_crossair(win, win->crossair_tab, canva);
    }
    sfRectangleShape_setFillColor(button->color->rect, canva->tool_color);
    return;
}
