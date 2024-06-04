/*
** EPITECH PROJECT, 2023
** error
** File description:
** error
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/ls.h"
#include "include/my.h"
#include <dirent.h>

int error_file(stock_st *var)
{
    for (int l = 1; var->argv[l] != NULL; l++) {
        if (var->argc >= 3 && var->argv[l][0] != '-') {
            my_printf("%s:\n", var->path);
        }
    }
}
