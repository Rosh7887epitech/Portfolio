/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_menu
*/

#include "rpg.h"

static sfVector2f convert_vu_to_vf(sfVector2u size)
{
    sfVector2f size_f;

    size_f.x = size.x;
    size_f.y = size.y;
    return size_f;
}

sfRectangleShape *init_rectshape(sfColor col, char *filepath)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfTexture *texture = NULL;

    if (filepath != NULL) {
        texture = sfTexture_createFromFile(filepath, NULL);
        if (texture == NULL)
            return NULL;
        sfRectangleShape_setTexture(rect, texture, sfTrue);
    } else
        sfRectangleShape_setFillColor(rect, col);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfTransparent);
    sfRectangleShape_setSize(rect,
        convert_vu_to_vf(sfTexture_getSize(texture)));
    sfRectangleShape_setScale(rect, (sfVector2f){2.5, 2.5});
    return rect;
}

button_t *init_button(sfColor color, char *filepath)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = init_rectshape(color, filepath);
    if (button->rect == NULL)
        return NULL;
    button->is_hovered = &is_button_hovered;
    button->is_click = &is_button_clicked;
    button->is_rel = &is_button_released;
    button->is_pres = &is_button_pressed;
    button->state = NON;
    return button;
}

button_t *create_buttons(char *filepath)
{
    button_t *buttons;

    buttons = init_button(sfBlack, filepath);
    if (buttons == NULL)
        exit(84);
    return buttons;
}
