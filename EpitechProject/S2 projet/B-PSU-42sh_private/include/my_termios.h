/*
** EPITECH PROJECT, 2024
** termios.h
** File description:
** that file should handle termios
*/
#pragma once

void clean_term(term_stru_t *term);
void move_cursor(int row, int col);
bool handle_arrow_left(term_stru_t *term);
bool handle_arrow_right(term_stru_t *term);
char *remove_char_str(char *str, int index);
void get_cursor_position(int *row, int *col);
void get_input(envp_info_t *envp, info_t *line);
char *add_char_str(char *str, char c, int index);
int get_the_line(info_t *line, envp_info_t *envp);
bool handle_arrow_up(char **array, term_stru_t *term);
bool handle_arrow_down(char **array, term_stru_t *term);
bool handle_tabulation(envp_info_t *info, term_stru_t *term);
void read_auto_completion(char *filename, term_stru_t *term);
void add_file_to_tab(char *str, char *filename, term_stru_t *term);
bool tabulation_with_path(char **tab, term_stru_t *term, envp_info_t *info);
