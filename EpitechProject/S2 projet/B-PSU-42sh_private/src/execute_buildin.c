/*
** EPITECH PROJECT, 2024
** execute_buildin.c
** File description:
** that function should execute buildin
*/

#include "my_project.h"
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *array_to_str(char **array)
{
    char *str = NULL;

    for (int i = 0; array[i] != NULL; i++)
        str = my_strcat(str, my_strcat(array[i], " "));
    return str;
}

static void redirect_last_buildin(char ***cmd, int i)
{
    int status = is_redirection(cmd[i][array_size(cmd[i]) - 1]);

    if (status != -1) {
        redirect_write(cmd[i][array_size(cmd[i]) - 1], status);
        cmd[i][array_size(cmd[i]) - 1] = NULL;
    }
}

bool execute_pipe_last_buildin(char ***cmd, envp_info_t *info)
{
    char *str = NULL;
    info_t line;
    int status = dup(STDOUT_FILENO);

    for (int i = 0; cmd[i] != NULL; i++) {
        if (cmd[i + 1] == NULL && is_buildin(cmd[i][0])) {
            redirect_last_buildin(cmd, i);
            str = array_to_str(cmd[i]);
            clean_str(str);
            line.directory_home = find_in_envp(info->l_envp, "HOME=", 5);
            line.line_getted = my_strdup(str);
            info->return_status = my_build_in(&line, info);
            info->status = 0;
            free(str);
            dup2(status, STDOUT_FILENO);
            return true;
        }
    }
    return false;
}
