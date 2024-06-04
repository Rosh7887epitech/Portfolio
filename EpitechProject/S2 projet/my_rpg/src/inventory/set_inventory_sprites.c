/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** set_inventory_sprites
*/

#include "rpg.h"

static void set_invent_pos_fourth_line(const inventory_buttons_t *but,
    sfView *view)
{
    sfVector2f pos = sfView_getCenter(view);
    float first_col = pos.y - 61;
    float second_col = pos.y - 33;
    float third_col = pos.y - 4;
    float fourth_col = pos.y + 26;
    float fourth_line = pos.x + 90;

    sfRectangleShape_setPosition(but->invent_13->rect,
        (sfVector2f){fourth_line, first_col});
    sfRectangleShape_setPosition(but->invent_14->rect,
        (sfVector2f){fourth_line, second_col});
    sfRectangleShape_setPosition(but->invent_15->rect,
        (sfVector2f){fourth_line, third_col});
    sfRectangleShape_setPosition(but->invent_16->rect,
        (sfVector2f){fourth_line, fourth_col});
}

static void set_invent_pos_third_line(const inventory_buttons_t *but, sfView
    *view)
{
    sfVector2f pos = sfView_getCenter(view);
    float first_col = pos.y - 61;
    float second_col = pos.y - 33;
    float third_col = pos.y - 4;
    float fourth_col = pos.y + 26;
    float third_line = pos.x + 61;

    sfRectangleShape_setPosition(but->invent_9->rect,
        (sfVector2f){third_line, first_col});
    sfRectangleShape_setPosition(but->invent_10->rect,
        (sfVector2f){third_line, second_col});
    sfRectangleShape_setPosition(but->invent_11->rect,
        (sfVector2f){third_line, third_col});
    sfRectangleShape_setPosition(but->invent_12->rect,
        (sfVector2f){third_line, fourth_col});
}

static void set_invent_pos_second_line(const inventory_buttons_t *but, sfView
    *view)
{
    sfVector2f pos = sfView_getCenter(view);
    float first_col = pos.y - 61;
    float second_col = pos.y - 33;
    float third_col = pos.y - 4;
    float fourth_col = pos.y + 26;
    float second_line = pos.x + 32;

    sfRectangleShape_setPosition(but->invent_5->rect,
        (sfVector2f){second_line, first_col});
    sfRectangleShape_setPosition(but->invent_6->rect,
        (sfVector2f){second_line, second_col});
    sfRectangleShape_setPosition(but->invent_7->rect,
        (sfVector2f){second_line, third_col});
    sfRectangleShape_setPosition(but->invent_8->rect,
        (sfVector2f){second_line, fourth_col});
}

void set_specials_pos(const inventory_buttons_t *but, sfView *view)
{
    sfVector2f pos = sfView_getCenter(view);
    float first_col = pos.y - 62;
    float fourth_col = pos.y + 30;
    float fourth_line = pos.x - 43;
    float first_line = pos.x - 102;

    sfRectangleShape_setPosition(but->wappon->rect,
        (sfVector2f){first_line, first_col});
    sfRectangleShape_setPosition(but->helmet->rect,
        (sfVector2f){fourth_line, first_col});
    sfRectangleShape_setPosition(but->shield->rect,
        (sfVector2f){first_line, fourth_col});
    sfRectangleShape_setPosition(but->boots->rect,
        (sfVector2f){fourth_line, fourth_col});
}

void set_invent_positions(const game_t *rpg,
    const inventory_buttons_t *button, sfView *view)
{
    sfVector2f pos = sfView_getCenter(view);
    float first_col = pos.y - 61;
    float second_col = pos.y - 33;
    float third_col = pos.y - 4;
    float fourth_col = pos.y + 26;
    float first_line = pos.x + 3;

    sfSprite_setPosition(rpg->inventory.inventory.sprite,
        (sfVector2f){pos.x - 30, pos.y + 10});
    sfRectangleShape_setPosition(button->invent_1->rect,
        (sfVector2f){first_line, first_col});
    sfRectangleShape_setPosition(button->invent_2->rect,
        (sfVector2f){first_line, second_col});
    sfRectangleShape_setPosition(button->invent_3->rect,
        (sfVector2f){first_line, third_col});
    sfRectangleShape_setPosition(button->invent_4->rect,
        (sfVector2f){first_line, fourth_col});
    set_invent_pos_second_line(button, view);
    set_invent_pos_third_line(button, view);
    set_invent_pos_fourth_line(button, view);
}

void set_specials_scales(const inventory_buttons_t *button)
{
    sfVector2f scale = {0.85, 0.85};

    sfRectangleShape_setScale(button->boots->rect, scale);
    sfRectangleShape_setScale(button->shield->rect, scale);
    sfRectangleShape_setScale(button->helmet->rect, scale);
    sfRectangleShape_setScale(button->wappon->rect, scale);
}

void set_inventory_scale(const inventory_buttons_t *button)
{
    sfVector2f scale = {0.58, 0.58};

    sfRectangleShape_setScale(button->invent_1->rect, scale);
    sfRectangleShape_setScale(button->invent_2->rect, scale);
    sfRectangleShape_setScale(button->invent_3->rect, scale);
    sfRectangleShape_setScale(button->invent_4->rect, scale);
    sfRectangleShape_setScale(button->invent_5->rect, scale);
    sfRectangleShape_setScale(button->invent_6->rect, scale);
    sfRectangleShape_setScale(button->invent_7->rect, scale);
    sfRectangleShape_setScale(button->invent_8->rect, scale);
    sfRectangleShape_setScale(button->invent_9->rect, scale);
    sfRectangleShape_setScale(button->invent_10->rect, scale);
    sfRectangleShape_setScale(button->invent_11->rect, scale);
    sfRectangleShape_setScale(button->invent_12->rect, scale);
    sfRectangleShape_setScale(button->invent_13->rect, scale);
    sfRectangleShape_setScale(button->invent_14->rect, scale);
    sfRectangleShape_setScale(button->invent_15->rect, scale);
    sfRectangleShape_setScale(button->invent_16->rect, scale);
    set_specials_scales(button);
}
