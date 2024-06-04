/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game_logic
*/

#include "rpg.h"
#include "npc.h"
#include "utils.h"
#include "my.h"

void anime_ghost(game_t *game)
{
    sfTime timef = sfClock_getElapsedTime(game->clock);
    float seconds = timef.microseconds / 1000000.0;
    node_npc_t *current = game->n_npc;

    if (seconds > 0.3) {
        while (current) {
            my_move_rect(&current->npc.sprite_obj.rect, 78, 156,
            &current->npc.sprite_obj.direction);
            my_move_rect(&current->npc.sprite_obj_letter.rect, 16, 32,
            &current->npc.sprite_obj_letter.direction);
            current = current->next;
        }
        sfClock_restart(game->clock);
    }
}

sfVector2f get_npc_pos(game_t *game, int id)
{
    node_npc_t *current = game->n_npc;

    while (current) {
        if (current->npc.id == id)
            return (current->npc.sprite_obj.pos);
        current = current->next;
    }
    return ((sfVector2f){0, 0});
}

void update_npc(sfVector2f player_pos, npc_t *npc)
{
    sfVector2f npc_pos = npc->sprite_obj.pos;

    if (npc->is_spoken == false && compare_pos(player_pos, npc_pos)) {
        npc->sprite_obj_letter.is_displayed = true;
    } else if (!compare_pos(player_pos, npc_pos)) {
        npc->sprite_obj_letter.is_displayed = false;
        npc->is_spoken = false;
    }
}

void update_game(game_t *game)
{
    node_npc_t *current = game->n_npc;

    update_attack_animation(&game->player, game->clock);
    attack_enemy(game);
    anime_ghost(game);
    check_door(game);
    while (current) {
        update_npc(game->player.p_sprite.position, &current->npc);
        current = current->next;
    }
}
