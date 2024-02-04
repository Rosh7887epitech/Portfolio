/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** SECURED
*/

#pragma once

#include <fcntl.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct secured_s {
    char *key;
    char *value;
    struct secured_s *next;
} secured_t;

char *my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strdup(char *src);
int main(void);
secured_t *create_node(char *key, char *value);
char *my_itoa(int score);
int my_strcmp(char *s1, char *s2);
