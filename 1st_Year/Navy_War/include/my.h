/*
** EPITECH PROJECT, 2023
** my
** File description:
** my h
*/

#pragma once

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <signal.h>
    #include <stdio.h>

typedef struct base_s {
    int x;
    int y;
    int sx;
    int sy;
    int ex;
    int ey;
    int row;
    int col;
    char *buff;
    int pid_one;
    int pid_two;
    char *buff_two;
    char **map_pone;
    char **map_ptwo;
    char **pos_file;
    char **pos_file_two;
} base_t;

typedef struct glob_var {
    int u1;
    int u2;
    int bol;
    int temp;
} g_t;

extern g_t var_sig;

int signal_me(void);
int receive_sig(void);
int my_put_nbr(int nb);
int is_alphanum(char c);
void my_putchar(char c);
char *my_itoa(int score);
int loop_one(base_t *var);
int loop_two(base_t *var);
int verif_map(base_t *var);
char *my_strdup(char *src);
int attack_one(base_t *var);
int attack_two(base_t *var);
void create_map(base_t *var);
int defense_one(base_t *var);
int defense_two(base_t *var);
int verif_map_two(base_t *var);
int load_boat_two(base_t *var);
int load_boat_one(base_t *var);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int main(int argc, char **argv);
int display_map_pone(base_t *var);
int display_map_ptwo(base_t *var);
int my_strcmp(char *s1, char *s2);
int get_nb_words(char const *str);
char conv_letter(base_t *var, int i);
int game_base(int argc, char **argv);
char **my_str_to_word_array(char *str);
int h_or_m_one(base_t *var, char *line);
int h_or_m_two(base_t *var, char *line);
int hit_boat(base_t *var, int x, int y);
int ping_one(base_t *var, int x, int y);
int ping_two(base_t *var, int x, int y);
int is_good_num(base_t *var, int x, int y);
int search_letter(base_t *var, char *line);
int recup_pos_one(base_t *var, char *line);
int recup_pos_two(base_t *var, char *line);
int hit_boat_two(base_t *var, int x, int y);
int filereader(base_t *var, char *file_pos);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char *src, int n);
int is_good_num_two(base_t *var, int x, int y);
int filereader_ptwo(base_t *var, char *file_pos);
int player_one(int argc, char **argv, base_t *var);
int player_two(int argc, char **argv, base_t *var);
char *push_str(char *str, int score, int i, int nb);
int case_length(int score, int length, int temp_score);
void handler(int signal, siginfo_t *info, void *context);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
