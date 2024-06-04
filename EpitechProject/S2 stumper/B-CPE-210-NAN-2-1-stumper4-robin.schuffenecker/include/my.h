/*
** EPITECH PROJECT, 2024
** B-CPE-210-NAN-2-1-stumper4-robin.schuffenecker
** File description:
** my
*/

#pragma once

int my_strncmp(char *s1, char *s2, int n);
int my_strcmp(char *s1, char *s2);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char *src);
char **my_str_to_word_array(char *str, char sep);
int my_str_isalphanum(char *str);
int my_getnbr(char const *str);
int flag_n(char **file, int nb_line);
int nb_of_char(char *str, char c);
char **tail(char *name_file);
int normal_tail(char **file);
int tail_c(char *name_file, int nb_byte);
void my_putchar(char c);
