/*
** EPITECH PROJECT, 2023
** B-CPE-100-NAN-1-1-cpoolday08-mael.perrigaud
** File description:
** my_macro_abs.h
*/

#pragma once

#include <stdbool.h>

int my_power(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(long long int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *concat_params(int argc, char **argv);
char *my_strdup(char const *src);
int my_show_word_array(char *const *tab);
int my_printf(const char *format, ...);
int how_many_args(char **args);
bool str_is_in_tab(char *str, const char *const *tab);
bool is_number(char const c);
bool my_isalpha(char c);
int my_putnbr_base(int nbr, char const *base);
bool is_in_str(char c, const char *list);
char *my_strdupmdelim(char const *src, char const *delim);
char *my_strndup(char const *src, int n);
char **my_str_to_word_array(char const *str, char *delim);
int nb_words(char const *str, char const *delim);
int my_atoi(char *str, int base);
long long int my_atol(char *str, int base);
bool check_is_prime(int nb);
long my_atol_with_verif(char const *str);
bool check_sign(char const *str);
bool my_is_alphanum(char c);
bool my_is_lower(char c);
char *my_itoa(long long int nb);
int my_tablen(char **tab);
char *file_in_buffer(char *file);
