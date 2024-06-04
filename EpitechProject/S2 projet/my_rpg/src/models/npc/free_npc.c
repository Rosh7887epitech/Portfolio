/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** free_npc
*/

#include <stdlib.h>
#include "npc.h"

void free_dialogue_opt(node_dialogue_opt_t *head)
{
    node_dialogue_opt_t *current = head;
    node_dialogue_opt_t *next = NULL;

    while (current != NULL && current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_dialogue(node_dialogue_t *head)
{
    node_dialogue_t *current = head;
    node_dialogue_t *next = NULL;

    while (current != NULL && current->next != NULL) {
        next = current->next;
        if (current->dialog.n_dialog_opt != NULL) {
            free_dialogue_opt(current->dialog.n_dialog_opt);
        }
        free(current);
        current = next;
    }
}

void free_stories(node_stories_t *head)
{
    node_stories_t *current = head;
    node_stories_t *next = NULL;

    while (current != NULL && current->next != NULL) {
        next = current->next;
        if (current->stories.n_dialog != NULL)
            free_dialogue(current->stories.n_dialog);
        free(current);
        current = next;
    }
}

void free_npc(node_npc_t *head)
{
    node_npc_t *current = head;
    node_npc_t *next = NULL;

    while (current != NULL && current->next != NULL) {
        next = current->next;
        if (current->npc.n_stories != NULL) {
            free_stories(current->npc.n_stories);
        }
        if (current->npc.n_quest != NULL)
            free_quest(current->npc.n_quest);
        free(current);
        current = next;
    }
}
