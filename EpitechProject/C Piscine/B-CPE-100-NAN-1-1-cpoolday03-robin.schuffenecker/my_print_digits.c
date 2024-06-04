/*
** EPITECH PROJECT, 2023
** my_print_digits
** File description:
** displays all digits in ascending order
*/

int my_print_digits(void)
{
    int digits = 48;

    while (digits != 58) {
        my_putchar(digits);
        digits = digits + 1;
    }
    my_putchar('\n');
}
