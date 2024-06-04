/*
** EPITECH PROJECT, 2023
** rush-1-1
** File description:
** rush-1-1
*/

int stick(int x, int y)
{
    my_putchar('o');
    my_putchar('\n');
    for (int i = 0; i < y - 2; i++) {
        my_putchar('|');
        my_putchar('\n');
    }
    my_putchar('o');
    my_putchar('\n');
}

static int top(int x, int y)
{
    my_putchar('o');
    for (int i = 0; i < x - 2; i++)
        my_putchar('-');
    my_putchar('o');
    my_putchar('\n');
}

static int bottom(int x, int y)
{
    if (y != 1) {
        my_putchar('o');
        for (int i = 0; i < x - 2; i++)
            my_putchar('-');
        my_putchar('o');
        my_putchar('\n');
    }
}

static int side(int x, int y)
{
    for (int i = 0; i < y - 2; i++) {
        my_putchar('|');
        for (int j = 0; j < x - 2; j++) {
            my_putchar(' ');
        }
        my_putchar('|');
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if (x < 1 || x > 2147483647 || y < 1 || y > 2147483647) {
        write(2, "Invalid size\n", 13);
        return;
    }
    if (x == 1 && y == 1) {
        my_putchar('o');
        return my_putchar('\n');
    }
    if (x == 1) {
        stick(x, y);
        return;
    }
    top(x, y);
    side(x, y);
    bottom(x, y);
}
