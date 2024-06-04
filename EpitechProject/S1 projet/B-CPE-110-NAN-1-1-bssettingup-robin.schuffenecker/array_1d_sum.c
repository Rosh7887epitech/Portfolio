/*
** EPITECH PROJECT, 2023
** array_1d_sum
** File description:
** sum of int in array
*/

int array_1d_sum(int const *arr, int size)
{
    int array_nb = 0;

    for (int i = 0; i < size; i++) {
        array_nb += arr[i];
    }
    return array_nb;
}
