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

typedef struct list_t {
    int data;
    struct list_t *next;
} list;

int del_list(void* l, int pos);
int add_list(void *l, int data);
int is_empty(list *l);
int put_list(void *l);
int len_list(list *l);
list *my_rev_list(list **first);
#endif /* !ls */
