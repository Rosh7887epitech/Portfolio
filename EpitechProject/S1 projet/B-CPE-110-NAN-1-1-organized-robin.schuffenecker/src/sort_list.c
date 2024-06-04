/*
** EPITECH PROJECT, 2023
** sort
** File description:
** sort
*/

#include "../shell/shell.h"
#include "../include/org.h"

static int cond_material(void *data, char **args, int i)
{
    if (my_strcmp(args[i], "NAME") == 0 ||
    my_strcmp(args[i], "TYPE") == 0 ||
    my_strcmp(args[i], "ID") == 0 ||
    my_strcmp(args[i], "-r") == 0) {
        return 0;
    } else {
        return 84;
    }
}

static void fonc_sort_rev(void *data, char **args, int i)
{
    if (my_strcmp(args[i + 1], "-r") == 0) {
        if (my_strcmp(args[i], "TYPE") == 0)
                sort_type_rev(data, args);
        if (my_strcmp(args[i], "NAME") == 0)
                sort_name_rev(data, args);
        if (my_strcmp(args[i], "ID") == 0)
                sort_id_rev(data, args);
    }
}

static void fonc_sort(void *data, char **args, int i)
{
    if (my_strcmp(args[i], "TYPE") == 0)
        sort_type(data, args);
    if (my_strcmp(args[i], "NAME") == 0)
        sort_name(data, args);
    if (my_strcmp(args[i], "ID") == 0)
        sort_id(data, args);
}

int sort(void *data, char **args)
{
    if (args[0] == NULL) {
        return 84;
    }
    for (int i = 0; args[i] != NULL; i++) {
        if (i >= 2) {
            return 84;
        }
        if (cond_material(data, args, i) == 84)
            return 84;
        if (args[i + 1] != NULL) {
            fonc_sort_rev(data, args, i);
        } else {
            fonc_sort(data, args, i);
        }
    }
    return 0;
}
