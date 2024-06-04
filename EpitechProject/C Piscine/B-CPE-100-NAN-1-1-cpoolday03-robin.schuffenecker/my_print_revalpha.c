/*
** EPITECH PROJECT, 2023
** my_print_revalpha
** File description:
** displays the lowercase alphabet in reverse order
*/

int my_print_revalpha(void)
{
    int	letter = 122;

    while (letter != 96) {
        my_putchar(letter);
        letter = letter - 1;
    }
    my_putchar('\n');
}
