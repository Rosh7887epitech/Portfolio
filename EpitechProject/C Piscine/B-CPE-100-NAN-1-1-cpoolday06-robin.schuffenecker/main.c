/*
** EPITECH PROJECT, 2023
** main
** File description:
** day 06 str
*/

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;
 
    while (str[i] != '\0' ) {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int main(void)
{
    char dest[] = "hel";

    my_strncpy(dest, "rush", 4);
    my_putstr(dest);
    return (0);
}
