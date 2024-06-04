/*
** EPITECH PROJECT, 2024
** build_in.c
** File description:
** that file should launch all the build in function
*/

#include "my_project.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

static int print_env(char *line_getted, path_t *list_envp)
{
    if (line_getted == NULL)
        return 0;
    if (my_strcmp(remove_quotes(line_getted), "env") == 0 ||
    my_strcmp(line_getted, "setenv") == 0) {
        print_list(list_envp);
        return 0;
    }
    return 1;
}

static int exit_error_setenv(char **array)
{
    if (is_char_alpha(array[0][0]) == false)
        my_printerror("setenv: Variable name must begin with a letter.\n", 1);
    else {
        my_printerror("setenv: Variable name must contain ", 1);
        my_printerror("alphanumeric characters.\n", 1);
    }
    if (!isatty(STDIN_FILENO))
        exit(1);
    return 1;
}

static int unsetenv_handler(info_t *line, envp_info_t *env, char **array)
{
    int len = 0;

    if (my_strncmp(line->line_getted, "unsetenv", 8) == 0) {
        env->status = 1;
        array = strtok_with_quotes(line->line_getted, " ");
        for (int i = 0; array[i]; i++)
            array[i] = remove_quotes(array[i]);
        len = array_size(array);
        if (len < 2)
            return my_printerror("unsetenv: Too few arguments.\n", 1);
        remove_envp(&env->l_envp, array[1]);
        return 0;
    }
    return 1;
}

static int setenv_function(info_t *line, envp_info_t *env)
{
    char **array = NULL;
    char **array_w_quotes = NULL;
    int len = 0;

    if (my_strncmp(line->line_getted, "setenv ", 7) == 0) {
        env->status = 1;
        array = strtok_with_quotes(line->line_getted + 7, " ");
        array_w_quotes = my_strtok(line->line_getted + 7, " ");
        len = array_size(array);
        if (is_alphanum(array_w_quotes[0]) != 0 ||
        is_char_alpha(array_w_quotes[0][0]) == false)
            return exit_error_setenv(array_w_quotes);
        if (len > 2)
            return my_printerror("setenv: Too many arguments.\n", 1);
        modify_envp(&env->l_envp, array_w_quotes[0], remove_quotes(array[1]));
        return 0;
    }
    return unsetenv_handler(line, env, array);
}

bool handle_null_redi(char **array, envp_info_t *info)
{
    int len = array_size(array);
    int status = 0;

    for (int i = 0; array[i]; i++) {
        status = is_redirection(array[i]);
        if (status != -1 && len < 2) {
            info->return_status = 1;
            return my_printerror("Invalid null command.\n", false);
        }
    }
    return true;
}

bool there_rediction(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '>' && is_pos_in_quotes(str, i) == NO_QUOTES)
            return true;
    }
    return false;
}

bool make_good_tab(char ***fct)
{
    redirection_t *redi_l = list_redirection(*fct);

    if (!is_good_redi(redi_l))
        return false;
    modify_redis(&redi_l);
    *fct = redirection_t_array(redi_l);
    return true;
}

char *redi_to_extract(char **fct)
{
    int count = 0;
    char *redi = NULL;

    for (int i = 0; fct[i]; i++) {
        count = is_redirection(fct[i]);
        if (count != -1) {
            redi = my_strdup(fct[i]);
            fct[i] = NULL;
            break;
        }
    }
    return redi;
}

int my_build_in(info_t *line, envp_info_t *info)
{
    int stdindup = dup(STDIN_FILENO);
    int returned = execute_my_program(line, info);

    dup2(stdindup, STDIN_FILENO);
    if (returned != -55)
        return returned;
    returned = history_command(line, info);
    info->status = 1;
    if (returned != 0)
        return 1;
    if (my_strncmp(line->line_getted, "exit", 4) == 0)
        return exit_function(line->line_getted, info);
    if (my_strncmp(line->line_getted, "cd", 2) == 0)
        return change_directory(line->line_getted, info, line);
    if (print_env(line->line_getted, info->l_envp) != 1)
        return 0;
    else if (returned == 1)
        return 0;
    info->status = 0;
    return setenv_function(line, info);
}
