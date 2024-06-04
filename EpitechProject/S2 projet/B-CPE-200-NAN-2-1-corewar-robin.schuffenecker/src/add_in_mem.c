/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** add_in_mem
*/

#include "my.h"

static void load_instru_in_mem(champ_t *champion, env_t *env)
{
    int id = 0;
    int mem_address = 0;
    int address = champion->load_ad;
    instruction_t *instruction = champion->instru;

    while (instruction != NULL) {
        id = instruction->code;
        mem_address = address % env->memory_size;
        env->memory[mem_address] = id;
        instruction = instruction->next;
        address++;
    }
}

void load_champions_in_mem(info_t *info, env_t *env)
{
    champ_t *current_champion = info->champ;

    while (current_champion != NULL) {
        if (current_champion->prog_n != NULL)
            load_instru_in_mem(current_champion, env);
        current_champion = current_champion->next;
    }
}
