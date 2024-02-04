/*
** EPITECH PROJECT, 2023
** ls
** File description:
** ls
*/

#ifndef LS_H_
    #define LS_H_
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <dirent.h>

typedef struct stock{
    int argc;
    char const **argv;
    char *flag;
    char const *path;
    char const *argvt;
    struct dirent *input;
}stock_st;

typedef struct infos {
    char *chmod;
    int under_dir;
    char *auteur;
    char *name;
    int size;
}infos_st;

typedef struct list_t {
    infos_st *var_ucd;
    struct list_t *next;
} list;


int my_ls(int argc, char const **argv, char *flag);
int put_a(struct dirent *input, DIR *directory, char const *path);
int put_l(struct dirent *input, DIR *directory, struct stock *var);
int directory(stock_st *var, struct stat *sb, infos_st *info, list *list_c);
int filepath(char const *argv);
list *add_list(list *l, infos_st *p, int pos);
int is_empty(list *l);
void put_list(list *l);
infos_st get_elem_of_list(list *l, int pos);
int len_list(list *l);
list *my_rev_list(list **first);
int error_file(stock_st *var);
int error_backslash(stock_st *var);
#endif /* !ls */
