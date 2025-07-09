/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player_controller
*/

#include "rpg.h"

static void move_rect(game_t *game, player_t *player, float stock)
{
    if (player->p_sprite.rect.left == 32)
        player->p_sprite.rect.left = 0;
    if (stock > 0.08) {
        player->p_sprite.rect.left += 16;
        sfClock_restart(game->clock);
    }
    sfSprite_setTextureRect(player->p_sprite.sprite,
        player->p_sprite.rect);
    sfRenderWindow_setView(game->window.window, game->player.p_view.view);
    sfMusic_stop(game->music.walk);
    sfMusic_play(game->music.walk);
}

static void move_forward(game_t *game,
    player_t *player, float stock)
{
    if (stock < 0.04)
        return;
    player->p_sprite.rect.top = 62;
    if (verif_collision(&game->window, player) != 1) {
        player->p_sprite.position.y -= 2;
        sfSprite_move(player->p_sprite.sprite, (sfVector2f){0, -2});
        if (sfView_getCenter(player->p_view.view).y > 102 &&
            player->p_sprite.position.y < 1504)
            sfView_move(player->p_view.view, (sfVector2f){0, -2});
    }
    move_rect(game, player, stock);
}

static void move_backward(game_t *game,
    player_t *player, float stock)
{
    if (stock < 0.04)
        return;
    player->p_sprite.rect.top = 2;
    if (verif_collision(&game->window, player) != 2) {
        player->p_sprite.position.y += 2;
        sfSprite_move(player->p_sprite.sprite, (sfVector2f){0, 2});
        if (sfView_getCenter(player->p_view.view).y < 1494 &&
            player->p_sprite.position.y > 104)
            sfView_move(player->p_view.view, (sfVector2f){0, 2});
    }
    move_rect(game, player, stock);
}

static void move_left(game_t *game,
    player_t *player, float stock)
{
    if (stock < 0.04)
        return;
    player->p_sprite.rect.top = 22;
    if (side_collision(&game->window, player) != 3) {
        player->p_sprite.position.x -= 2;
        sfSprite_move(player->p_sprite.sprite, (sfVector2f){-2, 0});
        if (sfView_getCenter(player->p_view.view).x > 182 &&
            player->p_sprite.position.x < 1428)
            sfView_move(player->p_view.view, (sfVector2f){-2, 0});
    }
    move_rect(game, player, stock);
}

static void move_right(game_t *game,
    player_t *player, float stock)
{
    if (stock < 0.04)
        return;
    player->p_sprite.rect.top = 42;
    if (side_collision(&game->window, player) != 4) {
        player->p_sprite.position.x += 2;
        sfSprite_move(player->p_sprite.sprite, (sfVector2f){2, 0});
        if (sfView_getCenter(player->p_view.view).x < 1418 &&
            player->p_sprite.position.x > 192)
            sfView_move(player->p_view.view, (sfVector2f){2, 0});
    }
    move_rect(game, player, stock);
}

static void player_move(sfEvent event, game_t *rpg, float stock)
{
    bool z = sfKeyboard_isKeyPressed(sfKeyZ);
    bool s = sfKeyboard_isKeyPressed(sfKeyS);
    bool q = sfKeyboard_isKeyPressed(sfKeyQ);
    bool d = sfKeyboard_isKeyPressed(sfKeyD);

    (void)event;
    if (z == true && s != true && q != true && d != true &&
        rpg->player.p_sprite.state != ATTACKING)
        move_forward(rpg, &rpg->player, stock);
    if (s == true && z != true && q != true && d != true &&
        rpg->player.p_sprite.state != ATTACKING)
        move_backward(rpg, &rpg->player, stock);
    if (q == true && d != true && z != true && s != true &&
        rpg->player.p_sprite.state != ATTACKING)
        move_left(rpg, &rpg->player, stock);
    if (d == true && q != true && z != true && s != true &&
        rpg->player.p_sprite.state != ATTACKING)
        move_right(rpg, &rpg->player, stock);
    event.type = sfEvtKeyReleased;
}

void move_condition(sfEvent event, game_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock);
    float stock = sfTime_asSeconds(time);

    if (rpg->touch == false) {
        player_move(event, rpg, stock);
    }
}

void player_action(sfEvent event, game_t *rpg)
{
    if (rpg->menu.state == START_MENU || rpg->menu.state == INTRA_MENU ||
    rpg->menu.state == SETTING_MENU)
        return;
    player_attack(event, rpg);
    sfRenderWindow_setView(rpg->window.window, rpg->player.p_view.view);
}
