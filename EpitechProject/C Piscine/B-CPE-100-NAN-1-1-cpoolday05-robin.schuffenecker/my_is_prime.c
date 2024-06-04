/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Write a function that returns 1
** if the number is prime and 0 if not.
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    for (int i = 2; nb / i >= 2; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
