/*
** EPITECH PROJECT, 2023
** my_compute_power_it
** File description:
** Write an iterative function that returns the first
** argument raised to the power p, where p is the second
** argument.
*/
int my_compute_power_it(int nb, int p)
{
    int res = nb;

    if ( p == 0 )
        return (1);
    if ( p < 0 )
        return (0);
    while ( p > 1) {
        res = nb * res;
        p = p - 1;        
    }
    return (res);
}

