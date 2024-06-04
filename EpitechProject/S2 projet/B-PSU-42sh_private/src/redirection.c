/*
** EPITECH PROJECT, 2024
** redirection.c
** File description:
** that file should handle the redirection
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_project.h"

bool is_pipe(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '|' && str[i + 1] == '|')
            return false;
        if (str[i] == '|')
            return true;
    }
    return false;
}

int is_injection(char *str)
{
    if (str[0] == '<' && str[1] != '<')
        return SIMPLE;
    if (str[0] == '<' && str[1] == '<')
        return DOUBLE;
    return -1;
}

int is_redirection(char *str)
{
    if (str[0] == '>' && str[1] != '>')
        return SIMPLE;
    if (str[0] == '>' && str[1] == '>')
        return DOUBLE;
    return -1;
}

void redirect_write(char *filename, int status)
{
    int file_descriptor = 0;

    if (status == SIMPLE) {
        filename = filename + 1;
        file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0755);
    }
    if (status == DOUBLE) {
        filename = filename + 2;
        file_descriptor = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0755);
    }
    if (file_descriptor == -1)
        return;
    dup2(file_descriptor, STDOUT_FILENO);
    return;
}

static void free_redirection_list(redirection_t *redi)
{
    redirection_t *tmp = NULL;

    while (redi) {
        tmp = redi->next;
        free(redi->redi);
        free(redi);
        redi = tmp;
    }
    if (tmp)
        free(tmp);
}

bool check_commands(char ***cmd)
{
    redirection_t *redi = NULL;

    for (int i = 0; cmd[i + 1]; i++) {
        if (is_ambiguous_redirect(cmd[i]))
            return false;
    }
    for (int i = 0; cmd[i]; i++) {
        if (is_ambiguous_injection(cmd, i))
            return false;
    }
    for (int i = 0; cmd[i]; i++) {
        redi = list_redirection(cmd[i]);
        if (!is_good_redi(redi))
            return false;
        modify_redis(&redi);
        cmd[i] = redirection_t_array(redi);
        free_redirection_list(redi);
    }
    return true;
}
