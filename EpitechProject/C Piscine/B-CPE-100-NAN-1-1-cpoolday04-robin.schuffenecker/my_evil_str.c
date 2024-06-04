/*
** EPITECH PROJECT, 2023
** my_evil_str
** File description:
** swap each of the string’s characters, two by two.
*/
void my_swap2(char *str, int size, int first)
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

char *my_evil_str(char *str)
{
    int first = 0;
    int size = my_strlen2(str);
    int div = size / 2;

    while ( size != div){
        size = size - 1;
        my_swap2(str, size, first);
        first = first +1;
    }
    return (str);
}
