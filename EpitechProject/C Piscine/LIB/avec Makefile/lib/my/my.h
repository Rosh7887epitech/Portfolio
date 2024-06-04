/*
** EPITECH PROJECT, 2023
** my
** File description:
** my h
*/
#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>

void my_putchar(char c);
char *my_itoa(int score);
int my_isneg(int nb);
int my_strcmp(char *s1, char *s2);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
unsigned int convertion(long int nb, char *base);
unsigned int my_put_unsigned_nbr(unsigned int nb);
int put_c(const char *format, va_list args, int i);
int put_hexa(const char *format, va_list args, int i);
int put_i_d(const char *format, va_list args, int i);
int put_s(const char *format, va_list args, int i);
int put_u(const char *format, va_list args, int i);
int put_pourcent(const char *format, va_list args, int i);
int put_octal(const char *format, va_list args, int i);
int my_printf(const char *format, ...);
void *put_p(const char *format, va_list args, int i);
double my_put_float_nbr(double nb);
int put_f(const char *format, va_list args, int i);
int put_e(const char *format, va_list args, int i);
int my_count_nbr(int nb);
int put_hexa_upper(const char *format, va_list args, int i);
int hashtag(const char *format, va_list args, int i);

#endif
