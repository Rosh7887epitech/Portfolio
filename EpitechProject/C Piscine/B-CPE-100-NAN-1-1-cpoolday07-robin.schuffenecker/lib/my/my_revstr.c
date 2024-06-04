/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** Write a function that reverses a string.
*/

void my_swap(char *str, int size, int first)
{
    int a = str[size];

    str[size] = str[first];
    str[first] = a;
}

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        i = i + 1;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int first = 0;
    int size = my_strlen2(str);
    int div = size / 2;

    while ( size != div){
        size = size - 1;
        my_swap(str, size, first);
        first = first +1;
    }
    return (str);
}
