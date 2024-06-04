/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** parsing
*/

#include "my.h"

static instruction_t *create_instruction(char *file)
{
    champ_t *champ = malloc(sizeof(champ_t));
    instruction_t *instru = NULL;

    if (champ == NULL)
        return NULL;
    champ->next = NULL;
    if (read_cor_file(file, champ) != 0) {
        free(champ);
        return NULL;
    }
    instru = champ->instru;
    free(champ);
    return instru;
}

static void fill_instru_list(info_t *info, instruction_t **instru_l)
{
    instruction_t *last = NULL;
    champ_t *current = info->champ;

    *instru_l = NULL;
    while (current != NULL) {
        if (read_cor_file(current->prog_n, current) != 0) {
            current = current->next;
            continue;
        }
        if (*instru_l == NULL)
            *instru_l = current->instru;
        else
            last->next = current->instru;
        last = current->instru;
        while (last->next != NULL) {
            last = last->next;
        }
        current = current->next;
    }
}

static int check_valid_file(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return 84;
    if (close(fd) == -1)
        return 84;
    return 0;
}

static void add_champ(info_t *info, champ_t *new)
{
    champ_t *current = info->champ;

    if (info->champ == NULL)
        info->champ = new;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
}

static void check_arg(char **av, champ_t *new, int i)
{
    if (my_strcmp(av[i], "-a") == 0 && av[i + 1] != NULL &&
        my_strcmp(av[i + 1], "-dump") != 0 &&
        my_strcmp(av[i + 1], "-n") != 0) {
        new->load_ad = my_getnbr(av[i + 1]);
    } else
        new->load_ad = MEM_SIZE % 4;
    if (my_strcmp(av[i], "-n") == 0 && av[i + 1] != NULL &&
        my_strcmp(av[i + 1], "-dump") != 0 &&
        my_strcmp(av[i + 1], "-a") != 0) {
        new->prog_nb = my_getnbr(av[i + 1]);
    } else
        new->prog_nb = 5;
}

static int check_file(char **av, info_t *info, int i)
{
    char *test = my_strstr(av[i], ".cor");
    champ_t *new = NULL;

    new = malloc(sizeof(champ_t));
    if (new == NULL)
        return 1;
    check_arg(av, new, i);
    info->nb_champ++;
    new->num_champ = info->nb_champ;
    if (test != NULL) {
        if (check_valid_file(av[i]) == 84)
            return 84;
        new->prog_n = my_strdup(av[i]);
    }
    new->data = NULL;
    new->next = NULL;
    add_champ(info, new);
    return 0;
}

int pars_arg(int ac, char **av, info_t *info)
{
    if (ac < 3)
        return 84;
    for (int i = 0; av[i] != NULL; i++) {
        if (check_file(av, info, i) == 84)
            return 84;
        if (my_strcmp(av[i], "-dump") == 0 && av[i + 1] != NULL &&
            my_strcmp(av[i + 1], "-a") != 0 &&
            my_strcmp(av[i + 1], "-n") != 0) {
            info->dump = my_getnbr(av[i + 1]);
        } else
            info->dump = 200;
    }
    fill_instru_list(info, &info->champ->instru);
    return 0;
}
