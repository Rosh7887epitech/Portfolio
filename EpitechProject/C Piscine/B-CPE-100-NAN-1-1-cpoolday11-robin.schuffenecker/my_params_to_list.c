/*
** EPITECH PROJECT, 2023
** my_params_to_list
** File description:
** that creates a new list from the command line arguments.
*/

#include <stdlib.h>
#include "include/list.h"
#include "include/my.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    int i = 0;
    linked_list_t *list;
    linked_list_t *lnext;

    while (i < ac) {
        lnext = malloc(sizeof(*lnext));
        lnext ->data = av[i];
        lnext ->next = list;
        list = lnext;
        i++;
    }
    return (list);
}
