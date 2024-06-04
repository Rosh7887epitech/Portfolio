/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/
#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
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
#endif /* MY_H_ */
