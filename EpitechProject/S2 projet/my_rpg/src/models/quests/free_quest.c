/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** free_quest
*/

#include <stdlib.h>
#include "quest.h"

void free_quest_step(node_quest_step_t *head)
{
    node_quest_step_t *current = head;
    node_quest_step_t *next = NULL;

    while (current != NULL && current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_quest(node_quest_t *head)
{
    node_quest_t *current = head;
    node_quest_t *next = NULL;

    while (current != NULL && current->next != NULL) {
        next = current->next;
        if (current->quest.n_quest_step != NULL)
            free_quest_step(current->quest.n_quest_step);
        free(current);
        current = next;
    }
}
