/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Write a function that returns the smallest prime number
** that is greater than, or equal to, the number given
** as a parameter.
*/

int my_find_prime_sup(int nb)
{
    for (int i = 0; 
    if (nb < 2)
        return 0;
    for (int i = 2; nb / i >= 2; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
