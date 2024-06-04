/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** copie of ls function
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

static int flag_l(list *list_c, stock_st *var)
{
    if (list_c->var_ucd->name[0] != '.' && var->flag[1] == '1') {
            my_printf("%i ", list_c->var_ucd->size);
            my_printf("%s", list_c->var_ucd->name);
            my_printf("\n");
        }
        return 0;
}

static int compt_arg(stock_st *var, struct stat *sb,
    infos_st *info, list *list_c)
{
    int k = 0;

    for (int i = 1; var->argv[i] != NULL; i++) {
        if (var->argv[i][0] != '-') {
            k++;
        }
    }
    if (k == 0) {
        var->path = ".";
        directory(var, sb, info, list_c);
        exit(0);
    }
}

static int display(list *list_c, stock_st *var)
{
    if (list_c->var_ucd->name[0] != '.' && var->flag[2] == '1') {
        my_rev_list(&list_c);
    }
    while (list_c) {
        if ((list_c->var_ucd->name[0] != '.' || var->flag[0] == '1')
            && var->flag[1] != '1') {
            my_printf("%s  ", list_c->var_ucd->name);
        }
        flag_l(list_c, var);
        list_c = list_c->next;
    }
}

static int put_file(struct stat *sb, list *list_c,
    stock_st *var, infos_st *info)
{
    info->name = var->input->d_name;
    info->size = sb->st_size;
}

static int between(struct stat *sb, stock_st *var,
    infos_st *info, list *list_c)
{
    if (S_ISDIR(sb->st_mode) != 0) {
        directory(var, sb, info, list_c);
    } else{
        filepath(var->path);
    }
}

int filepath(char const *argv)
{
    my_putstr(argv);
    my_putstr("\n");
}

static int error(DIR *directory)
{
    if (directory == NULL) {
        return 84;
    }
}

int directory(stock_st *var, struct stat *sb, infos_st *info, list *list_c)
{
    DIR *directory;
    struct stat file_stat;

    if (stat(var->path, &file_stat) < 0){
        return 84;
    } else {
    directory = opendir(var->path);
    var->input = readdir(directory);
    error(directory);
    while (var->input != NULL) {
        put_file(sb, list_c, var, info);
        list_c = add_list(list_c, info, 0);
        var->input = readdir(directory);
    }
    display(list_c, var);
    my_printf("\n");
    closedir(directory);
    }
    return 0;
}

int my_ls(int argc, char const **argv, char *flag)
{
    int i = 1;
    struct stat sb;
    stock_st var;
    infos_st *info = malloc(sizeof(infos_st));
    list *list_c = NULL;

    var.argc = argc;
    var.argv = argv;
    var.flag = flag;
    compt_arg(&var, &sb, info, list_c);
    for (; var.argv[i] != NULL; i++) {
        if (var.argv[i][0] != '-') {
            var.path = var.argv[i];
            stat(var.path, &sb);
            between(&sb, &var, info, list_c);
        }
    }
}
