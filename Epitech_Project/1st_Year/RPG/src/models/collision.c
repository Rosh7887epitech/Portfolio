/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** collision
*/

#include "rpg.h"
#include "npc.h"

bool compare_pos(sfVector2f pos1, sfVector2f pos2)
{
    if (pos1.x >= pos2.x - 30
        && pos1.x <= pos2.x + 30
        && pos1.y >= pos2.y - 30
        && pos1.y <= pos2.y + 30) {
        return true;
    }
    return false;
}

bool compare_pos_enemy(sfVector2f pos1, sfVector2f pos2)
{
    if (pos1.x >= pos2.x - 18
        && pos1.x <= pos2.x + 18
        && pos1.y >= pos2.y - 18
        && pos1.y <= pos2.y + 18) {
        return true;
    }
    return false;
}

int side_collision(window_node_t *window, player_t *player)
{
    sfColor color;
    sfImage *colision;

    if (player->p_sprite.room == SCHOOL)
        colision = window->col2;
    else
        colision = window->col;
    color = sfImage_getPixel(colision, player->p_sprite.position.x - 11,
        player->p_sprite.position.y);
    if (color.r == 255 && color.g == 0 && color.b == 0)
        return 3;
    color = sfImage_getPixel(colision, player->p_sprite.position.x + 11,
        player->p_sprite.position.y);
    if (color.r == 255 && color.g == 0 && color.b == 0)
        return 4;
    return 0;
}

int verif_collision(window_node_t *window, player_t *player)
{
    sfColor color;
    sfImage *colision;

    if (player->p_sprite.room == SCHOOL)
        colision = window->col2;
    else
        colision = window->col;
    color = sfImage_getPixel(colision, player->p_sprite.position.x,
        player->p_sprite.position.y - 11);
    if (color.r == 255 && color.g == 0 && color.b == 0)
        return 1;
    color = sfImage_getPixel(colision, player->p_sprite.position.x,
        player->p_sprite.position.y + 11);
    if (color.r == 255 && color.g == 0 && color.b == 0)
        return 2;
    return 0;
}
