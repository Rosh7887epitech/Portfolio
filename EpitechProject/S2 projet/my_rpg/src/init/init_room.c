/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_room
*/

#include "rpg.h"

static bool init_back_room(room_t *room)
{
    sfTexture *text = sfTexture_createFromFile("assets/images/back2.png",
        NULL);

    if (text == NULL)
        return false;
    room->back = sfSprite_create();
    sfSprite_setOrigin(room->back, (sfVector2f){0, 0});
    sfSprite_setScale(room->back, (sfVector2f){1, 1});
    sfSprite_setPosition(room->back, (sfVector2f){0, 0});
    sfSprite_setTexture(room->back, text, sfTrue);
    return true;
}

static bool init_start_anime(room_t *room)
{
    sfTexture *text =
        sfTexture_createFromFile("assets/images/bg_start_game2.png", NULL);

    if (text == NULL)
        return false;
    room->start_anim = sfSprite_create();
    sfSprite_setOrigin(room->start_anim, (sfVector2f){1920 / 2, 1080 / 2});
    sfSprite_setScale(room->start_anim, (sfVector2f){8, 8});
    sfSprite_setPosition(room->start_anim, (sfVector2f){1920 / 2, 1080 / 2});
    sfSprite_setTexture(room->start_anim, text, sfTrue);
    return true;
}

static bool init_dungeon(room_t *room)
{
    sfTexture *text =
        sfTexture_createFromFile("assets/images/d_map.png", NULL);

    if (text == NULL)
        return false;
    room->dungeon = sfSprite_create();
    sfSprite_setOrigin(room->dungeon, (sfVector2f){0, 0});
    sfSprite_setScale(room->dungeon, (sfVector2f){1, 1});
    sfSprite_setPosition(room->dungeon, (sfVector2f){121, 16});
    sfSprite_setTexture(room->dungeon, text, sfTrue);
    return true;
}

static bool init_bar_room(window_node_t *win, room_t *room)
{
    sfTexture *text = sfTexture_createFromFile("assets/images/bar.png",
        NULL);
    sfTexture *text2 = sfTexture_createFromFile("assets/images/s_b_col.png",
        NULL);

    if (text == NULL)
        return false;
    room->bar = sfSprite_create();
    sfSprite_setOrigin(room->bar, (sfVector2f){0, 0});
    sfSprite_setScale(room->bar, (sfVector2f){1, 1});
    sfSprite_setPosition(room->bar, (sfVector2f){7, 816});
    sfSprite_setTexture(room->bar, text, sfTrue);
    win->col2 = sfTexture_copyToImage(text2);
    return true;
}

static bool init_school_room(room_t *room)
{
    sfTexture *text = sfTexture_createFromFile("assets/images/school.png",
        NULL);

    if (text == NULL)
        return false;
    room->school = sfSprite_create();
    sfSprite_setOrigin(room->school, (sfVector2f){0, 0});
    sfSprite_setScale(room->school, (sfVector2f){1, 1});
    sfSprite_setPosition(room->school, (sfVector2f){1122, 784});
    sfSprite_setTexture(room->school, text, sfTrue);
    return true;
}

static bool init_shop_room(room_t *room)
{
    sfTexture *text = sfTexture_createFromFile("assets/images/shop.png",
        NULL);
    sfTexture *text2 = sfTexture_createFromFile("assets/images/s_b_col.png",
        NULL);

    if (text == NULL)
        return false;
    room->shop = sfSprite_create();
    sfSprite_setOrigin(room->shop, (sfVector2f){0, 0});
    sfSprite_setScale(room->shop, (sfVector2f){1, 1});
    sfSprite_setPosition(room->shop, (sfVector2f){7, 1216});
    sfSprite_setTexture(room->shop, text, sfTrue);
    room->col2 = sfSprite_create();
    sfSprite_setOrigin(room->col2, (sfVector2f){0, 0});
    sfSprite_setScale(room->col2, (sfVector2f){1, 1});
    sfSprite_setPosition(room->col2, (sfVector2f){7, 1216});
    sfSprite_setTexture(room->col2, text2, sfTrue);
    return true;
}

void init_room(window_node_t *win)
{
    init_bar_room(win, &win->room);
    init_shop_room(&win->room);
    init_school_room(&win->room);
    init_back_room(&win->room);
    init_start_anime(&win->room);
    init_dungeon(&win->room);
}
