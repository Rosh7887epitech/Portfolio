/*
** EPITECH PROJECT, 2024
** B-PSU-MIRROR-42
** File description:
** globbings
*/
#include "globbings.h"
#include "struct.h"

static char *globbings(char *line, int *pos, bool *is_error)
{
    glob_t glob_result;
    char *str = NULL;

    if (glob(line, 0, NULL, &glob_result) == GLOB_NOMATCH)
        return NULL;
    for (int i = 0; glob_result.gl_pathv[i]; i++) {
        glob_result.gl_pathv[i] = my_strcat("\'", glob_result.gl_pathv[i]);
        glob_result.gl_pathv[i] = my_strcat(glob_result.gl_pathv[i], "\'");
        str = my_strcat(str, my_strcat(glob_result.gl_pathv[i], " "));
    }
    *pos += my_strlen(str - 1);
    *is_error = false;
    return my_strdup(str);
}

static bool check_close_bracket(char *line, int pos)
{
    for (int i = pos; line[i] != '\0' && line[i] != ' ' &&
        line[i] != '\n' && line[i] != '|' && line[i] != '>' &&
        line[i] != '<'; i++) {
        if (line[i] == ']')
            return true;
    }
    return false;
}

static bool there_is_glob(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if ((line[i] == '?' || line[i] == '*') &&
        is_pos_in_quotes(line, i) == NO_QUOTES)
            return true;
        if (line[i] == '[' && is_pos_in_quotes(line, i) == NO_QUOTES &&
        check_close_bracket(line, i))
                return true;
    }
    return false;
}

char *remove_chars_in_str(char *str, int pos1, int pos2)
{
    char *new_str = malloc(sizeof(char) *
    ((my_strlen(str) + 1) - (pos2 - pos1)));
    int j = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (i >= pos1 && i < pos2) {
            i++;
            continue;
        }
        new_str[j] = str[i];
        i++;
        j++;
    }
    new_str[j] = '\0';
    free(str);
    return new_str;
}

static void assign_pre_next(char *str, int i, int *next, int *pre)
{
    int j = i;

    if (str[i] != '[') {
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' &&
        str[i] != '|' && str[i] != '>' && str[i] != '<')
            i++;
    } else {
        while (str[i] != '\0' && str[i] != ' ' &&
        str[i] != '\n' && str[i] != '|' && str[i] != '>' && str[i] != '<')
            i++;
        if (!check_close_bracket(str, j))
            i = -1;
    }
    *next = i;
    i = j;
    while (i > 0 && str[i] != ' ' && str[i] != '|' && str[i] != '>' &&
    str[i] != '<')
        i--;
    i++;
    *pre = i;
}

static char *get_str(char *tmp, int pre, int next)
{
    char *str = malloc(sizeof(char) * (next - pre + 1));
    int j = 0;

    for (int i = pre; i < next; i++) {
        str[j] = tmp[i];
        j++;
    }
    str[j] = '\0';
    return str;
}

static bool is_glob(char *line, int i, int *next, int *pre)
{
    if ((line[i] != '?' && line[i] != '*' && line[i] != '[') ||
    is_pos_in_quotes(line, i) != NO_QUOTES)
        return false;
    assign_pre_next(line, i, next, pre);
    if (*next < 0)
        return false;
    return true;
}

static char *check_glob(char *line, bool *is_error)
{
    char *str;
    char *tmp = my_strdup(line);
    char *save = my_strdup(line);
    int next = 0;
    int pre = 0;

    for (int i = 0; save[i] != '\0'; i++) {
        tmp = my_strdup(save);
        if (is_glob(save, i, &next, &pre) == false)
            continue;
        str = get_str(tmp, pre, next);
        tmp = remove_chars_in_str(tmp, pre, next);
        save = my_strdup(tmp);
        tmp = str_cat_at_pos(tmp, globbings(str, &pre, is_error), pre);
        if (tmp != NULL)
            save = my_strdup(tmp);
    }
    if (tmp == NULL)
        return my_strdup(save);
    return my_strdup(tmp);
}

static int do_glob_error(info_t *line, envp_info_t *info)
{
    my_putstr(my_strtok(line->line_getted, " ")[0]);
    my_putstr(": No match.\n");
    info->status = 1;
    info->return_status = 1;
    return 1;
}

int execute_globbings(info_t *line, envp_info_t *info)
{
    char *str = NULL;
    bool is_error = true;

    if (!there_is_glob(line->line_getted))
        return 0;
    for (int i = 0; line->line_getted[i] != '\0'; i++) {
        if (line->line_getted[i] == ';' &&
        is_pos_in_quotes(line->line_getted, i) == NO_QUOTES)
            return 0;
    }
    str = check_glob(my_strdup(line->line_getted), &is_error);
    if (is_error == true)
        return do_glob_error(line, info);
    clean_esperluette(str);
    line->line_getted = my_strdup(str);
    free(str);
    return 0;
}
