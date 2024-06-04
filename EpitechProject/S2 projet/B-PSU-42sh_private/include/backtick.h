/*
** EPITECH PROJECT, 2024
** backtick.h
** File description:
** include for all backtick functionnality
*/

#pragma once

bool error_backtick(char *str);
char **remove_useless_char_tab(char **array);
int handle_backtick(char *line, envp_info_t *info);
int handle_unknown_command(char *env_find, char *input);
int is_invalid_tick_cmd(char **tab_tick, int i, char *line, envp_info_t *info);
