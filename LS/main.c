/*
** EPITECH PROJECT, 2023
** main
** File description:
** main for my_ls
*/

#include "include/ls.h"
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static void put_flag(char const **argv, char *flag, int i)
{
    for (int j = 1; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'a') {
            flag[0] = '1';
        }
        if (argv[i][j] == 'l') {
            flag[1] = '1';
        }
        if (argv[i][j] == 'r') {
            flag[2] = '1';
        }
    }
}

static void search_flag(int argc, char const **argv, char *flag)
{
    int i;

    for (i = 0; argv[i] != NULL; i++) {
        if (argv[i][0] == '-') {
            put_flag(argv, flag, i);
        }
    }
}

int main(int argc, char const **argv)
{
    char *flag = malloc(sizeof(char)* 6);

    search_flag(argc, argv, flag);
    my_ls(argc, argv, flag);
    return 0;
}
