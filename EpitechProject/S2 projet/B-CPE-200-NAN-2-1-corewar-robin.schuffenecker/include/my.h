/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** my
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "op.h"

typedef struct instruction_s {
    char *mnemonique;
    int nbr_args;
    int type[4];
    char code;
    int nbr_cycles;
    char *comment;
    struct instruction_s *next;
} instruction_t;

typedef struct champ_s {
    int num_champ;
    int prog_nb;
    int load_ad;
    char *prog_n;
    char **data;
    instruction_t *instru;
    struct champ_s *next;
} champ_t;

typedef struct env_s {
    uint8_t *memory;
    int memory_size;
} env_t;

typedef struct info_s {
    int dump;
    int nb_champ;
    champ_t *champ;
    env_t *env;
} info_t;


// LIB FUNCTION

int my_getnbr(char const *str);
void my_puterr(char const *str);
void my_putstr(char const *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcat(char *s1, char *s2);
char *my_strdup(char *src);
int my_strlen(char const *str);
int my_str_isalpha(char *str);
int my_char_isalphanum(char str);
int my_str_isalphanum(char *str);
int my_str_num(char *str);
char *my_strstr(char *str, char *to_find);
void my_putchar(char c);
char *my_put_nbr(int nb);
char *my_itoa(int score);

// INIT

info_t *init_struct(void);

// PARSING

int pars_arg(int ac, char **av, info_t *info);
int read_cor_file(char *file, champ_t *champ);

// LOAD CHAMPION IN MEMORY

void load_champions_in_mem(info_t *info, env_t *env);

// GAME LOOP

void game_loop(info_t *info);
void exec_instru(champ_t *champ, instruction_t *instru);
