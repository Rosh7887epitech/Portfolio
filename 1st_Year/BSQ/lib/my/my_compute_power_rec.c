/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** Write an recursive function that returns the first
** argument raised to the power p, where p is the second
** argument
*/

int my_compute_power_rec(int nb, int p)
{
    if (nb == 0 || p < 0) {
        return (0);
        if (nb < 0)
            return (1);
    }
    if (p == 0)
        return (1);
    else
        return (nb * my_compute_power_rec(nb, p - 1));
}
