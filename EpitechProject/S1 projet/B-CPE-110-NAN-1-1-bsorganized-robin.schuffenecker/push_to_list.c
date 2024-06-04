/*
** EPITECH PROJECT, 2023
** push into list
** File description:
** push
*/

#include "include/bootstrap.h"
#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    node->data = data;
    node->next = *begin;
    *begin = node;
}