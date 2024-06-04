/*
** EPITECH PROJECT, 2024
** alias.h
** File description:
** that file should include all things for alias
*/
#include "struct.h"

#pragma once

void correct_str(char *str);
void print_alias(alias_t *alias);
void correct_array(char **array);
void clean_esperluette(char *str);
alias_t *add_alias_from_rc(envp_info_t *info);
bool is_alias_looping(alias_t *alias, char *command);
char *replace_alias_in_str(char *str, alias_t *alias);
bool correct_str_alias(info_t *line, envp_info_t *envp);
void add_alias(alias_t **alias, char *name, char *value);
bool handle_alias_command(char *str, alias_t **alias, envp_info_t *info);
char *analyse_each_alias(char *array, alias_t *tmp, int *status);
