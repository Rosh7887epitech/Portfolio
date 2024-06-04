/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#include "include/bootstrap.h"
#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void display_list(linked_list_t *begin, void(*disp_fct)(void *))
{
    while (begin != NULL) {
        disp_fct(begin);
        begin = begin->next;
    }
}
