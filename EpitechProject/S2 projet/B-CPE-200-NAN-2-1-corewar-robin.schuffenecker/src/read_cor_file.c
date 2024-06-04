/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** read_cor_file
*/

#include "my.h"
#include "op.h"

static void init_new_instru(uint8_t coding_byte, instruction_t *new_instru,
    op_t *instruction)
{
    new_instru->mnemonique = my_strdup(instruction->mnemonique);
    new_instru->nbr_args = instruction->nbr_args;
    for (int i = 0; i < instruction->nbr_args; i++)
        new_instru->type[i] = instruction->type[i];
    new_instru->code = coding_byte;
    new_instru->nbr_cycles = instruction->nbr_cycles;
    new_instru->comment = my_strdup(instruction->comment);
    new_instru->next = NULL;
}

static void cond_new_instru(champ_t *champ, instruction_t *new_instru,
    instruction_t *last_instru)
{
    if (champ->instru == NULL) {
        champ->instru = new_instru;
    } else {
        last_instru = champ->instru;
        while (last_instru->next != NULL)
            last_instru = last_instru->next;
        last_instru->next = new_instru;
    }
}

static void decode_instruction(uint8_t coding_byte, champ_t *champ)
{
    op_t *instruction = NULL;
    instruction_t *new_instru = malloc(sizeof(instruction_t));
    instruction_t *last_instru = NULL;

    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (op_tab[i].code == coding_byte) {
            instruction = &op_tab[i];
            break;
        }
    }
    if (instruction == NULL || new_instru == NULL)
        return;
    init_new_instru(coding_byte, new_instru, instruction);
    cond_new_instru(champ, new_instru, last_instru);
}

int read_cor_file(char *file, champ_t *champ)
{
    int fd = open(file, O_RDONLY);
    uint8_t coding_byte;
    ssize_t bytes_read;

    if (fd == -1)
        return 1;
    for (; bytes_read = read(fd, &coding_byte, sizeof(coding_byte));) {
        if (bytes_read > 0)
            decode_instruction(coding_byte, champ);
    }
    if (bytes_read == -1) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}
