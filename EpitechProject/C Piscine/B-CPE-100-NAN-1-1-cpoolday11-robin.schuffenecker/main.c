/*
** EPITECH PROJECT, 2023
** main
** File description:
** main d11
*/

#include <stdlib.h>
#include "include/list.h"
#include "include/my.h"

linked_list_t *my_params_to_list(int ac, char *const *av);

int main(int ac, char **av)
{
        
    linked_list_t *list = my_params_to_list(ac, av);
    while (list != NULL)
    {
        my_putstr((char *)list ->data);
        list = list ->next;
    }
    return (0);
}
