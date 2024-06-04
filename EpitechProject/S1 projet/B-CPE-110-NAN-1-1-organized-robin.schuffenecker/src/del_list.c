/*
** EPITECH PROJECT, 2023
** put list
** File description:
** put list for linked list
*/

#include "../include/org.h"
#include "../shell/shell.h"

static void display(list *current)
{
    write(1, current->type, my_strlen(current->type));
    write(1, " n°", 4);
    my_put_nbr(current->id);
    write(1, " - ", 4);
    my_putchar('"');
    write(1, current->name, my_strlen(current->name));
    my_putchar('"');
    write(1, " deleted.\n", 11);
}

int del_start(void *data)
{
    display(*(list **)data);
    *(list **)data = (*(list **)data)->next;
    return 0;
}

int cond_k(list *current, list *previous, int k)
{
    if (current->id == k) {
        display(current);
        previous->next = current->next;
        free(current);
        return 0;
    }
}

int del_loop(list *current, list *previous, int k)
{
    while (current->id != k || current != NULL) {
        previous = current;
        current = current->next;
        if (current == NULL)
            return 84;
        if (current->id == k) {
            display(current);
            previous->next = current->next;
            free(current);
            return 0;
        }
    }
}

int del(void *data, char **args)
{
    list **dup = (list **)data;
    list *current = *dup;
    list *previous = NULL;
    int k = 0;
    int h = 0;

    if (args[0] == NULL)
        return 84;
    k = my_getnbr(args[0]);
    if (*dup == NULL)
        return 84;
    if ((*dup)->id == k)
        return del_start(data);
    h = del_loop(current, previous, k);
    if (h == 84)
        return 84;
    return 0;
}
