/*
** EPITECH PROJECT, 2024
** getline.c
** File description:
** that function should get line and handle wrong input
*/
#include "my_project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <stdbool.h>

char *shell_function(char *str)
{
    int count = 0;
    char *returned = NULL;

    for (count = 0; str[count] != '\0' && str[count] != ' '; count++);
    returned = malloc(sizeof(char) * (count + 1));
    my_strncpy(returned, str, count);
    returned[count] = '\0';
    return returned;
}

char *make_tab_redi(char ***array, info_t *line, envp_info_t *i)
{
    char *redi = NULL;

    if (there_rediction(line->line_getted)) {
        *array = str_to_word_array(line->line_getted, " ");
        if (there_rediction(line->line_getted) && !handle_null_redi(*array, i))
            return NULL;
        if (!make_good_tab(array))
            return NULL;
        redi = redi_to_extract(*array);
        if (redi != NULL)
            redi += 1;
    }
    redi = remove_quotes(redi);
    return redi;
}

char **rm_quotes_tab(char **array)
{
    array = remove_useless_char_tab(array);
    for (int i = 0; array[i] != NULL; i++)
        array[i] = remove_quotes(array[i]);
    return array;
}

bool correct_str_alias(info_t *line, envp_info_t *envp)
{
    if (there_esperluette(line->line_getted))
        return false;
    line->line_getted = replace_alias_in_str(line->line_getted,
    envp->alias);
    if (line->line_getted == NULL) {
        envp->return_status = 1;
        if (!isatty(STDIN_FILENO))
            exit(1);
        return true;
    }
    return false;
}

int shell_input(info_t *line, envp_info_t *envp, int status)
{
    while (status > 0) {
        envp->status = 0;
        envp->is_semicolon = 0;
        status = get_the_line(line, envp);
        if (line->line_getted[0] == '\n') {
            exec_precmd(line, envp);
            continue;
        }
        set_special_variables(envp);
        add_history(line->line_getted, envp);
        if (first_pos_esperluette(line, envp))
            continue;
        if (handle_backtick(line->line_getted, envp) == -1)
            continue;
        clean_esperluette(line->line_getted);
        our_sh(line, envp, status);
        exec_precmd(line, envp);
    }
    return status;
}
