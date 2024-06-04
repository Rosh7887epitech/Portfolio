/*
** EPITECH PROJECT, 2024
** init_structure.c
** File description:
** that function should init all of our struct
*/
#include "my_project.h"
void init_canva_el(canva_t *canva, int wi, int hei, sfVector2f layer_button)
{
    canva->layer = malloc(sizeof(layer_t));
    layer_button.y += 65;
    canva->layer->button = init_canva_but(layer_button);
    canva->layer->texture = sfTexture_create(wi, hei);
    canva->layer->next = NULL;
    canva->layer->uint_tab = create_sfuint8_array(wi, hei);
    canva->tools_size = 10;
    canva->height = hei;
    canva->width = wi;
    canva->tool_color = sfBlack;
    canva->tool = NONE;
    canva->scale = (sfVector2f){1, 1};
    canva->layer->is_active = sfTrue;
    canva->layer->screen_sprite = sfSprite_create();
    canva->layer->is_visible = sfTrue;
}

canva_t *init_canva(int wi, int hei, sfVector2f layer_button_pos)
{
    canva_t *canva = malloc(sizeof(canva_t));

    init_canva_el(canva, wi, hei, layer_button_pos);
    sfSprite_setOrigin(canva->layer->screen_sprite,
        (sfVector2f){wi / 2, hei / 2});
    sfSprite_setPosition(canva->layer->screen_sprite,
        (sfVector2f){890, 1080 / 2});
    sfTexture_updateFromPixels(canva->layer->texture, canva->layer->uint_tab,
        wi, hei, 0, 0);
    sfSprite_setScale(canva->layer->screen_sprite, canva->scale);
    sfSprite_setTexture(canva->layer->screen_sprite,
        canva->layer->texture, sfTrue);
    canva->sprite_rect = sfSprite_getGlobalBounds(canva->layer->screen_sprite);
    canva->old_pos.x = -1;
    canva->old_pos.y = -1;
    canva->tool_shape = RECTANGLE;
    return canva;
}

static void init_slide(button_t *but)
{
    but->slide_size = create_slide((sfVector2f){1760, 119}, 100, 10);
    but->slide_trans = create_slide((sfVector2f){1760, 188}, 255, 255);
}

static void init_zoom_butt(sfVector2f size, button_t *but)
{
    but->zoomminus = init_button((sfVector2f){0, 267}, size, sfGreen,
        "img/zoomminus.png");
    but->zoomplus = init_button((sfVector2f){0, 317}, size, sfGreen,
        "img/zoomplus.png");
    size.x -= 10;
    size.y -= 10;
    but->square = init_button((sfVector2f){1862.5, 255}, size, sfGreen,
        "img/square.png");
    but->round = init_button((sfVector2f){1767, 255}, size, sfGreen,
        "img/circle.png");
    sfRectangleShape_setOutlineColor(but->round->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(but->square->rect, sfTransparent);
}

static switch_t *create_switch(void)
{
    switch_t *but = malloc(sizeof(switch_t));
    sfVector2f size = (sfVector2f){45, 40};

    but->switch_shape = init_button((sfVector2f){1807.5, 250}, size, sfGreen,
        "img/switch1.png");
    sfRectangleShape_setOutlineColor(but->switch_shape->rect, sfTransparent);
    but->switch1 = sfTexture_createFromFile("img/switch1.png", NULL);
    but->switch2 = sfTexture_createFromFile("img/switch2.png", NULL);
    return but;
}

button_t *create_buttons(char **cros)
{
    button_t *but = malloc(sizeof(button_t));
    sfVector2f size = (sfVector2f){40, 40};

    but = init_drop_menu(but);
    init_slide(but);
    but->sw = create_switch();
    but->pen = init_button((sfVector2f){0, 117}, size, sfWhite, cros[1]);
    but->rubber = init_button((sfVector2f){0, 167}, size, sfWhite, cros[2]);
    but->color = init_button((sfVector2f){0, 217}, size, sfBlack, NULL);
    init_zoom_butt(size, but);
    but->move_hand = init_button((sfVector2f){0, 367}, size, sfGreen, cros[4]);
    but->pipette = init_button((sfVector2f){0, 417}, size, sfGreen,
        "img/pipette.png");
    but->palette_couleur = create_palette((sfVector2f){40, 720});
    but->contour = palette_rect((sfVector2f){40, 720});
    but->addlayer = init_button((sfVector2f){1750, 520}, (sfVector2f){30, 30},
        sfGreen, "img/addlayer.png");
    but->dellayer = init_button((sfVector2f){1790, 520}, (sfVector2f){30, 30},
        sfGreen, "img/bin.png");
    return but;
}

win_t *init_window(void)
{
    sfVideoMode win_size = {1920, 1080, 0};
    win_t *window = malloc(sizeof(win_t));

    window->win = sfRenderWindow_create(win_size, "My Paint",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->win, 0);
    sfRenderWindow_setMouseCursorVisible(window->win, sfFalse);
    window->background = create_background();
    window = create_gui(window);
    modify_crosshair(window, window->crossair_tab[0], (sfVector2f){100, 30});
    return window;
}
