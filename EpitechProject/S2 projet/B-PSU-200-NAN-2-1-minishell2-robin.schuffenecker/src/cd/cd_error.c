/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** cd_error
*/

#include "cd.h"

int cd_error(base_t *var, char **where, struct stat *sb)
{
    if (stat(where[1], sb) == 0) {
        if (!S_ISDIR(sb->st_mode)) {
            my_putstr(where[1]);
            my_putstr(": Not a directory.\n");
            return 1;
        }
    }
    my_putstr(var->command[1]);
    my_putstr(": No such file or directory.\n");
    if (!isatty(0))
        exit(1);
    return 1;
}
