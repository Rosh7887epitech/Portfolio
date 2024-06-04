/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** base_error
*/

#include "command.h"

int errno_error(base_t *var, char *line)
{
    if (errno == EACCES) {
        my_putstr(line);
        my_putstr(": Permission denied.\n");
        return 1;
    }
    if (errno == ENOEXEC) {
        my_putstr(line);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        return 1;
    }
}

int exec_error(base_t *var, char *line)
{
    struct stat sb;

    if (stat(line, &sb) == -1) {
        my_putstr(line);
        my_putstr(": Command not found.\n");
        return 1;
    }
    if (access(line, W_OK | X_OK) == -1) {
        my_putstr(line);
        my_putstr(": Permission denied.\n");
        return 1;
    }
    return errno_error(var, line);
}
