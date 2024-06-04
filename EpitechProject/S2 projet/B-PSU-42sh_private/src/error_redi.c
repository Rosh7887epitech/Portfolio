/*
** EPITECH PROJECT, 2024
** error_redi.c
** File description:
** that file should handle redirection error
*/
#include "my_project.h"
#include <stdbool.h>
#include <stdlib.h>

bool is_good_redi(redirection_t *redi)
{
    int inje = 0;
    int redire = 0;

    while (redi) {
        if (is_injection(redi->redi) != -1)
            inje++;
        if (is_redirection(redi->redi) != -1)
            redire++;
        redi = redi->next;
    }
    if (inje > 1)
        return my_printerror("Ambiguous input redirect.\n", false);
    if (redire > 1)
        return my_printerror("Ambiguous output redirect.\n", false);
    return true;
}

bool there_injection(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '<' && is_pos_in_quotes(str, i) == NO_QUOTES)
            return true;
    }
    return false;
}

bool is_ambiguous_redirect(char **cmd)
{
    for (int j = 0; cmd[j]; j++)
        if (there_rediction(cmd[j]))
            return my_printerror("Ambiguous output redirect.\n", true);
    return false;
}

bool is_ambiguous_injection(char ***cmd, int i)
{
    for (int j = 0; cmd[i][j]; j++)
        if (cmd[i + 1] == NULL && there_injection(cmd[i][j]))
            return my_printerror("Ambiguous input redirect.\n", true);
    return false;
}

void error_injection(char ***command, envp_info_t *info)
{
    for (int i = 0; command[i]; i++) {
        if (is_injection(command[i][0]) != -1
            && open(command[i][0] + 1, O_RDONLY) != 0)
            info->return_status = 1;
    }
}
