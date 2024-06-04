/*
** EPITECH PROJECT, 2023
** main 05
** File description:
** 
*/
int my_putchar(char c)
{
    write(1, &c, 1);
}

int main()
{
    int res;
    
    res = my_compute_square_root(64);
    my_put_nbr(res);
    return (0);
}
