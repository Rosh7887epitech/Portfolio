/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** npc_dialogues
*/

#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "text.h"

static node_dialogue_t *create_dialogue(json_value_t *json_dialog)
{
    node_dialogue_t *node = calloc(1, sizeof(node_dialogue_t));
    json_value_t *json_dialog_opt = json_object_get(json_dialog, "dialog_opt");

    if (!node) {
        perror("Failed to allocate memory for Dialogue node");
        return NULL;
    }
    if (verif_json_value_dialogue(json_dialog_opt, json_dialog) == 1)
        return NULL;
    node->dialog.id = json_object_get_int(json_dialog, "id");
    strncpy(node->dialog.name, json_object_get_string(json_dialog, "name"),
        sizeof(node->dialog.name) - 1);
    node->dialog.name_obj = create_text(node->dialog.name);
    strncpy(node->dialog.text, json_object_get_string(json_dialog, "text"),
        sizeof(node->dialog.text) - 1);
    node->dialog.text_obj = create_text(node->dialog.text);
    node->dialog.n_dialog_opt = parse_dialogue_options(json_dialog_opt);
    node->next = NULL;
    return node;
}

static void add_dialogues(node_dialogue_t **head, node_dialogue_t **current,
    node_dialogue_t *node)
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

static void reverse_list(node_dialogue_t **head)
{
    node_dialogue_t *prev = NULL;
    node_dialogue_t *current = *head;
    node_dialogue_t *next = NULL;

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

static void set_start_for_each_node(node_dialogue_t *head)
{
    node_dialogue_t *current = head;
    int index = 1;

    while (current != NULL) {
        current->index = index;
        index++;
        current->start = head;
        current = current->next;
    }
}

node_dialogue_t *parse_dialogues(json_value_t *json_dialogs)
{
    node_dialogue_t *head = NULL;
    node_dialogue_t *current = NULL;
    int count = json_array_length(json_dialogs);
    json_value_t *json_dialog = NULL;
    node_dialogue_t *node = NULL;

    for (int i = 0; i < count; i++) {
        json_dialog = json_array_get(json_dialogs, i);
        if (!json_dialog)
            continue;
        node = create_dialogue(json_dialog);
        if (node == NULL)
            continue;
        add_dialogues(&head, &current, node);
    }
    reverse_list(&head);
    set_start_for_each_node(head);
    return head;
}

void npc_dialogue_next(npc_t *npc)
{
    if (npc == NULL || npc->n_stories == NULL ||
        npc->n_stories->stories.n_dialog == NULL)
        return;
    if (npc->n_stories->stories.n_dialog->next == NULL) {
        npc->n_quest->quest.current_step++;
        reset_dialogues(npc);
        return;
    }
    if (npc->n_stories->stories.n_dialog != NULL &&
        npc->n_stories->stories.n_dialog->next != NULL)
        npc->n_stories->stories.n_dialog =
            npc->n_stories->stories.n_dialog->next;
}

void npc_dialogue_prev(npc_t *npc)
{
    if (npc == NULL || npc->n_stories == NULL ||
        npc->n_stories->stories.n_dialog == NULL)
        return;
    if (npc->n_stories->stories.n_dialog != NULL &&
        npc->n_stories->stories.n_dialog->prev != NULL)
        npc->n_stories->stories.n_dialog =
            npc->n_stories->stories.n_dialog->prev;
}

void reset_dialogues(npc_t *npc)
{
    if (npc == NULL || npc->n_stories == NULL ||
        npc->n_stories->stories.n_dialog == NULL)
        return;
    npc->n_stories->stories.n_dialog = npc->n_stories->stories.n_dialog->start;
    npc->is_spoken = false;
}
