/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** handle_pipes_or
*/

#include <stdbool.h>
#include "my_project.h"

bool there_pipes_or(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|' && str[i + 1] == '|')
            return true;
    }
    return false;
}

bool is_invalid_pipe_or(char *str)
{
    char **array = my_strtok(str, " ");

    if (there_esperluette(str) == true && is_invalid_esperluette(str) == true)
        return my_printerror("Invalid null command.\n", true);
    if (str[0] == '|')
        return handle_null_command();
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|' && str[i + 1] == '\0')
            return handle_null_command();
    }
    for (int i = 0; array[i + 1] != NULL; i++) {
        clean_esperluette(array[i]);
        if (array[i][0] == '&' && array[i + 1][0] == '|')
            return handle_null_command();
        if (array[i][0] == '|' && array[i + 1][0] == '&')
            return handle_null_command();
    }
    return false;
}

static bool invalid_pipe_or_globbings(info_t *line, envp_info_t *info)
{
    if (replace_dollar(info, line) == 1)
        return true;
    execute_globbings(line, info);
    if (line->line_getted == NULL) {
        info->return_status = 1;
        return true;
    }
    return false;
}

static int check_info(envp_info_t *info)
{
    static int index = 0;

    if (info->return_status == 0) {
        index++;
    }
    if (index != 0) {
        index = 0;
        return 1;
    }
    return 0;
}

static void manage_line(info_t *line, char **array, int i)
{
    clean_esperluette(array[i]);
    line->line_getted = my_strdup(array[i]);
    clean_esperluette(line->line_getted);
}

static int check_other_feature(envp_info_t *info, info_t *line)
{
    if (invalid_pipe_or_globbings(line, info)) {
        if (check_info(info) == 1)
            return -1;
        return 1;
    }
    if (handle_esperluette(line->line_getted, info)) {
        if (check_info(info) == 1)
            return -1;
        return 1;
    }
    if (correct_str_alias(line, info)) {
        if (check_info(info) == 1)
            return -1;
        return 1;
    }
    handle_backtick(line->line_getted, info);
    return 0;
}

static char *change_pipes_or(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        replace_strings(str, "||", "°");
    }
    return str;
}

void pipes_or_handling(envp_info_t *info, info_t *line, char *str)
{
    int ret_value = 0;
    char **array = NULL;

    str = change_pipes_or(str);
    array = my_strtok(str, "°");
    if (array == NULL)
        return;
    for (int i = 0; array[i] != 0; i++) {
        manage_line(line, array, i);
        ret_value = check_other_feature(info, line);
        if (ret_value == -1)
            break;
        if (ret_value == 1)
            continue;
        our_sh(line, info, 0);
        if (check_info(info) == 1) {
            break;
        }
    }
}

void execute_pipes_or(char *str, envp_info_t *info)
{
    char **semicolon_array = my_strtok(str, ";");
    info_t line;

    line.directory_home = find_in_envp(info->l_envp, "HOME=", 5);
    line.line_getted = NULL;
    if (semicolon_array == NULL || line.directory_home == NULL)
        return;
    line.directory_home = line.directory_home + 5;
    for (int i = 0; semicolon_array[i] != NULL; i++) {
        clean_esperluette(semicolon_array[i]);
        info->return_status = 0;
        if (there_pipes_or(semicolon_array[i]) == true)
            pipes_or_handling(info, &line, str);
        else {
            line.line_getted = semicolon_array[i];
            our_sh(&line, info, 0);
        }
    }
}

bool handle_pipes_or(char *line, envp_info_t *info)
{
    char *cpy = NULL;

    if (line == NULL || my_strcmp(line, "\n") == 0)
        return true;
    if (there_pipes_or(line) == false)
        return false;
    cpy = my_strdup(line);
    clean_esperluette(cpy);
    if (is_invalid_pipe_or(cpy)) {
        info->return_status = 1;
        info->status = 1;
        return true;
    }
    if (my_strcmp(cpy, "||") == 0)
        return true;
    free(cpy);
    execute_pipes_or(line, info);
    return true;
}
