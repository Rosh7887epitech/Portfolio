/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player_move
*/

#include "rpg.h"

static void wich_top(player_t *player)
{
    if (player->p_sprite.rect.top == 2)
        player->p_sprite.attack_rect.top = 0;
    if (player->p_sprite.rect.top == 22)
        player->p_sprite.attack_rect.top = 32;
    if (player->p_sprite.rect.top == 42)
        player->p_sprite.attack_rect.top = 64;
    if (player->p_sprite.rect.top == 62)
        player->p_sprite.attack_rect.top = 96;
}

static void set_attack_rect(player_t *player, sfVector2f origin)
{
    sfSprite_setTexture(player->p_sprite.sprite,
        player->p_sprite.slash_tx, sfTrue);
    wich_top(player);
    sfSprite_setTextureRect(player->p_sprite.sprite,
        player->p_sprite.attack_rect);
    origin.x = player->p_sprite.attack_rect.width / 2.0f;
    origin.y = player->p_sprite.attack_rect.height / 2.0f;
    sfSprite_setOrigin(player->p_sprite.sprite, origin);
}

static void reset_player_rect(player_t *player, sfVector2f origin)
{
    sfSprite_setTexture(player->p_sprite.sprite,
        player->p_sprite.texture1, sfTrue);
    sfSprite_setTextureRect(player->p_sprite.sprite, player->p_sprite.rect);
    origin.x = player->p_sprite.rect.width / 2.0f;
    origin.y = player->p_sprite.rect.height / 2.0f;
    sfSprite_setOrigin(player->p_sprite.sprite, origin);
}

static void reset_rect(player_t *player)
{
    if (player->p_sprite.attack_rect.left >= 96) {
        player->p_sprite.attack_rect.left = 0;
        player->p_sprite.state = IDLE;
    }
}

void update_attack_animation(player_t *player, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    sfVector2f origin;

    if (player->p_sprite.state == ATTACKING) {
        if (seconds > 0.08) {
            player->p_sprite.attack_rect.left += 32;
            reset_rect(player);
            sfClock_restart(clock);
        }
        set_attack_rect(player, origin);
    } else
        reset_player_rect(player, origin);
    sfSprite_setPosition(player->p_sprite.sprite, player->p_sprite.position);
    sfRectangleShape_setPosition(player->player_hitbox,
        player->p_sprite.position);
}

void player_attack(sfEvent event, game_t *rpg)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA) {
        sfMusic_stop(rpg->music.slash);
        sfMusic_play(rpg->music.slash);
        event.type = sfEvtKeyReleased;
        if (rpg->player.p_sprite.state != ATTACKING) {
            rpg->player.p_sprite.state = ATTACKING;
            rpg->player.p_sprite.rect.left = 0;
            sfClock_restart(rpg->clock);
        }
    }
}

void init_attack_rect(player_t *player)
{
    player->p_sprite.attack_rect = init_rect(0, 0, 32, 32);
    player->p_sprite.attack_origin = (sfVector2f){32, 32};
    player->p_sprite.attack_scale = (sfVector2f){1, 1};
}

void attack_enemy(game_t *rpg)
{
    sfVector2f player_pos = rpg->player.p_sprite.position;
    sfVector2f enemy_pos = rpg->enemies.bat.position;

    if (rpg->player.p_sprite.state == ATTACKING &&
        compare_pos_enemy(player_pos, enemy_pos)) {
        if (rpg->enemies.bat.health > 0) {
            rpg->enemies.bat.health -= 1;
            rpg->player.exp += 2;
        }
    }
}

void draw_school(const game_t *game)
{
    if (game->player.p_sprite.room == SCHOOL) {
        sfRenderWindow_drawSprite(game->window.window,
            game->window.room.back, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->window.room.bar, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->window.room.shop, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->window.room.school, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->window.room.dungeon, NULL);
        sfRenderWindow_drawSprite(game->window.window,
            game->player.p_sprite.sprite, NULL);
    }
}
