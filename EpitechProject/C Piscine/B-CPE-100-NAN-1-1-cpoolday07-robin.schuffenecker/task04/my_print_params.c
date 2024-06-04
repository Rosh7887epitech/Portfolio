/*
** EPITECH PROJECT, 2023
** main
** File description:
** main day 07
*/

main(int argc, char *argv[])
{
    int i = 0;

    while (i < argc) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i = i +1;
    }
    return (0);
}
