/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** special_variable
*/

#include "special_variable.h"

int set_special_variables(envp_info_t *envp)
{
    char *cwd = getcwd(NULL, 0);

    if (envp == NULL || cwd == NULL)
        return 1;
    modify_envp(&envp->l_envp, "CWD", cwd);
    if (my_strcmp(find_in_envp(envp->l_envp, "TERM=", 4), "") == 0)
        modify_envp(&envp->l_envp, "TERM", "xterm-256color");
    return 0;
}

bool there_alias_searched(alias_t *tmp, char *search)
{
    while (tmp) {
        if (my_strcmp(tmp->name, search) == 0)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int exec_precmd(info_t *line, envp_info_t *info)
{
    if (there_alias_searched(info->alias, "precmd")) {
        line->line_getted = replace_alias_in_str("precmd", info->alias);
        our_sh(line, info, 1);
    }
    return 0;
}

int exec_cwdcmd(info_t *line, envp_info_t *info)
{
    if (there_alias_searched(info->alias, "cwdcmd")) {
        line->line_getted = replace_alias_in_str("cwdcmd", info->alias);
        our_sh(line, info, 1);
    }
    return 0;
}
