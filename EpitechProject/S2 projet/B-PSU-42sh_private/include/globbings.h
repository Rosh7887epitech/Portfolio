/*
** EPITECH PROJECT, 2024
** globbings.h
** File description:
** that file should include all things for globbings
*/

#pragma once

#include "my_project.h"
#include <stdio.h>
#include <glob.h>

int execute_globbings(info_t *line, envp_info_t *info);
char *str_cat_at_pos(char *dest, char *src, int pos);
