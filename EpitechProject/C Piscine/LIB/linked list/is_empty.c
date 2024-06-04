/*
** EPITECH PROJECT, 2023
** empty
** File description:
** empty
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "include/ls.h"
#include <dirent.h>
#include <stdio.h>

int is_empty(list *l)
{
    return l == NULL;
}
