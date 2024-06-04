/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap the content of two integer,
** whos adresses are given as a parameter
*/

void my_swap(int *a, int *b)
{
    int variable = *a;

    *a = *b;
    *b = variable;
}
