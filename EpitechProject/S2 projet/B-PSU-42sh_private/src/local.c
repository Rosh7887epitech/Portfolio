/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** local
*/
#include "my_project.h"

static void sorted_name(path_t **list, path_t *post)
{
    path_t *current = NULL;

    if (*list == NULL || my_strcmp((*list)->value, post->value) > 0) {
        post->next = *list;
        *list = post;
    } else {
        current = *list;
        while (current->next != NULL &&
        my_strcmp(current->next->value, post->value) < 0)
            current = current->next;
        post->next = current->next;
        current->next = post;
    }
}

void sort_name(path_t **list)
{
    path_t *sorted = NULL;
    path_t *next = NULL;
    path_t *current = *list;

    while (current != NULL) {
        next = current->next;
        sorted_name(&sorted, current);
        current = next;
    }
    *list = sorted;
}

static int modify_local(path_t **list, char *value, char *name)
{
    int status = search_list(*list, value);

    if (status == -1) {
        if (name == NULL)
            add_end(list, my_strcat(value, "\t"));
        else
            add_end(list, my_strcat(value, my_strcat("\t", name)));
        return 0;
    }
    if (name == NULL)
        modify_node(*list, my_strcat(value, "\t"), status);
    else
        modify_node(*list, my_strcat(value, my_strcat("\t", name)), status);
    return 0;
}

static int remove_local(path_t **list, char *value)
{
    int status = 0;

    if (!*list || !value)
        return 0;
    status = search_list(*list, value);
    if (status == -1)
        return 0;
    *list = free_pos(*list, value);
    return 0;
}

static int exit_error_set(char *str)
{
    if (is_char_alpha(str[0]) == false)
        my_printerror("set: Variable name must begin with a letter.\n", 1);
    else {
        my_printerror("set: Variable name must contain ", 1);
        my_printerror("alphanumeric characters.\n", 1);
    }
    if (!isatty(STDIN_FILENO))
        exit(1);
    return 1;
}

static int add_in_local(info_t *line, envp_info_t *info)
{
    char *str = my_strdup(line->line_getted) + 4;
    char **array = NULL;
    char **tmp = NULL;

    if (!str)
        return 0;
    array = strtok_with_quotes(str, " ");
    for (int i = 0; array[i]; i++) {
        tmp = strtok_with_quotes(array[i], "=");
        if (is_alphanum(tmp[0]) != 0 || is_char_alpha(tmp[0][0]) == false) {
            info->return_status = exit_error_set(tmp[0]);
            return 0;
        }
        modify_local(&info->local, tmp[0], remove_quotes(tmp[1]));
    }
    ignoreeof_function(info);
    info->return_status = 0;
    return 0;
}

int handle_unset(info_t *line, envp_info_t *info)
{
    char **array = NULL;

    array = strtok_with_quotes(line->line_getted, " ");
    for (int i = 0; array[i]; i++)
        array[i] = remove_quotes(array[i]);
    if (array_size(array) < 2) {
        info->return_status = 1;
        return my_printerror("unset: Too few arguments.\n", 0);
    }
    for (int i = 1; array[i]; i++)
        remove_local(&info->local, array[i]);
    free_array(array);
    info->return_status = 0;
    return 0;
}

int local_functions(info_t *line, envp_info_t *info)
{
    if (my_strncmp(line->line_getted, "set ", 4) == 0) {
        info->status = 1;
        return add_in_local(line, info);
    }
    if (my_strncmp(line->line_getted, "unset", 5) == 0
        && my_strncmp(line->line_getted, "unsetenv", 8) != 0) {
        info->status = 1;
        return handle_unset(line, info);
    }
    if (my_strcmp(line->line_getted, "set") == 0
    && my_strncmp(line->line_getted, "setenv", 6) != 0) {
        sort_name(&info->local);
        print_set_list(info->local, info);
        info->return_status = 0;
        info->status = 1;
        return 0;
    }
    return 1;
}
