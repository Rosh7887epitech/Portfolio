/*
** Epitech
** Solo stumper
** main
** U 65/90  k 97/122
 */

#include <stddef.h>
#include <unistd.h>

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}

char *lower_case(char *test)
{
    for (int i = 0; test[i] != '\0'; i++) {
        if (test[i] >= 65 && test[i] <= 90)
            test[i] += 32;
    }
    return test;
}

char *loop_size(char *test)
{
    for (int i = 0; test[i] != '\0'; i += 2) {
        if (test[i] >= 65 && test[i] <= 90) {
            test[i] += 32;
        }
        if (test[i] >= 97 && test[i] <= 122) {
            test[i] -= 32;
        }
    }
    return test;
}

char *loop_change(char *test)
{
    for (int i = 0; test[i] != '\0'; i++) {
        if (test[i] == 'o')
            test[i] = '0';
        if (test[i] == 'i')
            test[i] = '1';
        if (test[i] == 'u')
            test[i] = '2';
        if (test[i] == 'e')
            test[i] = '3';
        if (test[i] == 'a')
            test[i] = '4';
        if (test[i] == 'y')
            test[i] = '5';
    }
    return test;
}

int main(int argc, char **argv)
{
    char *test = argv[1];

    if (argc <= 1 || argv[1] == NULL || argc >= 3)
        return 84;
    test = lower_case(test);
    test = loop_change(test);
    test = loop_size(test);
    my_putstr(test);
    my_putstr("\n");
    return 0;
}
