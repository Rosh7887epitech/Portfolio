/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** quest
*/

#pragma once

#include <stdbool.h>
#include "my_json.h"
#include <SFML/Graphics.h>

#define QUESTS_FRAME "assets/images/cadrequest.png"

typedef enum {
    IN_PROGRESS,
    COMPLETED,
    NOT_STARTED
} quest_status_t;

typedef struct {
    int target_id;
    int target_type;
    int nb_to_kill;
    int nb_killed;
} quest_step_kill_t;

typedef struct {
    int target_id;
    int target_type;
    int nb_to_collect;
    int nb_collected;
} quest_step_collect_t;

typedef struct {
    int target_id;
    int target_type;
    int nb_to_talk;
    int nb_talked;
} quest_step_talk_t;

typedef enum {
    QUEST_KILL,
    QUEST_COLLECT,
    QUEST_TALK,
    QUEST_COUNT
} quest_type_t;

typedef struct quest_step_s {
    char description[256];
    sfText *description_obj;
    int status;
    int id;
    quest_type_t type;
    union {
        quest_step_kill_t kill;
        quest_step_collect_t collect;
        quest_step_talk_t talk;
    } data_t;
} quest_step_t;

typedef struct node_quest_step_s {
    quest_step_t quest_step;
    struct node_quest_step_s *next;
    struct node_quest_step_s *start;
    struct node_quest_step_s *prev;
    int index;
} node_quest_step_t;

typedef struct quest_s {
    int id;
    int status;
    int current_step;
    int nb_steps;
    char title[50];
    sfText *title_obj;
    node_quest_step_t *n_quest_step;
} quest_t;

typedef struct node_quest_s {
    quest_t quest;
    struct node_quest_s *next;
    struct node_quest_s *start;
    struct node_quest_s *prev;
    int index;
} node_quest_t;

typedef struct npc_s npc_t;

int wich_quest_type(json_value_t *json);

// quest

void free_quest(node_quest_t *head);
void print_quests(node_quest_t *head);
node_quest_t *parse_quests(json_value_t *json_quest);
node_quest_step_t *parse_quest_steps(json_value_t *json_quest_step);

// quest_step

void free_quest_step(node_quest_step_t *head);
void print_quest_step_kill(quest_step_kill_t kill);
void print_quest_step_collect(quest_step_collect_t collect);
void print_quest_step_talk(quest_step_talk_t talk);
void print_quest_steps(node_quest_step_t *step);

bool verif_quest_json(json_value_t *json_quest, json_value_t *json_quest_step);
bool verif_quest_step_collect(json_value_t *js_quest_step);
bool verif_quest_step_kill(json_value_t *js_quest_step);
bool verif_quest_step_talk(json_value_t *js_quest_step);
bool verif_quest_step_json(json_value_t *js_quest_step);
