/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** instruction
*/

#include "my.h"

static void exec_instru_two(instruction_t *instru)
{
    if (my_strcmp(instru->mnemonique, "xor") == 0)
        my_putstr("xor\n");
    if (my_strcmp(instru->mnemonique, "zjmp") == 0)
        my_putstr("zjmp\n");
    if (my_strcmp(instru->mnemonique, "ldi") == 0)
        my_putstr("ldi\n");
    if (my_strcmp(instru->mnemonique, "sti") == 0)
        my_putstr("sti\n");
    if (my_strcmp(instru->mnemonique, "fork") == 0)
        my_putstr("fork\n");
    if (my_strcmp(instru->mnemonique, "lld") == 0)
        my_putstr("lld\n");
    if (my_strcmp(instru->mnemonique, "lldi") == 0)
        my_putstr("lldi\n");
    if (my_strcmp(instru->mnemonique, "lfork") == 0)
        my_putstr("lfork\n");
    if (my_strcmp(instru->mnemonique, "aff") == 0)
        my_putstr("aff\n");
}

void exec_instru(champ_t *champ, instruction_t *instru)
{
    if (my_strcmp(instru->mnemonique, "live") == 0) {
        my_putstr("The player ");
        my_put_nbr(champ->prog_nb);
        my_putstr(champ->prog_n);
        my_putstr(" is alive.\n");
    }
    if (my_strcmp(instru->mnemonique, "ld") == 0)
        my_putstr("ld\n");
    if (my_strcmp(instru->mnemonique, "st") == 0)
        my_putstr("st\n");
    if (my_strcmp(instru->mnemonique, "add") == 0)
        my_putstr("add\n");
    if (my_strcmp(instru->mnemonique, "sub") == 0)
        my_putstr("sub\n");
    if (my_strcmp(instru->mnemonique, "and") == 0)
        my_putstr("and\n");
    if (my_strcmp(instru->mnemonique, "or") == 0)
        my_putstr("or\n");
    else
        exec_instru_two(instru);
}
