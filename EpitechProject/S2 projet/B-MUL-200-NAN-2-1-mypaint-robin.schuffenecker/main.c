/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** that file should contain the main of our program
*/
#include <string.h>
#include "my_project.h"
#include <stdlib.h>
#include <stdio.h>

char *find_pwd(char **envp)
{
    if (envp == NULL)
        return "/home";
    for (int i = 0; envp[i]; i++) {
        if (my_strncmp(envp[i], "PWD=", 4) == 0)
            return my_strdup(envp[i] + 4);
    }
    return "/home";
}

int main(int argc, char **argv, char **envp)
{
    if (argc >= 2 || argv[1] != NULL)
        return 84;
    windows_loop(envp);
    return 0;
}
