/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** print_npc
*/

#include <stdio.h>
#include "npc.h"

void print_dialogue_options(node_dialogue_opt_t *head)
{
    node_dialogue_opt_t *current = head;

    while (current != NULL) {
        printf("      Option ID: %d, Text: %s\n",
            current->dialog_opt.id, current->dialog_opt.text);
        current = current->next;
    }
}

void print_dialogues(node_dialogue_t *head)
{
    node_dialogue_t *current = head;

    while (current != NULL) {
        printf("    Dialogue ID: %d, Name: %s, Text: %s\n", current->dialog.id,
            current->dialog.name, current->dialog.text);
        printf("     Options:\n");
        print_dialogue_options(current->dialog.n_dialog_opt);
        current = current->next;
    }
}

void print_stories(node_stories_t *head)
{
    node_stories_t *current = head;

    while (current != NULL) {
        printf("  Stories ID: %d, Name: %s\n", current->stories.id,
            current->stories.name);
        printf("   Dialogues:\n");
        print_dialogues(current->stories.n_dialog);
        current = current->next;
    }
}

void print_npc(npc_t npc)
{
    printf("NPC ID: %d, Name: %s\n", npc.id, npc.name);
    printf(" Stories:\n");
    print_stories(npc.n_stories);
    printf(" Quests:\n");
    print_quests(npc.n_quest);
}
