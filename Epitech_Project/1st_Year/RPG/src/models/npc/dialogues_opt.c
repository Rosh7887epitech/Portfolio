/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** dialogues_opt
*/

#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "text.h"

static node_dialogue_opt_t *create_dialogue_option(
    json_value_t *json_dialog_option)
{
    node_dialogue_opt_t *node = calloc(1, sizeof(node_dialogue_opt_t));

    if (!node) {
        perror("Failed to allocate memory for Dialogue Option node");
        return NULL;
    }
    if (verif_json_dialogue_option(json_dialog_option) == 1)
        return NULL;
    node->dialog_opt.id = json_object_get_int(json_dialog_option, "id");
    strncpy(node->dialog_opt.text, json_object_get_string(json_dialog_option,
        "text"), sizeof(node->dialog_opt.text) - 1);
    node->next = NULL;
    return node;
}

static void add_dialogue_option(node_dialogue_opt_t **head,
    node_dialogue_opt_t **current, node_dialogue_opt_t *node)
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

static void reverse_list_opt(node_dialogue_opt_t **head)
{
    node_dialogue_opt_t *prev = NULL;
    node_dialogue_opt_t *current = *head;
    node_dialogue_opt_t *next = NULL;

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

static void set_start_for_each_node_opt(node_dialogue_opt_t *head)
{
    node_dialogue_opt_t *current = head;
    int index = 1;

    while (current != NULL) {
        current->start = head;
        current->index = index;
        index++;
        current = current->next;
    }
}

node_dialogue_opt_t *parse_dialogue_options(json_value_t *json_dialog_opt)
{
    node_dialogue_opt_t *head = NULL;
    node_dialogue_opt_t *current = NULL;
    int count = json_array_length(json_dialog_opt);
    json_value_t *json_dialog_option = NULL;
    node_dialogue_opt_t *node = NULL;

    for (int i = 0; i < count; i++) {
        json_dialog_option = json_array_get(json_dialog_opt, i);
        if (!json_dialog_option) {
            continue;
        }
        node = create_dialogue_option(json_dialog_option);
        if (node == NULL)
            continue;
        add_dialogue_option(&head, &current, node);
    }
    reverse_list_opt(&head);
    set_start_for_each_node_opt(head);
    return head;
}
