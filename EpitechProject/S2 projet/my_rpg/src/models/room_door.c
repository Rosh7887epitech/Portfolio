/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** room_door
*/

#include "rpg.h"

static void enter_bar(game_t *game)
{
    sfColor color = sfImage_getPixel(game->window.col,
        game->player.p_sprite.position.x,
        game->player.p_sprite.position.y);
    sfColor color2 = sfImage_getPixel(game->window.col2,
        game->player.p_sprite.position.x,
        game->player.p_sprite.position.y);

    if (color.r == 200 && color.g == 0 && color.b == 255) {
        get_npc_by_id(game, 2)->sprite_obj.is_displayed = true;
        get_npc_by_id(game, 2)->sprite_obj_letter.is_displayed = true;
        game->player.p_sprite.room = SCHOOL;
    }
    if (color2.r == 200 && color2.g == 0 && color2.b == 255) {
        get_npc_by_id(game, 2)->sprite_obj.is_displayed = false;
        get_npc_by_id(game, 2)->sprite_obj_letter.is_displayed = false;
        game->player.p_sprite.room = MAP;
    }
}

void check_door(game_t *game)
{
    enter_bar(game);
}
