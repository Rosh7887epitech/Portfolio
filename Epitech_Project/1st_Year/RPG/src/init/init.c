/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init
*/

#include <stdlib.h>
#include "rpg.h"
#include "my_json.h"
#include "npc.h"
#include "text.h"
#include "extern.h"
#include "text.h"

static bool init_enemies(enemies_t *enemies)
{
    init_enemy_sprite(&enemies->bat, "assets/images/bat.png",
        (sfVector2f){1218, 1491});
    return true;
}

static bool init_other_layer(window_node_t *win)
{
    sfTexture *text2 = sfTexture_createFromFile("assets/images/couche.png",
        NULL);
    sfTexture *text3 = sfTexture_createFromFile("assets/images/col.png",
        NULL);

    if (text2 == NULL || text3 == NULL)
        return false;
    win->colision = sfSprite_create();
    sfSprite_setTexture(win->colision, text3, sfTrue);
    win->col = sfTexture_copyToImage(text3);
    win->couche = sfSprite_create();
    sfSprite_setOrigin(win->couche, (sfVector2f){0, 0});
    sfSprite_setScale(win->couche, (sfVector2f){1, 1});
    sfSprite_setPosition(win->couche, (sfVector2f){0, 0});
    sfSprite_setTexture(win->couche, text2, sfTrue);
    return true;
}

static bool init_background(window_node_t *win)
{
    sfTexture *text = sfTexture_createFromFile("assets/images/back.png",
        NULL);

    if (text == NULL)
        return false;
    win->back = sfSprite_create();
    sfSprite_setOrigin(win->back, (sfVector2f){0, 0});
    sfSprite_setScale(win->back, (sfVector2f){1, 1});
    sfSprite_setPosition(win->back, (sfVector2f){0, 0});
    sfSprite_setTexture(win->back, text, sfTrue);
    init_other_layer(win);
    init_room(win);
    return true;
}

static bool init_npc_and_quest(node_npc_t **n_npc)
{
    json_value_t *json_npc = json_file("config/npc.json");

    if (json_npc == NULL)
        return false;
    *n_npc = json_to_npcs(json_npc);
    return true;
}

static bool init_items(item_node_t **node_items)
{
    json_value_t *json = json_file("config/exemple.json");

    if (json == NULL)
        return false;
    *node_items = json_to_items(json);
    json = json_file("config/item_sprite.json");
    if (json == NULL)
        return false;
    browse_items_and_create_sprite(*node_items, json);
    return true;
}

static bool init_music(music_t *music)
{
    music->music = sfMusic_createFromFile("assets/sounds/bg_music.wav");
    if (music->music == NULL)
        return false;
    music->music_state = ON;
    sfMusic_setLoop(music->music, true);
    sfMusic_setVolume(music->music, 35);
    sfMusic_play(music->music);
    init_sound_effect(music);
    return true;
}

static bool init_game(game_t *game)
{
    bool (*init_funcs[])(void *) = {
        (bool (*)(void *))init_player_view, (bool (*)(void *))init_player,
        (bool (*)(void *))init_enemies, (bool (*)(void *))init_player_sprite,
        (bool (*)(void *))init_background, (bool (*)(void *))init_menu,
        (bool (*)(void *))init_npc_and_quest, (bool (*)(void *))init_items,
        (bool (*)(void *))init_frame, (bool (*)(void *))init_music,
        (bool (*)(void *))init_quest_frame, (bool (*)(void *))init_health_bar
    };
    void *params[] = {
        &game->player.p_view, &game->player, &game->enemies, &game->player,
        &game->window, &game->menu, &game->n_npc, &game->node_items,
        &game->frame, &game->music, &game->quest_frame, &game->health_bar
    };
    int num_init_funcs = sizeof(init_funcs) / sizeof(*init_funcs);

    for (int i = 0; i < num_init_funcs; i++)
        if (!init_funcs[i](params[i]))
            return false;
    return true;
}

bool initialize_game(game_t *game)
{
    if (!loadglobalfont(PATH_FONT))
        return false;
    global_quest_text = create_text("Quetes");
    if (!init_game(game))
        return false;
    init_inventory(&game->inventory, game->node_items->items);
    print_inventory(&game->inventory);
    init_player_hitbox(&game->player);
    game->window.window = create_window("My RPG",
        sfVideoMode_getDesktopMode());
    if (game->window.window == NULL)
        return false;
    browse_and_fill_npc(game);
    game->menu.state = START_MENU;
    game->state = GAME_RUNNING;
    game->menu.last_state = START_MENU;
    game->clock = sfClock_create();
    game->touch = false;
    init_minimap(&game->minimap, &game->player);
    return true;
}
