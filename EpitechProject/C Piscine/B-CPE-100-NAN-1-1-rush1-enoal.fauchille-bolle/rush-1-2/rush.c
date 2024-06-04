/*
** EPITECH PROJECT, 2023
** rush-1-2
** File description:
** rush-1-2
*/

static void part1(int x, int y)
{
    my_putchar('/');
    for (int i = 0; i < x - 2; i++) {
        my_putchar('*');
    }
    my_putchar('\\');
    my_putchar('\n');
}

static void part2(int x, int y)
{
    for (int i = 0; i < y - 2; i++) {
        my_putchar('*');
        for (int j = 0; j < x - 2; j++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
    }
}

static void part3(int x, int y)
{
    my_putchar('\\');
    for (int i = 0; i < x - 2; i++) {
        my_putchar('*');
    }
    my_putchar('/');
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x < 1 || y < 1 || x > 2147483647 || y > 2147483647) {
        return write(2, "Invalid size\n", 13);
    }
    if (x == 1) {
        for (int i = 0; i < y; i++) {
            my_putchar('*');
            my_putchar('\n');
        }
        return;
    }
    if (y == 1) {
        for (int i = 0; i < x; i++) {
            my_putchar('*');
        }
        my_putchar('\n');
    } else {
        part1(x, y);
        part2(x, y);
        part3(x, y);
    }
}
