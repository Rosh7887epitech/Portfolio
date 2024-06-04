/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** command
*/

#pragma once

    #include "my.h"
    #include "cd.h"
    #include "env.h"

char *cond_clean(char *str);
char *clean_line(char *str);
int is_red(char *com);
char *pars_file(char *sep, char *line);
char **pars_com(base_t *var, char *sep, char *file, char *line);
int pipe_err(char *line);
int d_left(base_t *var, char *line, int w);
char **search_pipe(base_t *var, char **com);
int my_re_command(int status);
char *end_clean(char *dest, int j);
int cond_launch(base_t *var, char *line);
int redirection(base_t *var, char *line);
char *search_dir(base_t *var, int i);
char *my_prog(base_t *var, char *filepath);
int my_put_command(base_t *var, char *line);
int launch_command(base_t *var, char *line);
int exec_error(base_t *var, char *line);
int pipe_exec(base_t *var, char *line);
int sep_exec(base_t *var, char *line);
char *search_command(base_t *var, char *line);
int my_env_command(base_t *var, char *line, char **name);
int exec_command(base_t *var, char *line, char *filepath);
