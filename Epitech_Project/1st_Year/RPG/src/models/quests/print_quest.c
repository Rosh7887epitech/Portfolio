/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** printf_quest
*/

#include <stdio.h>
#include "quest.h"

void print_quests(node_quest_t *head)
{
    node_quest_t *current = head;

    if (!current) {
        printf("  No quests\n");
        return;
    }
    while (current != NULL) {
        printf("  Quest ID: %d, Title: %s, Current Step: %d, "
            "Number of Steps: %d\n", current->quest.id,
            current->quest.title, current->quest.current_step,
            current->quest.nb_steps);
        print_quest_steps(current->quest.n_quest_step);
        current = current->next;
    }
}
