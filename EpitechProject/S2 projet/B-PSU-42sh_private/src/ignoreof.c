/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** ignoreof
*/

#include "special_variable.h"

static int cond_ignoreof(char *result)
{
    if (my_strcmp(result, "ignoreeof ON") == 0 ||
        my_strcmp(result, "ignoreeof on") == 0) {
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);
    }
    if (my_strcmp(result, "ignoreeof OFF") == 0 ||
        my_strcmp(result, "ignoreeof off") == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
    }
    return 0;
}

int ignoreeof_function(envp_info_t *info)
{
    char *result = find_in_envp(info->local, "ignoreeof", 8);

    if (result == NULL || my_strcmp(result, "") == 0)
        result = find_in_envp(info->local, "ignoreeof", 8);
    if (result == NULL || my_strcmp(result, "") == 0)
        return 0;
    clean_esperluette(result);
    cond_ignoreof(result);
    free(result);
    return 0;
}
