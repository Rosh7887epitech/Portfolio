/*
** EPITECH PROJECT, 2023
** rush3
** File description:
** rush final stumper
*/

#include <unistd.h>

int rush3(int x, int y)
{
    char tab[x][y];
    int res = x * y;
    int i = 0;
    int compt = 0;

    for (tab[i]; tab[i] != '\0'; i++) {
        compt++;        
    }
    my_put_nbr(compt);
    return (compt);
}
