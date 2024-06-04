/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** jobs
*/

#pragma once

#include "my_project.h"
#include <stdio.h>

int execute_jobs_control(info_t *line, envp_info_t *envp);
int search_prog(info_t *line, envp_info_t *envp);
int have_param(info_t *line, envp_info_t *envp);
int error_jobs(envp_info_t *envp, int index);
int error_param(envp_info_t *envp, int pos);
void remove_tab(envp_info_t *envp, int size);
int count_size(int *tab);
int count_str(char **tab);
int count_nb_jobs(info_t *line);
void final_line(info_t *line);
int first_pos_esperluette(info_t *line, envp_info_t *envp);
char *search_path_jobs(info_t *line, envp_info_t *envp, char *com);
