/*
** EPITECH PROJECT, 2024
** handle_esperluette.c
** File description:
** that file should handle esperluette
*/
#include <stdbool.h>
#include "my_project.h"

bool there_esperluette(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&' && is_pos_in_quotes(str, i) == NO_QUOTES)
            return true;
    }
    return false;
}

static bool is_jobs_control(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i > 0 && str[i] == '&' && (str[i + 1] != '&' &&
            str[i - 1] != '&')) {
            return true;
        }
    }
    return false;
}

bool is_invalid_esperluette(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&' && is_pos_in_quotes(str, i) == NO_QUOTES)
            count++;
        if (str[i] == '&' && str[i + 1] == '\0' && count != 1)
            return my_printerror("Invalid null command.\n", true);
        if (str[i] != '&' && count > 2)
            return my_printerror("Invalid null command.\n", true);
        if (str[i] != '&')
            count = 0;
    }
    return false;
}

static bool invalid_esperluette_globbings(info_t *line, envp_info_t *info)
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

char **esperluette_handling(char **array, envp_info_t *info, info_t *line)
{
    int count = 0;
    char **array_alias = malloc(sizeof(char *) * (array_size(array)));

    for (int i = 0; array[i] != 0 && info->return_status == 0; i++) {
        line->line_getted = my_strdup(array[i]);
        clean_esperluette(line->line_getted);
        if (my_strncmp("alias", line->line_getted, 5) == 0) {
            array_alias[count] = my_strdup(line->line_getted);
            count++;
            continue;
        }
        if (invalid_esperluette_globbings(line, info))
            continue;
        if (correct_str_alias(line, info))
            continue;
        handle_backtick(line->line_getted, info);
        execute_semicolon_pipe(line, info, 0);
    }
    array_alias[count] = NULL;
    return array_alias;
}

static char *replace_double_esperluette(char *str)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        replace_strings(str, "&&", "£");
    return str;
}

// execute_globbings(&line) should be in line 56 57;
void execute_esperluette(char *str, envp_info_t *info)
{
    char **array = NULL;
    char **array_alias = NULL;
    info_t line;

    if (str == NULL)
        return;
    line.directory_home = find_in_envp(info->l_envp, "HOME=", 5);
    line.line_getted = NULL;
    str = replace_double_esperluette(str);
    array = my_strtok(str, "£");
    if (array == NULL || line.directory_home == NULL)
        return;
    line.directory_home = line.directory_home + 5;
    info->return_status = 0;
    array_alias = esperluette_handling(array, info, &line);
    for (int i = 0; array_alias[i] != NULL; i++)
        handle_alias_command(array_alias[i], &info->alias, info);
}

bool handle_esperluette(char *line, envp_info_t *info)
{
    char *cpy = NULL;

    if (line == NULL || my_strcmp(line, "\n") == 0)
        return true;
    if (there_esperluette(line) == false)
        return false;
    cpy = my_strdup(line);
    clean_esperluette(cpy);
    if (is_jobs_control(cpy))
        return false;
    if (is_invalid_esperluette(cpy)) {
        info->return_status = 1;
        info->status = 1;
        return true;
    }
    if (my_strcmp(cpy, "&&") == 0)
        return true;
    free(cpy);
    execute_esperluette(line, info);
    return true;
}
