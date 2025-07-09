/*
** EPITECH PROJECT, 2025
** Zappynian
** File description:
** win
*/

#ifndef WIN_H
    #define WIN_H

    #include "player.h"
    #include "team.h"
    #include <string.h>

bool win_check(const char *team_name, player_t **players, int player_count);
void check_victory(server_t *server);

#endif // WIN_H
