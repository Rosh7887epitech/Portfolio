/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** displays the number given as a parameter.
*/

int my_put_nbr(int n)
{
    int boleen = 8;
    int value = 0;

    if (n == 0) {
        my_putchar('0');
    }
    if ( n < 0 ) {
        n = n * -1;
        my_putchar('-');
    }
    for (int s = 1000000000; s >= 1;
s = s / 10) {
        value = n / s;
        n = n % s;
        if (boleen == 8 && value != 0) {
            boleen = 9;
            my_putchar( value + '0');
        } else if ( boleen == 9 ) {
            my_putchar( value + '0');
        }
    }
}
