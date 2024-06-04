/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** displays the number given as a parameter.
*/
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_put_nbr_two(int n)
{
    int i = 1;
    while ((n / i) >= 10)
        i = i * 10;
    while (i > 0) {
        my_putchar((n / i) % 10 + '0');
        i /= 10;
    }   
}

void my_put_nbr(int n)
{
    if (n <= (-2147483648 || 2147483648))
        return;
    else
    {
        if (n < 0)
        {
            my_putchar('-');
            n = n * -1;
        }
        my_put_nbr_two(n);
    }
}
