/*
** EPITECH PROJECT, 2023
** my_print_comb2
** File description:
** displays, in ascending order, all the different
** combinations of two two-digit numbers
*/

void comma2(int first, int second, int third, int four)
{
    if (first == 9 && second == 8 && third == 9 && four == 9) {
    } else {
    my_putchar(',');
    my_putchar(' ');
    }
}

void display(int first, int second, int third, int four)
{
    if (first * 10 + second < third * 10 + four) {
        my_putchar(48 + first);
        my_putchar(48 + second);
        my_putchar(' ');
        my_putchar(48 + third);
        my_putchar(48 + four);
        comma2(first, second, third, four);
    }
}

int integration2(int first, int second)
{
    for (int third = 0; third < 10; ++third) {
        for (int four = 0; four < 10; ++four) {
            display(first, second, third, four);
        }
    }
}

int my_print_comb2(void)
{
    for (int first = 0; first < 10; ++first) {
        for (int second = 0; second < 10; ++second) {
            integration2(first, second);
        }
    }
    my_putchar('\n');
}
