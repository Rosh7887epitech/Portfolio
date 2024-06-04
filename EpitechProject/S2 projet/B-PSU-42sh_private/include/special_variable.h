/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** special_variable
*/

#pragma once

#include "my_project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int ignoreeof_function(envp_info_t *info);
int set_special_variables(envp_info_t *envp);
bool there_alias_searched(alias_t *tmp, char *search);
int exec_precmd(info_t *line, envp_info_t *info);
