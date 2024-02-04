/*
** EPITECH PROJECT, 2023
** put list
** File description:
** put list for linked list
*/

#include "../include/org.h"
#include "../shell/shell.h"

int disp(void *data, char **args)
{
    list *current = *(list **)data;

    if (args[0] != NULL)
        return 84;
    while (current != NULL) {
        write(1, current->type, my_strlen(current->type));
        write(1, " n°", 4);
        my_put_nbr(current->id);
        write(1, " - ", 4);
        my_putchar('"');
        write(1, current->name, my_strlen(current->name));
        my_putchar('"');
        write(1, "\n", 2);
        current = current->next;
    }
    return 0;
}
