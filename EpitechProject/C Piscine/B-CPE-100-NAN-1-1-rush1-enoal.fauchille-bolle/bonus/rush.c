/*
** EPITECH PROJECT, 2023
** rush_generic
** File description:
** rush_generic
*/

static void part1(int x, int y, char *chars)
{
    my_putchar(chars[0]);
    for (int i = 0; i < x - 2; i++) {
        my_putchar(chars[4]);
    }
    my_putchar(chars[1]);
    my_putchar('\n');
}

static void part2(int x, int y, char *chars)
{
    for (int i = 0; i < y - 2; i++) {
        my_putchar(chars[5]);
        for (int j = 0; j < x - 2; j++) {
            my_putchar(' ');
        }
        my_putchar(chars[6]);
        my_putchar('\n');
    }
}

static void part3(int x, int y, char *chars)
{
    my_putchar(chars[2]);
    for (int i = 0; i < x - 2; i++) {
        my_putchar(chars[7]);
    }
    my_putchar(chars[3]);
    my_putchar('\n');
}

static void x_case(int x, int y, int angle, char *chars)
{
    if (angle) {
        my_putchar(chars[0]);
        my_putchar('\n');
        for (int i = 0; i < y - 2; i++) {
            my_putchar(chars[5]);
            my_putchar('\n');
        }
        my_putchar(chars[2]);
        my_putchar('\n');
    } else {
        for (int i = 0; i < y; i++) {
            my_putchar(chars[5]);
            my_putchar('\n');
        }
    }
}

static void y_case(int x, int y, int angle, char *chars)
{
    if (angle) {
        my_putchar(chars[0]);
        for (int i = 0; i < x - 2; i++) {
            my_putchar(chars[4]);
        }
        my_putchar(chars[1]);
        my_putchar('\n');
    } else {
        for (int i = 0; i < x; i++) {
            my_putchar(chars[4]);
        }
        my_putchar('\n');
    }
}

void rush_generic(int x, int y, int angle, char *chars)
{
    if (x < 1 || y < 1 || x > 2147483647 || y > 2147483647) {
        write(2, "Invalid size\n", 13);
        return;
    }
    if (x == 1) {
        x_case(x, y, angle, chars);
    } else if (y != 1) {
        part1(x, y, chars);
        part2(x, y, chars);
        part3(x, y, chars);
    } else {
        y_case(x, y, angle, chars);
    }
}
