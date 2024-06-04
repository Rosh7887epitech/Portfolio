/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** main
*/

#include "rpg.h"
#include "my.h"
#include "my_json.h"
#include "item.h"

int main(int ac, char **av)
{
    int ret = 0;

    ret = my_rpg(ac, av[1]);
    return ret;
}
