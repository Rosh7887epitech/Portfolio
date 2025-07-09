/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** draw_npc
*/

#include "rpg.h"
#include "text.h"

void display_frame(sfRenderWindow *window, sfView *view,
    sfSprite *sprite, off_set_t offset)
{
    sfVector2f pos = sfView_getCenter(view);

    pos = vector_edition(pos, offset.x, offset.y);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_text_and_frame(const game_t *game)
{
    off_set_t frame_offset = {-180, 35};

    if (game->n_npc->npc.is_spoken) {
        display_frame(game->window.window, game->player.p_view.view,
            game->frame.sprite, frame_offset);
        render_text_in_game(game);
    }
}

void draw_npc(const game_t *game, node_npc_t *current)
{
    create_texture(current->npc.sprite_obj.sprite,
        current->npc.sprite_obj.texture, &current->npc.sprite_obj.rect);
    sfRenderWindow_drawSprite(game->window.window,
        current->npc.sprite_obj.sprite, NULL);
}

void draw_letter(const game_t *game, node_npc_t *current)
{
    create_texture(current->npc.sprite_obj_letter.sprite,
        current->npc.sprite_obj_letter.texture,
        &current->npc.sprite_obj_letter.rect);
    sfRenderWindow_drawSprite(game->window.window,
        current->npc.sprite_obj_letter.sprite, NULL);
}

void display_npc_on_screen(const game_t *game)
{
    node_npc_t *current = game->n_npc;

    while (current != NULL) {
        if (current->npc.sprite_obj.is_displayed &&
            current->npc.sprite_obj.sprite != NULL) {
            draw_npc(game, current);
        }
        if (current->npc.sprite_obj_letter.is_displayed &&
            current->npc.sprite_obj_letter.sprite != NULL) {
            draw_letter(game, current);
            display_text_and_frame(game);
        }
        current = current->next;
    }
}
