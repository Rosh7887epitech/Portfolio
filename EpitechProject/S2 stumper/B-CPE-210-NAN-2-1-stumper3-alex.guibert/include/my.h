/*
** EPITECH PROJECT, 2023
** B-CP7
** File description:
** my
*/

#pragma once

typedef struct game {
    int ac;
    char **cmd;
    char p1;
    char p2;
    int map_size;
    int n_p1;
    int n_p2;
    char **game_map;
}game_t;

int fill_cmd(char **av, game_t *game);
int check_cmd(game_t *game);
int main_loop(game_t *game);
char **create_grid(int size);
int check_end(char **grid);
char **my_str_to_word_tok(char *str, char *sep);
char *my_strdup(char const *str);
