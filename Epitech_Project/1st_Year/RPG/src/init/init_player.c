/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_player
*/

#include "rpg.h"

bool init_sound_effect(music_t *music)
{
    music->walk = sfMusic_createFromFile("assets/sounds/walk.ogg");
    if (music->walk == NULL)
        return false;
    music->slash = sfMusic_createFromFile("assets/sounds/slash.ogg");
    if (music->slash == NULL)
        return false;
    sfMusic_setVolume(music->slash, 80);
    sfMusic_setVolume(music->walk, 100);
    return true;
}

bool init_enemy_sprite(enemy_t *enemies, char *filepath, sfVector2f pos)
{
    sfTexture *text =
        sfTexture_createFromFile(filepath, NULL);

    enemies->sprite = sfSprite_create();
    enemies->rect = init_rect(0, 0, 16, 16);
    enemies->origin = (sfVector2f){8, 8};
    enemies->scale = (sfVector2f){1, 1};
    enemies->position = (sfVector2f){pos.x, pos.y};
    enemies->health = 100;
    sfSprite_setOrigin(enemies->sprite, enemies->origin);
    sfSprite_setScale(enemies->sprite, enemies->scale);
    sfSprite_setPosition(enemies->sprite, enemies->position);
    sfSprite_setTexture(enemies->sprite, text, sfTrue);
    sfSprite_setTextureRect(enemies->sprite, enemies->rect);
    return true;
}

bool init_player_sprite(player_t *player)
{
    player->p_sprite.texture1 =
        sfTexture_createFromFile("assets/images/p2.png", NULL);
    player->p_sprite.slash_tx =
        sfTexture_createFromFile("assets/images/slash1.png", NULL);
    if (player->p_sprite.texture1 == NULL || player->p_sprite.slash_tx == NULL)
        return false;
    player->p_sprite.sprite = sfSprite_create();
    player->p_sprite.rect = init_rect(2, 0, 16, 18);
    player->p_sprite.origin = (sfVector2f){8, 9};
    player->p_sprite.scale = (sfVector2f){1, 1};
    player->p_sprite.position = (sfVector2f){1342, 1391};
    sfSprite_setOrigin(player->p_sprite.sprite, player->p_sprite.origin);
    sfSprite_setScale(player->p_sprite.sprite, player->p_sprite.scale);
    sfSprite_setPosition(player->p_sprite.sprite, player->p_sprite.position);
    sfSprite_setTexture(player->p_sprite.sprite,
        player->p_sprite.texture1, sfTrue);
    sfSprite_setTextureRect(player->p_sprite.sprite, player->p_sprite.rect);
    init_attack_rect(player);
    return true;
}

bool init_player_hitbox(player_t *player)
{
    sfVector2f hitboxSize = {player->p_sprite.rect.width,
        player->p_sprite.rect.height};

    player->player_hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(player->player_hitbox, hitboxSize);
    sfRectangleShape_setOrigin(player->player_hitbox, player->p_sprite.origin);
    sfRectangleShape_setScale(player->player_hitbox, player->p_sprite.scale);
    sfRectangleShape_setPosition(player->player_hitbox,
        player->p_sprite.position);
    sfRectangleShape_setFillColor(player->player_hitbox, sfRed);
    return true;
}

bool init_player(player_t *player)
{
    player->health = 100;
    player->attack = 10;
    player->defense = 5;
    player->level = 1;
    player->exp = 0;
    player->p_sprite.state = IDLE;
    player->p_sprite.room = MAP;
    return true;
}
