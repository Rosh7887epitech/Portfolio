/*
** EPITECH PROJECT, 2023
** disp_stdarg
** File description:
** display all of its argument except the first one
*/

#include <stdarg.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int n);
void my_putchar(char c);

void disp_stdarg(char *s, ...)
{
    va_list args;
    int lenght = my_strlen(s);
    
    va_start(args, s);
    for(int i = 0; i < lenght; i++) {
        if(s[i] == 'c')
            my_putchar(va_arg(args, int));
        if(s[i] == 's')
            my_putstr(va_arg(args, char *));
        if(s[i] == 'i')
            my_put_nbr(va_arg(args, int));
        my_putchar('\n');
    }
    va_end(args);
}
