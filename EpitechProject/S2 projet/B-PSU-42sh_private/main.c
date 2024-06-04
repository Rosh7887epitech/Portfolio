/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** that function should be the main of my project
*/
#include "include/my_project.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

static void pre_set_local(envp_info_t *environ)
{
    info_t tmp;

    tmp.line_getted = my_strdup("set ignoreeof=OFF");
    local_functions(&tmp, environ);
}

int my_shell(envp_info_t *environ)
{
    int status = 1;

    pre_set_local(environ);
    shell_input(environ->my_cd, environ, status);
    free_struct(environ);
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    envp_info_t *envp_info = NULL;

    if (argc != 1 && argv[0] != NULL)
        return my_printerror("Unknown option\n", 84);
    envp_info = alloc_struct(envp);
    return my_shell(envp_info);
}
