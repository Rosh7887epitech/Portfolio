/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** function that returns a number, sent to the function as a string.
*/

int my_getnbr(char const *str)
{
    int n = str;

    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
        return (n);
    }
}
