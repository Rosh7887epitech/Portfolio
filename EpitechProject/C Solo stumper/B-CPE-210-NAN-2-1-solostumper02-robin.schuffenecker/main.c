/*
** EPITECH PROJECT, 2024
** main
** File description:
** main solo stumper
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_is_alpha(char *str, int len)
{
    for (int i = 0; i < len; i++) {
        if (str[i] <= 47 || str[i] >= 58)
            return 84;
    }
    return 0;
}

int disp_int(int nb_one, int nb_two)
{
    int len = 0;
    int index = nb_one;

    len = (nb_two - nb_one) + 1;
    for (int i = 0; i < len; i++) {
        if ((index % 10) == 0 && (index % 9 == 0))
            printf("FazzBizz\n");
        if ((index % 10) == 0 && (index % 9) != 0)
            printf("Fazz\n");
        if ((index % 9) == 0 && (index % 10) != 0)
            printf("Bizz\n");
        if ((index % 9) > 0 && (index % 10) > 0)
            printf("%d\n", index);
        index++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int nb_one = 0;
    int nb_two = 0;

    if (argc == 1 || argv[1] == NULL || argv[2] == NULL || argc >= 4)
        return 84;
    if (my_is_alpha(argv[1], my_strlen(argv[1])) == 84)
        return 84;
    if (my_is_alpha(argv[2], my_strlen(argv[2])) == 84)
        return 84;
    nb_one = atoi(argv[1]);
    nb_two = atoi(argv[2]);
    if (nb_one > nb_two) {
        write(2, "Error: the second parameter", 27);
        write(2, " must be greater than the first one.\n", 37);
        return 84;
    }
    disp_int(nb_one, nb_two);
    return 0;
}
