/*
** EPITECH PROJECT, 2024
** exit.c
** File description:
** that function should handle the exit of the shell
*/
#include <stdlib.h>
#include "../include/my_project.h"
#include <unistd.h>
#include <sys/wait.h>

static int handle_error_exit(char *str)
{
    for (int i = 5; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && isatty(STDIN_FILENO))
            return my_printerror("exit: Expression Syntax.\n", 1);
        if (!isatty(STDIN_FILENO) && (str[i] < '0' || str[i] > '9')) {
            my_printerror("exit: Expression Syntax.\n", 1);
            exit(1);
        }
    }
    return -1;
}

int exit_function(char *str, envp_info_t *info)
{
    char *returned = NULL;

    if (my_strlen(str) == 4) {
        free_struct(info);
        exit(0);
    }
    if (my_strncmp(str, "exit ", 5) != 0) {
        for (int i = 0; str[i] != '\0' && str[i] != ' '; i++)
            write(2, &str[i], 1);
        return my_printerror(": Command not found.\n", 1);
    }
    if (handle_error_exit(str) != -1)
        return 1;
    returned = my_strcat(returned, str + 5);
    if (returned != NULL) {
        free_struct(info);
        exit(my_getnbr(returned));
    }
    return my_printerror("Error exiting\n", 84);
}

void wait_my_pid(char ***cmd, int index, int pid, int *status)
{
    if (cmd[index + 1] == NULL)
        waitpid(pid, status, 0);
    else {
        for (int i = 0; i < 5000000; i++)
            i = i;
    }
}
