/*
** EPITECH PROJECT, 2023
** ORG
** File description:
** ORG
*/

#pragma once

    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

typedef struct list_t {

    char *type;
    char *name;
    int id;
    struct list_t *next;

} list;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_itoa(int score, char str[]);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_strcmp(char *s1, char *s2);
int my_intcmp(int i1, int i2);
list *my_rev_list(list **first);
int sort_type(void *data, char **args);
int sort_type_rev(void *data, char **args);
int sort_name(void *data, char **args);
int sort_name_rev(void *data, char **args);
int sort_id(void *data, char **args);
int sort_id_rev(void *data, char **args);
int del_start(void *data);
