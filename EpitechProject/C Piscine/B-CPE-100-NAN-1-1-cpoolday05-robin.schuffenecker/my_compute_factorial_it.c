/*
** EPITECH PROJECT, 2023
** my_compute_factorial_it
** File description:
** Write an iterative function that returns
** the factorial of the number given as a parameter.
*/

int my_compute_factorial_it(int nb)
{
    int fact = 1;
    int i = 1;

    if ( nb > 12 || nb < 0) {
        return (0);
    }
    while (i <= nb) {
        fact = fact * i;
        i = i + 1;
    }
    return (fact);
}
