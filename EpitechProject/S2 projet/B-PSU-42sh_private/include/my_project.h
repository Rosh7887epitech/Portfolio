/*
** EPITECH PROJECT, 2023
** my_project.h
** File description:
** header of my project
*/
#include <stdbool.h>
#include "globbings.h"
#include "special_variable.h"
#include "dollar.h"
#include "jobs.h"
#include "struct.h"
#include "history.h"
#include "alias.h"
#include "esperluette.h"
#include "pipes_or.h"
#include "my_termios.h"
#include "inhibitors.h"
#include "backtick.h"

#pragma once

envp_info_t *alloc_struct(char **envp);
void free_struct(envp_info_t *environ);

int lenght_list(path_t *list);
void print_list(path_t *list);
path_t *create_node(char *value);
path_t *envp_to_list(char **envp);
void add_end(path_t **list, char *value);
int remove_envp(path_t **list, char *value);
path_t *free_pos(path_t *list, char *value);
char **list_to_array(path_t *list, char *value);

char *my_itoa(int number);
int my_put_nbr(int number);
int is_alphanum(char *str);
int my_getnbr(char *string);
int is_charalphanum(char str);
void my_putchar(char character);
int my_strlen(char const *string);
char *char_to_str(char character);
void my_putstr(char const *string);
char *my_strdup(char const *string);
int my_strcmp(char *str1, char *str2);
char *my_strcat(char *dest, char *src);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcpy(char *dest, char const *src);
void my_strncpy(char *dest, char *src, int n);
int my_printerror(char *str, int return_status);
char **my_strtok(char const *str, char *delimiter);
char *my_revstr(char *str);

bool is_slash(char *str);
void print_arg(char **arg);
int array_size(char **array);
void clean_str(char *str);
char **array_cpy(char **environ);

int make_echo(info_t *line, envp_info_t *info);
int change_directory(char *line, envp_info_t *envp, info_t *line_t);

char *make_tab_redi(char ***array, info_t *line, envp_info_t *i);

void free_array(char **array);
char *find_path(path_t *list, char *function);
void modify_node(path_t *list, char *value, int pos);
int modify_envp(path_t **list, char *value, char *name);
int search_list(path_t *list, char *value);
char *find_in_envp(path_t *envp_list, char *to_find, int size);

int shell_input(info_t *line, envp_info_t *envp, int status);

int exit_function(char *str, envp_info_t *info);
char *reduce_path(char *line);
int is_reg_file(char *filepath, char *function);
int my_exec(char *filepath, char **argu, char **envp, char *filename);


int my_build_in(info_t *line, envp_info_t *info);

char *shell_function(char *str);

int segfault_handling(int status);
void access_to_file(char *filename);

bool make_pipe(char *line, envp_info_t *info);
bool check_commands(char ***cmd);

void modify_redis(redirection_t **redi);
redirection_t *list_redirection(char **array);
void redirect_write(char *filename, int status);
char **redirection_t_array(redirection_t *redi);
bool is_good_redi(redirection_t *redi);

int is_injection(char *str);
int is_redirection(char *str);

bool is_pipe(char *str);

char *redi_to_extract(char **fct);
bool make_good_tab(char ***fct);
bool there_rediction(char *str);
bool there_injection(char *str);


void parse_redirection(redirection_t **redi, redirection_t *other);
void add_redi(redirection_t **list, char *str);
/* HANDLING ERROR OF REDIRECTION */
bool handle_null_redi(char **array, envp_info_t *info);
bool is_ambiguous_redirect(char **cmd);
bool is_ambiguous_injection(char ***cmd, int i);

bool handle_injection(char **array_fct);

int handle_usr_injection(info_t *line, char ***array, envp_info_t *info);

bool is_buildin(char *str);
bool is_semicolon(char *str);
int handle_echo(info_t *line, envp_info_t *info);
void wait_my_pid(char ***cmd, int index, int pid, int *status);

bool handle_null_command(void);
bool execute_pipe_last_buildin(char ***cmd, envp_info_t *info);
void execute_semicolon_pipe(info_t *line, envp_info_t *envp, int status);

/* history command */
int execute_exclamation(info_t *line, envp_info_t *info);
int history_command(info_t *line, envp_info_t *info);
char *search_nb_in_history(char *data, char *search, envp_info_t *info);
char *search_last_cmd_in_history(char *data, info_t *line, envp_info_t *info);
int history_with_argument(char **line_array, char *file_data, int nb_lines_f,
    envp_info_t *info);
int execute_history(char *line, envp_info_t *info);
int check_error_line(char const *src, envp_info_t *info);
int history_error(char *line, envp_info_t *info);
void add_history(char *tmp, envp_info_t *envp);
char *get_data_file(envp_info_t *envp);
char *format_line_history(char *str, envp_info_t *envp);
char *concat_history(char **tab_elem_line, char *str, envp_info_t *envp);
int found_cmd(int fd, char **tab_elem_line, envp_info_t *info);
char *search_cmd_in_history(char *data, char *search, envp_info_t *info);
int element_found(char *cmd_line_history, char **tab_elem_line,
    envp_info_t *info);
int delete_line_f(char *str, int fd, envp_info_t *info);
int open_history_write(envp_info_t *envp);
int open_history_read(envp_info_t *envp, char **path);
char *search_history_data(envp_info_t *envp);

int execute_my_program(info_t *line_getted, envp_info_t *info);
/* WHICH FUNCTIONNALITY */
bool handle_which(char *line, envp_info_t *info);
int execute_alias_which(char *line_getted, envp_info_t *info);

/* WHERE FUNCTIONNALITY */
bool handle_where(envp_info_t *info, char *str);

void replace_strings(char *str, char *cramptes, char *space);
int user_shell_fonction(info_t *line, envp_info_t *info);
int exec_cwdcmd(info_t *line, envp_info_t *info);
