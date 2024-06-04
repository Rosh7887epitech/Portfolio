/*
** EPITECH PROJECT, 2023
** my_rev_params
** File description:
** Write a program that displays all the arguments
** received on the command line in reverse order.
*/

int main(int argc, char *argv[])
{
    int i = argc - 1;

    while (i > 0) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i = i - 1;
    }
    return (0);
}
