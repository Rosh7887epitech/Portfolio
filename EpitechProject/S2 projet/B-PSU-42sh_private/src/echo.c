/*
** EPITECH PROJECT, 2024
** echo.c
** File description:
** that file should handle the echo function
*/
#include "my_project.h"

bool is_buildin(char *str)
{
    if (my_strncmp(str, "alias", 5) == 0 || my_strncmp(str, "which", 5) == 0)
        return true;
    if (my_strncmp(str, "exit", 4) == 0 || my_strncmp(str, "env", 3) == 0)
        return true;
    if (my_strncmp(str, "setenv", 6) == 0)
        return true;
    if (my_strncmp("cd", str, 2) == 0 || my_strncmp(str, "unsetenv", 8) == 0)
        return true;
    if (my_strncmp("history", str, 7) == 0 || my_strncmp(str, "!", 1) == 0)
        return true;
    if (my_strncmp("where", str, 5) == 0 || my_strncmp(str, "set", 3) == 0)
        return true;
    if (my_strncmp("unset", str, 5) == 0)
        return true;
    return false;
}
