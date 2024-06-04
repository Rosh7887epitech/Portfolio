/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** take a str as parameters and return an int
*/

static int count_number(char const *str)
{
    int index_nb = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if ((str[index] >= '0') && (str[index] <= '9')) {
            index_nb++;
        }
    }
    if (index_nb > 10) {
        return 1;
    } else {
        return 0;
    }
}

static int is_nbr(char a)
{
    if ((a >= '0') && (a <= '9')) {
        return 1;
    } else {
        return 0;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = count_number(str);
    int neg = 0;

    if (result == 1)
        return 0;
    while (is_nbr(str[i]) != 1) {
        if ((str[i] == '-') && (is_nbr(str[i + 1]) == 1)) {
            neg = -1;
        }
        i++;
    }
    while (is_nbr(str[i]) == 1) {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    if (neg == -1)
        result = result * neg;
    return result;
}
