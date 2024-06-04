/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** main
*/

#include "include/my.h"
#include <stddef.h>
#include <stdlib.h>

static int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static char *my_strdup(char const *src)
{
    char *r = malloc(sizeof(char) * my_strlen(src) + 1);

    my_strcpy(r, src);
    return r;
}

int fill_cmd(char **av, game_t *game)
{
    int i = 0;
    int k = 1;

    while (i != 5 && k != 6) {
        game->cmd = malloc(sizeof(char *));
        game->cmd[i] = my_strdup(av[k]);
        i++;
        k++;
    }
    i = 0;
    while (i != game->ac) {
        if (game->cmd[i] == "-p1" && game->cmd[i + 1] != NULL)
            game->p1 = game->cmd[i + 1][0];
        if (game->cmd[i] == "-p2" && game->cmd[i + 1] != NULL)
            game->p2 = game->cmd[i + 1][0];
        if (game->cmd[i] == "-s" && game->cmd[i + 1] != NULL)
            game->map_size = atoi(game->cmd[i + 1]);
        i++;
    }
    return 0;
}

int check_cmd(game_t *game)
{
    int i = 0;
    int x = 0;

    if (game->map_size < 3)
        x = 1;
    if (game->p1 == '+' || game->p1 == '-'
    || game->p1 == ' ' || game->p1 == game->p2)
        x = 1;
    if (game->p2 == '+' || game->p2 == '-' || game->p2 == ' ')
        x = 1;
    if (x == 1)
        return 84;
}
