/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** N if negative and P if positive
*/

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
}
