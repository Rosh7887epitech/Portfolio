/*
** EPITECH PROJECT, 2023
** main
** File description:
** star
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    star(5);
    return (0);
}
