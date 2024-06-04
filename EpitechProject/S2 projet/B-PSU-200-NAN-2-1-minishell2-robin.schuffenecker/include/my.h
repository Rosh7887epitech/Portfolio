/*
** EPITECH PROJECT, 2023
** my
** File description:
** my h
*/

#pragma once

    #include <time.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <errno.h>
    #include <unistd.h>
    #include <string.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>

typedef struct base_s {
    int j;
    char *n;
    int save;
    int status;
    int re_status;
    char **env;
    char **com;
    char **path;
    int nb_rows;
    char *f_name;
    char *old_path;
    char **command;
    int exit;
} base_t;

#include "command.h"

void my_putchar(char c);
char *my_put_nbr(int nb);
char *my_itoa(int score);
int disp_env(char **env);
int my_str_num(char *str);
char *my_strdup(char *src);
int nb_of_slash(char *str);
int verif_name(char **name);
int my_str_isalpha(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int my_str_isalphanum(char *str);
int my_char_isalphanum(char str);
int nb_of_char(char *str, char c);
int my_strcmp(char *s1, char *s2);
void my_putsterr(char const *str);
char **mem_dup_2d_array(char **arr);
char *my_strcat(char *dest, char *src);
int my_strncmp(char *s1, char *s2, int n);
int main(int argc, char **argv, char **env);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char *src, int n);
char **my_str_to_word_tok(char *str, char *sep);
char **my_str_to_word_array(char *str, char sep);

int main_loop(base_t *var);
char **search_path(char **env);
int main(int argc, char **argv, char **env);
int my_access_denied(char *line, base_t *var);
int cond_loop(base_t *var, char *line, int res);
