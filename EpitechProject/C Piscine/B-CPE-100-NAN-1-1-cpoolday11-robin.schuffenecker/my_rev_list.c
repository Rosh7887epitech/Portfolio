/*
** EPITECH PROJECT, 2023
** my_rev_list
** File description:
** rev list
*/

#include <stdlib.h>
#include "include/list.h"
#include "include/my.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    int i = 0;
    linked_list_t *list;

    while (i < ac)
    {
        linked_list_t *lnext;
        lnext = malloc(sizeof(*lnext));
        lnext ->data = av[i];
        lnext ->next = list;
        list = lnext;
        i++;
    }
    return (list);
}

