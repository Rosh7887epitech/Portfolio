/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** add_quest
*/

#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "rpg.h"
#include "macro.h"
#include "quest.h"
#include "text.h"

static node_quest_t *create_quest(json_value_t *json_quest_step)
{
    node_quest_t *node = calloc(1, sizeof(node_quest_t));
    quest_t quest = {0};

    if (verif_quest_json(json_quest_step, json_object_get(json_quest_step,
        "steps")) == 1)
        return NULL;
    quest.id = json_object_get_int(json_quest_step, "id");
    strncpy(quest.title, json_object_get_string(json_quest_step, "title"),
        sizeof(quest.title) - 1);
    quest.current_step = 0;
    quest.nb_steps = json_array_length(json_object_get(json_quest_step,
        "steps"));
    quest.status = NOT_STARTED;
    quest.n_quest_step = parse_quest_steps(json_object_get(json_quest_step,
        "steps"));
    quest.title_obj = create_text(quest.title);
    node->quest = quest;
    node->next = NULL;
    return node;
}

static void add_quest(node_quest_t **head, node_quest_t **current,
    json_value_t *json_quest_step)
{
    node_quest_t *node = create_quest(json_quest_step);

    if (!node)
        return;
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

static void reverse_list_quest(node_quest_t **head)
{
    node_quest_t *prev = NULL;
    node_quest_t *current = *head;
    node_quest_t *next = NULL;

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

static void set_start_for_each_node_quest(node_quest_t *head)
{
    node_quest_t *current = head;
    int index = 0;

    while (current != NULL) {
        current->index = index;
        index++;
        current->start = head;
        current = current->next;
    }
}

node_quest_t *parse_quests(json_value_t *json_quest)
{
    node_quest_t *head = NULL;
    node_quest_t *current = NULL;
    int count = 0;
    json_value_t *json_quest_step = NULL;

    if (!json_quest)
        return NULL;
    count = json_array_length(json_quest);
    for (int i = 0; i < count; i++) {
        json_quest_step = json_array_get(json_quest, i);
        if (!json_quest_step)
            continue;
        add_quest(&head, &current, json_quest_step);
    }
    reverse_list_quest(&head);
    set_start_for_each_node_quest(head);
    return head;
}
