/*
** EPITECH PROJECT, 2024
** B-CPE-210-NAN-2-1-stumper2-robin.schuffenecker
** File description:
** my
*/

#pragma once

typedef struct poke_stat_t {
    char *name;
    int attack;
    int defense;
    int speed;
    int health;
    struct poke_stat_t *next;
} poke_s;

char *search_data(char **argv, char *filepath);
int my_getnbr(char const *str);
char **my_str_to_word_array(char *str, char sep);
int pars_arg(char *t1, char *t2, poke_s **poke);
int fight(poke_s *poke, char *player1, char *player2);
