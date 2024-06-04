/*
** EPITECH PROJECT, 2023
** my
** File description:
** my h
*/

#pragma once

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include <stdio.h>

int my_put_nbr(int nb);
char **my_str_to_word_array(char *str);
void my_putchar(char c);
char *my_itoa(int score);
char *my_strdup(char *src);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char *src, int n);
void child_prog(int status);
void print_arg(char **arg);
char **disp_info(int argc, char **argv, char **arg, pid_t pid);
