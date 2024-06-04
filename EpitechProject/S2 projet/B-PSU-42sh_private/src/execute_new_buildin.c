/*
** EPITECH PROJECT, 2024
** execute_newbuildin.c
** File description:
** that file should execute new buildin
*/
#include "struct.h"
#include "my_project.h"

static int execute_slash(char *line_getted, envp_info_t *info)
{
    char **fct = NULL;
    char *redi = NULL;

    if (is_slash(line_getted)) {
        info->status = 1;
        fct = str_to_word_array(line_getted, " ");
        if (there_rediction(line_getted) && !handle_null_redi(fct, info))
            return 1;
        if (!make_good_tab(&fct))
            return 1;
        redi = redi_to_extract(fct);
        if (redi != NULL)
            redi += 1;
        if (handle_injection(fct))
            fct++;
        for (int i = 0; fct[i] != NULL; i++)
            fct[i] = remove_quotes(fct[i]);
        return my_exec(fct[0], fct, list_to_array(info->l_envp, NULL), redi);
    }
    return -55;
}

int execute_my_program(info_t *line, envp_info_t *info)
{
    int status = execute_alias_which(line->line_getted, info);

    if (status != -55)
        return status;
    status = local_functions(line, info);
    if (status == 0) {
        info->status = 1;
        return 0;
    }
    return execute_slash(line->line_getted, info);
}

int execute_alias_which(char *line_getted, envp_info_t *info)
{
    if (handle_where(info, line_getted))
        return info->return_status;
    if (handle_which(line_getted, info))
        return info->return_status;
    if (handle_alias_command(line_getted, &info->alias, info)) {
        info->status = 1;
        return 0;
    }
    return -55;
}
