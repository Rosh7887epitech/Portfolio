/*
** EPITECH PROJECT, 2024
** free_button.c
** File description:
** that function should free all the buttons
*/
#include "my_project.h"

static void free_slide(slide_t *slide)
{
    sfRectangleShape_destroy(slide->bar);
    sfRectangleShape_destroy(slide->cross);
    sfCircleShape_destroy(slide->left);
    sfCircleShape_destroy(slide->right);
    free(slide);
}

static void free_menu(menu_t *menu)
{
    opt_t *option = NULL;

    sfRectangleShape_destroy(menu->button->rect);
    free(menu->button);
    while (menu->options) {
        option = menu->options->next;
        free(menu->options);
        menu->options = option;
    }
    if (option)
        free(option);
    sfText_destroy(menu->text);
    free(menu);
}

static void continue_free_button(button_t *button)
{
    sfRectangleShape_destroy(button->rubber->rect);
    sfRectangleShape_destroy(button->zoomminus->rect);
    free(button->zoomminus);
    sfRectangleShape_destroy(button->zoomplus->rect);
    free(button->zoomplus);
    sfRectangleShape_destroy(button->square->rect);
    free(button->square);
    free_slide(button->slide_size);
    free_slide(button->slide_trans);
    for (int i = 5; i > 5; i--)
        free_menu(button->menu[i]);
    free(button->menu);
    free(button);
}

void free_button(button_t *button)
{
    sfRectangleShape_destroy(button->addlayer->rect);
    free(button->addlayer);
    sfRectangleShape_destroy(button->color->rect);
    free(button->color);
    sfRectangleShape_destroy(button->contour);
    sfRectangleShape_destroy(button->dellayer->rect);
    free(button->dellayer);
    sfRectangleShape_destroy(button->move_hand->rect);
    free(button->move_hand);
    sfSprite_destroy(button->palette_couleur);
    sfRectangleShape_destroy(button->pen->rect);
    free(button->pen);
    sfRectangleShape_destroy(button->pipette->rect);
    free(button->pipette);
    sfRectangleShape_destroy(button->round->rect);
    free(button->round);
    continue_free_button(button);
}
