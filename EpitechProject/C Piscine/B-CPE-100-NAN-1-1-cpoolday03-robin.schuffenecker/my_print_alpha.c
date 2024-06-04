/*
** EPITECH PROJECT, 2023
** my_print_alpha
** File description:
** displays the lowercase alphabet
*/

int my_print_alpha(void)
{
    int letter = 97;

    while (letter != 123) {
        my_putchar(letter);
        letter = letter + 1;
    }
    my_putchar('\n');
}
