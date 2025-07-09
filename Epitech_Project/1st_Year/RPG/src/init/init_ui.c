/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_ui
*/

#include "rpg.h"
#include "extern.h"

bool init_frame(sprite_object_t *frame)
{
    frame->sprite = sfSprite_create();
    frame->texture = sfTexture_createFromFile(PATH_FRAME, NULL);
    if (frame->sprite == NULL || frame->texture == NULL)
        return false;
    sfSprite_setTexture(frame->sprite, frame->texture, sfTrue);
    sfSprite_setOrigin(frame->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(frame->sprite, (sfVector2f){0.195, 0.2});
    sfSprite_setPosition(frame->sprite, (sfVector2f){1350, 1320});
    return true;
}

bool init_quest_frame(sprite_object_t *frame)
{
    frame->sprite = sfSprite_create();
    frame->texture = sfTexture_createFromFile(QUESTS_FRAME, NULL);
    if (frame->sprite == NULL || frame->texture == NULL)
        return false;
    sfSprite_setTexture(frame->sprite, frame->texture, sfTrue);
    sfSprite_setOrigin(frame->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(frame->sprite, (sfVector2f){0.21, 0.25});
    sfSprite_setPosition(frame->sprite, (sfVector2f){1350, 1320});
    return true;
}

bool init_health_bar(sprite_object_t *health_bar)
{
    health_bar->sprite = sfSprite_create();
    health_bar->texture = sfTexture_createFromFile(HEALTH_BAR_PATH, NULL);
    if (!health_bar->sprite || !health_bar->texture)
        return false;
    sfSprite_setTexture(health_bar->sprite, health_bar->texture, sfTrue);
    sfSprite_setOrigin(health_bar->sprite, (vectorfzero));
    sfSprite_setScale(health_bar->sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setPosition(health_bar->sprite, (sfVector2f){1400, 1300});
    return true;
}
