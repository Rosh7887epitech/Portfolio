/*
** EPITECH PROJECT, 2023
** rush-1-3
** File description:
** rush-1-3
*/

static void part1(int x, int y)
{
    my_putchar('A');
    for (int i = 0; i < x - 2; i++) {
        my_putchar('B');
    }
    my_putchar('A');
    my_putchar('\n');
}

static void part2(int x, int y)
{
    for (int i = 0; i < y - 2; i++) {
        my_putchar('B');
        for (int j = 0; j < x - 2; j++) {
            my_putchar(' ');
        }
        my_putchar('B');
        my_putchar('\n');
    }
}

static void part3(int x, int y)
{
    my_putchar('C');
    for (int i = 0; i < x - 2; i++) {
        my_putchar('B');
    }
    my_putchar('C');
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x < 1 || y < 1 || x > 2147483647 || y > 2147483647) {
        write(2, "Invalid size\n", 13);
        return;
    }
    if (x == 1) {
        for (int i = 0; i < y; i++) {
            my_putchar('B');
            my_putchar('\n');
        }
    } else if (y != 1) {
        part1(x, y);
        part2(x, y);
        part3(x, y);
    } else {
        for (int i = 0; i < x; i++) {
            my_putchar('B');
        }
        my_putchar('\n');
    }
}
