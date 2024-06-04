/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** replace_dollar
*/

#include "my_project.h"

static int get_pos_next_space(char *str, int pos)
{
    for (; str[pos] != '\0' && str[pos] != ' '; pos++);
    return pos - 1;
}

static int get_pos_next_delim(char *str, int pos)
{
    for (; str[pos] != '\0' && is_charalphanum(str[pos]) == 0; pos++);
    return pos - 1;
}

static char *extract_list_value(char *str, char delim)
{
    char *tmp;
    int i = 0;
    int index = 0;

    if (str == NULL)
        return NULL;
    tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; str[i] != '\0' && str[i] != delim; i++);
    if (str[i] == '\0' || str[i + 1] == '\0')
        return "";
    i++;
    for (index = 0; str[i] != '\0'; index++) {
        tmp[index] = str[i];
        i++;
    }
    tmp[index] = '\0';
    return tmp;
}

static char *get_value_from_list(path_t *list, int pos)
{
    if (pos == -1 || list == NULL)
        return NULL;
    for (int i = 0; i < pos && list != NULL; i++)
        list = list->next;
    if (list == NULL)
        return NULL;
    return my_strdup(list->value);
}

static char *search_in_envs(envp_info_t *info, char *name)
{
    int result = 0;
    char *str = NULL;

    if (info->l_envp == NULL && info->local == NULL)
        return NULL;
    result = search_list(info->local, name);
    str = extract_list_value(get_value_from_list(info->local, result), '\t');
    if (str != NULL)
        return my_strdup(str);
    result = search_list(info->l_envp, name);
    str = extract_list_value(get_value_from_list(info->l_envp, result), '=');
    if (str != NULL)
        return my_strdup(str);
    return NULL;
}

static char *get_str_between_pos(char *str, int pos1, int pos2)
{
    char *tmp = malloc(sizeof(char) * (pos2 - pos1 + 2));
    int j = 0;

    for (int i = pos1; i <= pos2; i++) {
        tmp[j] = str[i];
        j++;
    }
    tmp[j] = '\0';
    return tmp;
}

static char *handle_dollar(envp_info_t *info, char *str, int j)
{
    char *value = NULL;
    char *tmp = NULL;

    if (str[j] != '$' || is_pos_in_quotes(str, j) == SINGLE_QUOTES ||
        str[j + 1] == '\0' || str[j + 1] == ' ')
        return NULL;
    tmp = get_str_between_pos(str, j, get_pos_next_space(str, j));
    if (tmp[1] == '?') {
        value = my_itoa(info->return_status);
        replace_strings(str, tmp, value);
        return NULL;
    }
    tmp = get_str_between_pos(str, j, get_pos_next_delim(str, j + 1));
    if (is_charalphanum(tmp[1]) == 1)
        return "ILLEGAL VAR NAME PRINT ERROR\n";
    value = search_in_envs(info, tmp + 1);
    if (value == NULL)
        return tmp + 1;
    replace_strings(str, tmp, value);
    return NULL;
}

static int dollar_error(char *str, envp_info_t *info)
{
    if (my_strcmp(str, "ILLEGAL VAR NAME PRINT ERROR\n") == 0) {
        my_putstr("Illegal variable name.\n");
        info->return_status = 1;
        if (!isatty(STDIN_FILENO))
            exit(1);
        return 1;
    }
    my_putstr(str);
    my_putstr(": Undefined variable.\n");
    info->return_status = 1;
    if (!isatty(STDIN_FILENO))
        exit(1);
    return 1;
}

int replace_dollar(envp_info_t *info, info_t *line)
{
    char *str = my_strdup(line->line_getted);
    char *tmp = NULL;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ';' && is_pos_in_quotes(str, i) == NO_QUOTES)
            return 0;
    }
    clean_esperluette(str);
    for (int i = 0; str[i]; i++) {
        tmp = handle_dollar(info, str, i);
        if (tmp != NULL)
            return dollar_error(tmp, info);
    }
    line->line_getted = my_strdup(str);
    return 0;
}
