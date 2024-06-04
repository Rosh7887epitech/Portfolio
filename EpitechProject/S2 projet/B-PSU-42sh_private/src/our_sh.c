/*
** EPITECH PROJECT, 2024
** our_sh.c
** File description:
** that file should call all our sh functionnality after getline
*/
#include "my_project.h"
int handle_unknown_command(char *env_find, char *input)
{
    if (!env_find) {
        my_printerror(input, 84);
        free(input);
        return my_printerror(": Command not found.\n", 1);
    }
    return 0;
}

int user_shell_fonction(info_t *line, envp_info_t *info)
{
    char *input = NULL;
    char *env_find = NULL;
    char *fct = NULL;
    char **array = NULL;
    char *redi = NULL;

    redi = make_tab_redi(&array, line, info);
    if (handle_usr_injection(line, &array, info) != 0)
        return 1;
    if (array == NULL)
        array = str_to_word_array(line->line_getted, " ");
    input = my_strdup(array[0]);
    fct = reduce_path(input);
    fct = remove_quotes(fct);
    env_find = find_path(info->l_envp, fct);
    if (handle_unknown_command(env_find, remove_quotes(input)) != 0)
        return 1;
    fct = my_strcat(env_find, my_strcat("/", fct));
    array = rm_quotes_tab(array);
    return my_exec(fct, array, list_to_array(info->l_envp, NULL), redi);
}

static int user_input(info_t *line, envp_info_t *info, int status)
{
    if (execute_jobs_control(line, info) == 1) {
        info->return_status = 1;
        return 1;
    }
    if (line->line_getted[0] == '\n')
        return 0;
    clean_esperluette(line->line_getted);
    if (replace_dollar(info, line) == 1)
        return 1;
    if (execute_globbings(line, info) == 1)
        return 1;
    status = my_build_in(line, info);
    if (info->status == 1)
        return status;
    return user_shell_fonction(line, info);
}

static bool normal_shell(info_t *line, envp_info_t *envp, int status)
{
    int fd_dup = dup(STDIN_FILENO);

    if (!is_pipe(line->line_getted) && !is_semicolon(line->line_getted)) {
        envp->return_status = user_input(line, envp, status);
        dup2(fd_dup, STDIN_FILENO);
        envp->status = 0;
        return true;
    }
    return false;
}

void our_sh(info_t *line, envp_info_t *envp, int status)
{
    if (check_inhibitors(line, envp) != 0)
        return;
    if (correct_str_alias(line, envp) == true)
        return;
    handle_backtick(line->line_getted, envp);
    clean_esperluette(line->line_getted);
    if (handle_pipes_or(line->line_getted, envp) ||
    handle_esperluette(line->line_getted, envp))
        return;
    if (normal_shell(line, envp, status))
        return;
    execute_semicolon_pipe(line, envp, status);
}
