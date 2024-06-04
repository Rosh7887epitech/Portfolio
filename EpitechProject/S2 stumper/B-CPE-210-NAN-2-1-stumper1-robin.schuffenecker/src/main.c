/*
** EPITECH PROJECT, 2024
** boggle
** File description:
** boggle word finder
*/

#include "boggle.h"
#include <string.h>
#include <stdlib.h>

int is_lower_alpha(char *str)
{
    while (*str) {
        if (*str < 'a' || 'z' < *str) {
            return 0;
        }
        str++;
    }
    return 1;
}

int is_num(char *str)
{
    while (*str) {
        if (*str < '0' || '9' < *str) {
            return 0;
        }
        str++;
    }
    return 1;
}

int errors(int ac, char **av)
{
    int nbr_w = 0;
    int nbr_s = 0;

    if (ac < 3 || ac > 7 || ac % 2 == 0
        || strcmp(av[1], "-g") || !is_lower_alpha(av[2])) {
        return 1;
    }
    for (int i = 3; i < ac; i += 2) {
        if (!strcmp(av[i], "-w") && is_lower_alpha(av[i + 1]) && !nbr_w) {
            nbr_w++;
            continue;
        }
        if (!strcmp(av[i], "-s") && is_num(av[i + 1]) && !nbr_s) {
            nbr_s++;
            continue;
        }
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    infos_t infos;

    if (errors(ac, av)) {
        return 84;
    }
    if (!parse_args(ac, av, &infos)) {
        return 84;
    }
    if (infos.word) {
        find_word(&infos);
    } else {
        main_loop(ac, av, &infos);
    }
    return 0;
}
