/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** boggle header
*/

#pragma once

typedef struct infos_s {
    char *letters;
    char *word;
    int size;
    char **grid;
} infos_t;

int explore_grid(char **grid, int i, int j, char *str);
int parse_args(int ac, char **av, infos_t *infos);
int main_loop(int ac, char **av, infos_t *infos);
void display_boggle(infos_t *infos);
int find_word(infos_t *infos);
int my_strlen(char *str);
void my_putchar(char c);
char *my_putstr(char *str);
