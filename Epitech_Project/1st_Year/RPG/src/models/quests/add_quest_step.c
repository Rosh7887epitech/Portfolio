/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** add_quest_step
*/

#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "rpg.h"
#include "macro.h"
#include "quest.h"
#include "text.h"

static quest_step_kill_t create_quest_step_kill(json_value_t *js_quest_step)
{
    quest_step_kill_t quest_step = {0};

    if (verif_quest_step_kill(js_quest_step) == true)
        return quest_step;
    quest_step.nb_to_kill = json_object_get_int(js_quest_step, "nb_to_kill");
    quest_step.target_id = json_object_get_int(js_quest_step, "target_id");
    quest_step.target_type = json_object_get_int(js_quest_step, "target_type");
    quest_step.nb_killed = 0;
    return quest_step;
}

static quest_step_collect_t create_quest_step_collect(
    json_value_t *js_quest_step)
{
    quest_step_collect_t quest_step = {0};

    if (verif_quest_step_talk(js_quest_step) == true)
        return quest_step;
    quest_step.nb_to_collect = json_object_get_int(js_quest_step,
        "nb_to_collect");
    quest_step.target_id = json_object_get_int(js_quest_step, "target_id");
    quest_step.target_type = json_object_get_int(js_quest_step, "target_type");
    quest_step.nb_collected = 0;
    return quest_step;
}

static quest_step_talk_t create_quest_step_talk(json_value_t *js_quest_step)
{
    quest_step_talk_t quest_step = {0};

    if (verif_quest_step_talk(js_quest_step) == true)
        return quest_step;
    quest_step.nb_to_talk = json_object_get_int(js_quest_step, "nb_to_talk");
    quest_step.target_id = json_object_get_int(js_quest_step, "target_id");
    quest_step.target_type = json_object_get_int(js_quest_step, "target_type");
    quest_step.nb_talked = 0;
    return quest_step;
}

static quest_step_t parse_quest_step(json_value_t *js_quest_step,
    quest_step_t quest_step)
{
    switch (quest_step.type) {
        case QUEST_KILL:
            quest_step.data_t.kill = create_quest_step_kill(js_quest_step);
            break;
        case QUEST_TALK:
            quest_step.data_t.talk = create_quest_step_talk(js_quest_step);
            break;
        case QUEST_COLLECT:
            quest_step.data_t.collect =
                create_quest_step_collect(js_quest_step);
            break;
        case QUEST_COUNT:
            break;
    }
    return quest_step;
}

static node_quest_step_t *create_quest_step(json_value_t *js_quest_step)
{
    node_quest_step_t *node = calloc(1, sizeof(node_quest_step_t));
    quest_step_t quest_step = {0};

    if (!node) {
        perror("Failed to allocate memory for Quest Step node");
        return NULL;
    }
    if (verif_quest_step_json(js_quest_step) == true)
        return NULL;
    quest_step.id = json_object_get_int(js_quest_step, "id");
    strncpy(quest_step.description, json_object_get_string(js_quest_step,
        "description"), sizeof(quest_step.description) - 1);
    quest_step.type = wich_quest_type(js_quest_step);
    quest_step.status = NOT_STARTED;
    quest_step = parse_quest_step(js_quest_step, quest_step);
    quest_step.description_obj = create_text(quest_step.description);
    node->quest_step = quest_step;
    node->next = NULL;
    return node;
}

static void add_quest_step(node_quest_step_t **head,
    node_quest_step_t **current, json_value_t *json_quest_step_step)
{
    node_quest_step_t *node = create_quest_step(json_quest_step_step);

    if (*head == NULL) {
        *head = node;
        *current = *head;
        node->prev = NULL;
    } else {
        node->prev = *current;
        (*current)->next = node;
        *current = (*current)->next;
    }
    node->next = NULL;
}

static void reverse_list_quest_step(node_quest_step_t **head)
{
    node_quest_step_t *prev = NULL;
    node_quest_step_t *current = *head;
    node_quest_step_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        if (prev)
            prev->prev = current;
        prev = current;
        current = next;
    }
    *head = prev;
    if (head)
        (*head)->prev = NULL;
}

static void set_start_for_each_node_quest_step(node_quest_step_t *head)
{
    node_quest_step_t *current = head;
    int index = 0;

    while (current != NULL) {
        current->index = index;
        index++;
        current->start = head;
        current = current->next;
    }
}

node_quest_step_t *parse_quest_steps(json_value_t *json_quest_step)
{
    node_quest_step_t *head = NULL;
    node_quest_step_t *current = NULL;
    int count = 0;
    json_value_t *json_quest_step_step = NULL;

    if (!json_quest_step)
        return NULL;
    count = json_array_length(json_quest_step);
    for (int i = 0; i < count; i++) {
        json_quest_step_step = json_array_get(json_quest_step, i);
        if (!json_quest_step_step)
            continue;
        add_quest_step(&head, &current, json_quest_step_step);
    }
    reverse_list_quest_step(&head);
    set_start_for_each_node_quest_step(head);
    return head;
}
