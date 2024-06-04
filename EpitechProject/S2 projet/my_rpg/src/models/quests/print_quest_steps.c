/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** print_quest_steps
*/

#include <stdio.h>
#include "quest.h"

void print_quest_step_kill(quest_step_kill_t kill)
{
    printf("    Kill: Target ID %d, To Kill %d, Killed %d, target type %d\n",
        kill.target_id, kill.nb_to_kill, kill.nb_killed, kill.target_type);
}

void print_quest_step_collect(quest_step_collect_t collect)
{
    printf("    Collect: Target ID %d, To Collect %d, Collected %d\n",
        collect.target_id, collect.nb_to_collect, collect.nb_collected);
}

void print_quest_step_talk(quest_step_talk_t talk)
{
    printf("    Talk: Target ID %d, To Talk %d, Talked %d\n",
        talk.target_id, talk.nb_to_talk, talk.nb_talked);
}

static void print_switch(quest_step_t step)
{
    switch (step.type) {
        case QUEST_KILL:
            print_quest_step_kill(step.data_t.kill);
            break;
        case QUEST_COLLECT:
            print_quest_step_collect(step.data_t.collect);
            break;
        case QUEST_TALK:
            print_quest_step_talk(step.data_t.talk);
            break;
        default:
            break;
    }
}

void print_quest_steps(node_quest_step_t *step)
{
    node_quest_step_t *current = step;

    if (!current) {
        printf("    No steps\n");
        return;
    }
    while (current != NULL) {
        printf("    Step ID: %d, Description: %s, Status: %d\n",
            current->quest_step.id, current->quest_step.description,
            current->quest_step.status);
        print_switch(current->quest_step);
        current = current->next;
    }
}
