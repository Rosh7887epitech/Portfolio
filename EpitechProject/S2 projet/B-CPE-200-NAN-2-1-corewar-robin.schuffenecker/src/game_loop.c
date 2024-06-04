/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** game_loop
*/

#include "my.h"

static void exec_champ(champ_t *champ)
{
    instruction_t *instru = champ->instru;

    if (instru == NULL)
        return;
    while (instru != NULL) {
        exec_instru(champ, instru);
        instru = instru->next;
    }
}

static void cond_loop(info_t *info, champ_t *current)
{
    if (current->prog_n != NULL)
        exec_champ(current);
    return;
}

static void cond_of_dump(int i, int j, uint8_t *memory, int memory_size)
{
    if (i + j < memory_size) {
        for (int k = 1; k >= 0; k--)
            my_putchar("0123456789ABCDEF"[(memory[i + j] >> (4 * k)) & 0xF]);
    } else
        my_putstr("  ");
    if ((j + 1) % 8 == 0)
        my_putchar(' ');
}

static void print_memory(uint8_t *memory, int memory_size)
{
    int bytes_per_line = 32;

    for (int i = 0; i < memory_size; i += bytes_per_line) {
        for (int j = 0; j < bytes_per_line; j++)
            cond_of_dump(i, j, memory, memory_size);
        my_putchar('\n');
    }
}

void game_loop(info_t *info)
{
    int cycle = 0;
    int prev_cycle = 0;
    champ_t *current = info->champ;

    while (cycle < info->dump) {
        while (current != NULL) {
            cond_loop(info, current);
            current = current->next;
        }
        print_memory(info->env->memory, info->env->memory_size);
        cycle++;
    }
}
