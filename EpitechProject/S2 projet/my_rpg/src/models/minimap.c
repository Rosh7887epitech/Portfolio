/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** minimap
*/

#include "rpg.h"

static void init_minimap_dot(minimap_t *mini, player_t *player)
{
    mini->dot = sfCircleShape_create();
    sfCircleShape_setRadius(mini->dot, 4);
    sfCircleShape_setFillColor(mini->dot, sfRed);
    sfCircleShape_setOrigin(mini->dot, (sfVector2f){5, 5});
    sfCircleShape_setPosition(mini->dot,
        (sfVector2f){player->p_sprite.position.x,
        player->p_sprite.position.y});
    sfCircleShape_setScale(mini->dot, (sfVector2f){0.2, 0.2});
    mini->state = NO;
}

void init_minimap(minimap_t *mini, player_t *player)
{
    sfTexture *text = sfTexture_createFromFile("assets/images/mini.png", NULL);
    sfVector2f pos = sfView_getCenter(player->p_view.view);

    mini->map = sfSprite_create();
    sfSprite_setTexture(mini->map, text, sfTrue);
    sfSprite_setOrigin(mini->map, (sfVector2f){412.5, 412.5});
    sfSprite_setPosition(mini->map, (sfVector2f){pos.x, pos.y});
    sfSprite_setScale(mini->map, (sfVector2f){0.2, 0.2});
    init_minimap_dot(mini, player);
}

void draw_minimap(const game_t *game)
{
    if (game->minimap.state == PRINT) {
        sfSprite_setPosition(game->minimap.map,
            sfView_getCenter(game->player.p_view.view));
        sfCircleShape_setPosition(game->minimap.dot,
            (sfVector2f){game->player.p_sprite.position.x,
            game->player.p_sprite.position.y});
        sfRenderWindow_drawSprite(game->window.window,
            game->minimap.map, NULL);
        sfRenderWindow_drawCircleShape(game->window.window,
            game->minimap.dot, NULL);
    }
}

void update_state_minimap(game_t *game, sfEvent event, minimap_t *mini)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyH &&
        game->player.p_sprite.room == MAP) {
        if (mini->state == PRINT)
            mini->state = NO;
        else
            mini->state = PRINT;
    }
    if (game->player.p_sprite.room == SCHOOL)
        mini->state = NO;
}
