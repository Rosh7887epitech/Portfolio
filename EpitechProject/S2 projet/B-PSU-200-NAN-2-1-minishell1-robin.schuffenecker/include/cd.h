/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** cd
*/

#pragma once

    #include "my.h"
    #include "env.h"
    #include "command.h"

int old_cd(base_t *var);
int cond_exit(char *line);
int normal_cd(base_t *var, char *line);
int cd_command(base_t *var, char *line);
int complet_cd(base_t *var, char *line);
int cd_error(base_t *var, char **where, struct stat *sb);
