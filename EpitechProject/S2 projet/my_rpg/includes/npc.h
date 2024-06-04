/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** npc
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "quest.h"
#include "my_json.h"

#define PATH_GHOST "assets/images/npc/g.png"
#define PATH_E_LETTER "assets/images/npc/e_letter.png"
#define PATH_FRAME "assets/images/npc/cc.png"
#define PATH_VAMPIRE "assets/images/npc/v.png"

typedef struct dialogue_opt_s {
    int id;
    char text[256];
    sfText *text_obj;
} dialogue_opt_t;

typedef struct node_dialogue_opt_s {
    dialogue_opt_t dialog_opt;
    struct node_dialogue_opt_s *next;
    struct node_dialogue_opt_s *start;
    struct node_dialogue_opt_s *prev;
    int index;
} node_dialogue_opt_t;

typedef struct dialogue_s {
    int id;
    char name[50];
    char text[256];
    sfText *text_obj;
    sfText *name_obj;
    node_dialogue_opt_t *n_dialog_opt;
} dialogue_t;

typedef struct node_dialogue_s {
    dialogue_t dialog;
    struct node_dialogue_s *next;
    struct node_dialogue_s *start;
    struct node_dialogue_s *prev;
    int index;
} node_dialogue_t;

typedef struct stories_s {
    int id;
    char name[50];
    sfText *name_obj;
    node_dialogue_t *n_dialog;
} stories_t;

typedef struct node_stories_s {
    stories_t stories;
    struct node_stories_s *next;
    struct node_stories_s *start;
    struct node_stories_s *prev;
    int index;
} node_stories_t;

typedef struct sprite_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    bool is_displayed;
    int direction;
} sprite_object_t;

typedef struct npc_s {
    int id;
    char name[50];
    sfVector2f position;
    sfText *name_obj;
    bool is_spoken;
    sprite_object_t sprite_obj;
    sprite_object_t sprite_obj_letter;
    node_stories_t *n_stories;
    node_quest_t *n_quest;
} npc_t;

typedef struct node_npc_s {
    npc_t npc;
    struct node_npc_s *next;
    struct node_npc_s *start;
    struct node_npc_s *prev;
    int index;
} node_npc_t;

typedef struct game_s game_t;

// game

void print_game(game_t game);

// NPC
void add_npc(game_t *game, npc_t npc);
void free_npc(node_npc_t *head);
void print_npc(npc_t npc);
npc_t *get_npc_by_id(game_t *game, int id);

// stories

void add_stories(npc_t *npc, stories_t stories);
void free_stories(node_stories_t *head);
void print_stories(node_stories_t *head);
node_stories_t *parse_stories(json_value_t *json_stories);

// dialogue

void add_dialogue(stories_t *stories, dialogue_t dialog);
void free_dialogue(node_dialogue_t *head);
void print_dialogues(node_dialogue_t *head);
node_dialogue_t *parse_dialogues(json_value_t *json_dialogs);

// dialogue_opt

node_dialogue_opt_t *parse_dialogue_options(json_value_t *json_dialog_opt);
void add_dialogue_opt(dialogue_t *dialog, dialogue_opt_t dialog_opt);
void free_dialogue_opt(node_dialogue_opt_t *head);
void print_dialogue_options(node_dialogue_opt_t *head);

// JSON

node_dialogue_opt_t *fill_dialogue_opt_node_by_json(const json_value_t *js,
    node_dialogue_opt_t *node);
node_dialogue_t *fill_dialogue_node_by_json(const json_value_t *js,
    node_dialogue_t *node);
node_stories_t *fill_stories_node_by_json(const json_value_t *js,
    node_stories_t *node);
node_npc_t *fill_npc_node_by_json(const json_value_t *js, node_npc_t *node);
node_npc_t *json_to_npcs(json_value_t *js);

bool verif_npc_json(json_value_t *json_npc, json_value_t *json_stories,
    json_value_t *json_quests);
bool verif_json_value_stories(json_value_t *json_story,
    json_value_t *json_dialog);
bool verif_json_value_dialogue(json_value_t *json_dialog_opt,
    json_value_t *json_dialog);
bool is_missing(json_value_t *json, const char *key, bool is_string,
    const char *type);
bool verif_json_dialogue_option(json_value_t *json_dialog_option);

// linked list

void npc_dialogue_next(npc_t *npc);
void npc_dialogue_prev(npc_t *npc);
void reset_dialogues(npc_t *npc);
void npc_story_next(npc_t *npc);
void npc_next(game_t *game);
void fill_npc(npc_t *npc, char *path, sfVector2f pos, sfIntRect rect);

// sprite
void browse_and_fill_npc(game_t *game);
