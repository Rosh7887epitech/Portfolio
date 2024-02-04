/*
** EPITECH PROJECT, 2024
** main
** File description:
** main navy
*/

#include "my.h"

int game_base(int argc, char **argv)
{
    base_t *var = malloc(sizeof(base_t));

    create_map(var);
    if (argc == 2)
        if (player_one(argc, argv, var) == 84)
            return 84;
    if (argc == 3)
        if (player_two(argc, argv, var) == 84)
            return 84;
}

int main(int argc, char **argv)
{
    if (game_base(argc, argv) == 84)
        return 84;
}
