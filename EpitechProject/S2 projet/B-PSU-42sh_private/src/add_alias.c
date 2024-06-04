/*
** EPITECH PROJECT, 2024
** alias.c
** File description:
** that files should handle all aliases
*/

#include "my_project.h"
#include <stdio.h>

static void print_single_alias(char **array, alias_t *alias)
{
    while (alias) {
        if (strncmp(alias->name, array[1], strlen(array[1])) == 0) {
            my_putstr(alias->value);
            my_putchar('\n');
            return;
        }
        alias = alias->next;
    }
}

static bool print_good_alias(char **array, alias_t *alias)
{
    if (array == NULL)
        return true;
    if (array[1] == NULL || array[2] != NULL)
        return false;
    if (array[2] == NULL) {
        print_single_alias(array, alias);
        return true;
    }
    return false;
}

static void modify_execute_status(envp_info_t *envp)
{
    envp->status = 1;
    envp->return_status = 0;
}

static bool handle_print_alias(char *str, alias_t **alias, envp_info_t *info)
{
    alias_t *tmp = NULL;

    if (strcmp(str, "alias") == 0) {
        tmp = *alias;
        print_alias(tmp);
        modify_execute_status(info);
        return true;
    }
    return false;
}

static void concat_and_add(char **array, alias_t **alias)
{
    char *str = NULL;

    if (array == NULL)
        return;
    if (array[1] == NULL || array[2] == NULL)
        return;
    for (int i = 2; array[i]; i++) {
        str = my_strcat(str, my_strcat(" ", array[i]));
    }
    clean_esperluette(str);
    add_alias(alias, array[1], str);
}

bool handle_alias_command(char *str_tmp, alias_t **alias, envp_info_t *info)
{
    char **array = NULL;
    char *str = my_strdup(str_tmp);

    clean_esperluette(str);
    if (handle_print_alias(str, alias, info))
        return true;
    if (strncmp("alias ", str, 6) == 0) {
        array = str_to_word_array(str, " ");
        for (int i = 0; array[i]; i++)
            array[i] = remove_quotes(array[i]);
        for (int i = 0; array[i]; i++)
            clean_esperluette(array[i]);
        modify_execute_status(info);
        if (print_good_alias(array, *alias) && array[2] == NULL)
            return true;
        concat_and_add(array, alias);
        return true;
    }
    return false;
}

char *analyse_each_alias(char *array, alias_t *tmp, int *status)
{
    char **tab_tmp = my_strtok(array, " ");
    char *str = NULL;

    if (tab_tmp == NULL || tab_tmp[0] == NULL)
        return my_strdup(array);
    for (int j = 0; tab_tmp[j]; j++) {
        if (my_strcmp(tab_tmp[j], tmp->name) == 0) {
            *status = 1;
            tab_tmp[j] = my_strdup(tmp->value);
        }
    }
    for (int k = 0; tab_tmp[k]; k++)
        str = my_strcat(str, my_strcat(tab_tmp[k], " "));
    free_array(tab_tmp);
    return my_strdup(str);
}

static int modify_str_alias(char **array, alias_t *tmp, int affect)
{
    int status = affect;

    for (int i = 0; array[i]; i++) {
        if (is_alias_looping(tmp, array[i]))
            return my_printerror("Alias loop.\n", -1);
        clean_esperluette(array[i]);
        array[i] = analyse_each_alias(array[i], tmp, &status);
    }
    return status;
}

static char *concat_str_after_alias(int status, char **array, char *str)
{
    char *str_tmp = NULL;

    if (status == 1) {
        for (int i = 0; array[i]; i++)
            str_tmp = my_strcat(str_tmp, my_strcat(array[i], " "));
        clean_esperluette(str_tmp);
        return my_strdup(str_tmp);
    }
    return my_strdup(str);
}

char *replace_alias_in_str(char *str_tmp, alias_t *alias)
{
    char **array = NULL;
    int status = 0;
    char *tmp = my_strdup(str_tmp);

    clean_esperluette(tmp);
    array = my_strtok(tmp, " ");
    if (array == NULL || !strncmp(tmp, "which", 5) || !strncmp("echo", tmp, 4)
        || !strncmp("alias", tmp, 5) || !strncmp("where", tmp, 5)
            || !strncmp("set", tmp, 3))
        return my_strdup(str_tmp);
    while (alias) {
        status = modify_str_alias(array, alias, status);
        if (status == -1)
            return NULL;
        alias = alias->next;
    }
    return concat_str_after_alias(status, array, str_tmp);
}
