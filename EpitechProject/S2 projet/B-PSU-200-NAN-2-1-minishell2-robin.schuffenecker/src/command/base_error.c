/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** base_error
*/

#include "command.h"

int errno_error(char *line)
{
    if (errno == EACCES) {
        my_putsterr(line);
        my_putsterr(": Permission denied.\n");
        return 1;
    }
    if (errno == ENOEXEC) {
        my_putsterr(line);
        my_putsterr(": Exec format error. Wrong Architecture.\n");
        return 1;
    }
    return 0;
}

int exec_error(base_t *var, char *line)
{
    struct stat sb;

    if (stat(line, &sb) == -1) {
        my_putsterr(line);
        my_putsterr(": Command not found.\n");
        return 1;
    }
    if (access(line, W_OK | X_OK) == -1) {
        my_putsterr(line);
        my_putsterr(": Permission denied.\n");
        return 1;
    }
    return errno_error(line);
}
