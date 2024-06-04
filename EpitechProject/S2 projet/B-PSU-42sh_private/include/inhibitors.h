/*
** EPITECH PROJECT, 2024
** inhibitors.h
** File description:
** that file should include all things for inhibitors
*/

#pragma once

#include "my_project.h"

typedef enum quotes_e {
    NO_QUOTES,
    SINGLE_QUOTES,
    DOUBLE_QUOTES
}quotes_t;

int count_quotes(char *str);
char *remove_quotes(char *str);
void print_set_list(path_t *list, envp_info_t *info);
char **rm_quotes_tab(char **array);
quotes_t is_pos_in_quotes(char *str, int pos);
char **str_to_word_array(char *str, char *delim);
char *add_delim_to_quotes(char *str, char *delim);
char *str_cat_to_pos(char *str, char *cat, int pos);
void modify_q_status(char line, bool *sq, bool *dq);
int local_functions(info_t *line, envp_info_t *info);
int check_inhibitors(info_t *line, envp_info_t *infos);
void error_injection(char ***command, envp_info_t *info);
void our_sh(info_t *line, envp_info_t *envp, int status);
char **remove_quotes_before_list(char **array, char *del1, char *del2);
char **strtok_with_quotes(char *str, char *delim);
bool is_char_alpha(char c);
