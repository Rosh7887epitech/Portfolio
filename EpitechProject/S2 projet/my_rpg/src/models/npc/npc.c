/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** npc
*/

#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "rpg.h"
#include "macro.h"
#include "quest.h"
#include "text.h"

npc_t *get_npc_by_id(game_t *game, int id)
{
    node_npc_t *current = game->n_npc;

    while (current != NULL) {
        if (current->npc.id == id)
            return (&current->npc);
        current = current->next;
    }
    return (NULL);
}

int json_array_length(json_value_t *json_array)
{
    int count = 0;
    json_array_t *array = json_array->data.array;

    while (array != NULL) {
        count++;
        array = array->next;
    }
    return count;
}

static node_npc_t *create_npc(json_value_t *json_npc)
{
    node_npc_t *node = calloc(1, sizeof(node_npc_t));
    npc_t npc = {0};
    json_value_t *json_stories = json_object_get(json_npc, "stories");
    json_value_t *json_quests = json_object_get(json_npc, "quests");

    if (verif_npc_json(json_npc, json_stories, json_quests) == 1)
        return NULL;
    if (!node)
        return NULL;
    npc.id = json_object_get_int(json_npc, "id");
    npc.n_quest = NULL;
    strncpy(npc.name, json_object_get_string(json_npc, "name"),
        sizeof(npc.name) - 1);
    npc.n_stories = parse_stories(json_stories);
    npc.n_quest = parse_quests(json_quests);
    npc.name_obj = create_text(npc.name);
    npc.is_spoken = false;
    node->npc = npc;
    node->next = NULL;
    return node;
}

static void add_npcs(node_npc_t **head, node_npc_t **current, node_npc_t *node)
{
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

static node_npc_t *parse_npc(int count, json_value_t *js)
{
    node_npc_t *head = NULL;
    node_npc_t *current = NULL;
    json_value_t *npc = NULL;
    node_npc_t *node = NULL;

    for (int i = 0; i < count; i++) {
        npc = json_array_get(js, i);
        if (!npc)
            continue;
        node = create_npc(npc);
        if (node == NULL)
            continue;
        add_npcs(&head, &current, node);
    }
    return head;
}

static void reverse_list(node_npc_t **head)
{
    node_npc_t *prev = NULL;
    node_npc_t *current = *head;
    node_npc_t *next = NULL;

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

static void set_start_for_each_node(node_npc_t *head)
{
    node_npc_t *current = head;
    int index = 1;

    while (current != NULL) {
        current->index = index;
        index++;
        current->start = head;
        current = current->next;
    }
}

node_npc_t *json_to_npcs(json_value_t *js)
{
    node_npc_t *head = NULL;
    json_value_t *npcs = json_object_get(js, "npcs");
    int count = json_array_length(npcs);

    if (npcs == NULL) {
        printf("No npcs found.\n");
        return NULL;
    }
    head = parse_npc(count, npcs);
    reverse_list(&head);
    set_start_for_each_node(head);
    return head;
}

void npc_next(game_t *game)
{
    if (game->n_npc == NULL)
        return;
    if (game->n_npc->next != NULL)
        game->n_npc = game->n_npc->next;
}

void npc_story_next(npc_t *npc)
{
    if (npc == NULL || npc->n_stories == NULL ||
        npc->n_stories->stories.n_dialog == NULL)
        return;
    if (npc->n_stories->next != NULL)
        npc->n_stories = npc->n_stories->next;
}
