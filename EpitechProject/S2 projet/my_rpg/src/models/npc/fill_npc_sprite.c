/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** fill_npc_sprite
*/

#include "my.h"
#include "rpg.h"
#include "npc.h"
#include "utils.h"

const sfVector2f POS_GHOST = {1320, 1320};
const sfVector2f POS_VAMPIRE = {225, 854};

static bool fill_npc_sprite(npc_t *npc, char *path, sfIntRect rect)
{
    npc->sprite_obj.sprite = sfSprite_create();
    npc->sprite_obj.texture = sfTexture_createFromFile(path, NULL);
    if (npc->sprite_obj.sprite == NULL || npc->sprite_obj.texture == NULL)
        return false;
    sfSprite_setTexture(npc->sprite_obj.sprite,
        npc->sprite_obj.texture, sfTrue);
    sfSprite_setScale(npc->sprite_obj.sprite, (sfVector2f){0.25, 0.25});
    sfSprite_setOrigin(npc->sprite_obj.sprite, (sfVector2f){39, 47});
    npc->sprite_obj.rect = rect;
    npc->sprite_obj.direction = 1;
    return true;
}

static bool fill_npc_letter_sprite(npc_t *npc, char *path)
{
    npc->sprite_obj_letter.sprite = sfSprite_create();
    npc->sprite_obj_letter.texture = sfTexture_createFromFile(path, NULL);
    if (npc->sprite_obj_letter.sprite == NULL ||
        npc->sprite_obj_letter.texture == NULL)
        return false;
    sfSprite_setTexture(npc->sprite_obj_letter.sprite,
        npc->sprite_obj_letter.texture, sfTrue);
    sfSprite_setScale(npc->sprite_obj_letter.sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setOrigin(npc->sprite_obj_letter.sprite, (sfVector2f){10, 40});
    npc->sprite_obj_letter.rect = init_rect(0, 0, 16, 16);
    npc->sprite_obj_letter.direction = 1;
    return true;
}

void fill_npc_pos(npc_t *npc, sfVector2f pos)
{
    npc->sprite_obj.pos = pos;
    sfSprite_setPosition(npc->sprite_obj.sprite, pos);
    sfSprite_setPosition(npc->sprite_obj_letter.sprite, pos);
}

void fill_npc(npc_t *npc, char *path, sfVector2f pos, sfIntRect rect)
{
    if (npc == NULL)
        exit(84);
    if (fill_npc_sprite(npc, path, rect) == false)
        exit(84);
    if (fill_npc_letter_sprite(npc, PATH_E_LETTER) == false)
        exit(84);
    fill_npc_pos(npc, pos);
    npc->sprite_obj.is_displayed = true;
    npc->sprite_obj_letter.is_displayed = false;
}

void browse_and_fill_npc(game_t *game)
{
    node_npc_t *current = game->n_npc;
    sfIntRect ghost = init_rect(0, 0, 78, 94);
    sfIntRect vampire = init_rect(0, 0, 70, 86);

    while (current != NULL) {
        if (current->npc.id == 1)
            fill_npc(&current->npc, PATH_GHOST, POS_GHOST, ghost);
        if (current->npc.id == 2)
            fill_npc(&current->npc, PATH_VAMPIRE, POS_VAMPIRE, vampire);
        current = current->next;
    }
}
