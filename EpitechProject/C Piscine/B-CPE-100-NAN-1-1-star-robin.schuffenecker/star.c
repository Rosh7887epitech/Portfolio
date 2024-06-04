/*
** EPITECH PROJECT, 2023
** star
** File description:
** Write a function that displays a star, based on its given size.
*/

static int putchar_repeted(int nb, char c)
{
    for (int i = 0; i < nb; i++)
        my_putchar(c);
}

static int slash(int size, int i)
{
    putchar_repeted(i, ' ');
    my_putstr("*");
    putchar_repeted((6 * size ) - (2 * i) - 3, ' ');
    my_putstr("*\n");
}

int pyramid(int size)
{
    putchar_repeted((3 * size) - 1, ' ');
    my_putstr("*\n");
    for ( int i = 1; i < size; i++) {
        putchar_repeted((3 * size) - i - 1, ' ');
        my_putstr("*");
        putchar_repeted((i * 2) - 1, ' ');
        my_putstr("*\n");
    }
}

int rev_pyramid(int size)
{
    for (int i = size - 1; i > 0; i--) {
        putchar_repeted((3 * size) - i - 1, ' ');
        my_putstr("*");
        putchar_repeted((i * 2) - 1, ' ');
        my_putstr("*\n");
    }
    putchar_repeted((3 * size) - 1, ' ');
    my_putstr("*\n");
}

int middle_stick(int size)
{
    for (int i = 1; i <= size; i++)
        slash(size, i);
    for (int i = size - 1; i > 0; i--)
        slash(size, i);
}

int line(int size)
{
    putchar_repeted((2 * size) + 1, '*');
    putchar_repeted((2 * size) - 3, ' ');
    putchar_repeted((2 * size) + 1, '*');
    my_putstr("\n");
}

void star(unsigned int size)
{
    if (size == 0)
        return;
    if (size == 1) {
        mini_star();
        return;
    }
    pyramid(size);
    line(size);
    middle_stick(size);
    line(size);
    rev_pyramid(size);
}
