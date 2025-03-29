/*
** EPITECH PROJECT, 2023
** add_list
** File description:
** add list for link list
*/

#include "../shell/shell.h"
#include "../include/org.h"

static void display(list *node, char **args, int i)
{
    write(1, args[i], my_strlen(args[i]));
    write(1, " n°", 4);
    my_put_nbr(node->id);
    write(1, " - ", 4);
    my_putchar('"');
    write(1, args[i + 1], my_strlen(args[i + 1]));
    my_putchar('"');
    write(1, " added.\n", 9);
}

static int cond_material(void *data, char **args, int i)
{
    if (my_strcmp(args[i], "WIRE") == 0 ||
    my_strcmp(args[i], "DEVICE") == 0 ||
    my_strcmp(args[i], "ACTUATOR") == 0 ||
    my_strcmp(args[i], "PROCESSOR") == 0 ||
    my_strcmp(args[i], "SENSOR") == 0) {
        return 0;
    } else {
        return 84;
    }
}

int add_data(void *data, char **args, list *node)
{
    static int g = 0;

    for (int i = 0; args[i] != NULL || args[i + 1] != NULL; i += 2) {
        if (cond_material(data, args, i) == 84)
            return 84;
        node = malloc(sizeof(list));
        if (node == NULL)
            return 84;
        node->type = my_strdup(args[i]);
        node->id = g;
        g++;
        node->name = my_strdup(args[i + 1]);
        node->next = *(list **)data;
        *(list **)data = node;
        display(node, args, i);
    }
    return 0;
}

int add(void *data, char **args)
{
    list *node = *(list **)data;
    int i = 0;

    while (args[i] != NULL) {
        i++;
    }
    if (args[0] == NULL)
        return 84;
    if (i % 2 == 1)
        return 84;
    if (add_data(data, args, node) == 84) {
        return 84;
    } else {
        return 0;
    }
}
