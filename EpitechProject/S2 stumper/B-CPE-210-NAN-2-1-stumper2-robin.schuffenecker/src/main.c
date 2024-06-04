/*
** EPITECH PROJECT, 2024
** B-CPE-210-NAN-2-1-stumper2-robin.schuffenecker
** File description:
** main
*/

#include "my.h"
#include <stddef.h>
#include <stdio.h>

void main(int argc, char **argv)
{
    poke_s *poke = NULL;
    char *team_one;
    char *team_two;

    if (argc != 3)
        return 84;
    team_one = search_data(argv, "pokecfg/pikachu");
    team_two = search_data(argv, "pokecfg/pidgeotto");
    pars_arg(team_one, team_two, &poke);
    fight(poke, argv[1], argv[2]);

    free(team_one);
    free(team_two);
}
