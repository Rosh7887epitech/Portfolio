/*
** EPITECH PROJECT, 2023
** my_print_comb
** File description:
** displays, in ascending order, all the numbers
** composed by three different digits numbers.
*/
void comma(int first, int second, int third)
{
    if (first * 100 + second * 10 + third != 789) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int integration(int first, int second)
{
    for (int third = 0; third < 10; ++third) {
        if (first < second && second < third) {
            my_putchar(48 + first);
            my_putchar(48 + second);
            my_putchar(48 + third);
            comma(first, second, third);
        }
    }
}

int my_print_comb(void)
{
    for (int first = 0; first < 10; ++first) {
        for (int second = 0; second < 10; ++second) {
            integration(first, second);
        }
    }
    my_putchar('\n');
}
