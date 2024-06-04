/*
** EPITECH PROJECT, 2024
** alias_looping.
** File description:
** that file should handle alias looping
*/
#include "my_project.h"

static void free_my_tmp_array(char **name2, char **value2)
{
    if (name2)
        free_array(name2);
    if (value2)
        free_array(value2);
}

static bool is_same_name_value(char *name1, char *cmd, char *value1,
    alias_t *alias_value)
{
    char **value2 = my_strtok(alias_value->value, " ");
    char **name2 = my_strtok(alias_value->name, " ");

    if (strcmp(name1, name2[0]) != 0 &&
        (strncmp(cmd, name1, strlen(name1)) == 0
        || strncmp(cmd, name2[0], strlen(name2[0])) == 0)) {
        if (strcmp(name1, value2[0]) == 0 && strcmp(name2[0], value1) == 0) {
            free_my_tmp_array(name2, value2);
            return true;
        }
    }
    free_my_tmp_array(name2, value2);
    return false;
}

static bool analyse_value_loop(alias_t *alias_name, alias_t *alias_value,
    char *command)
{
    char **value1 = my_strtok(alias_name->value, " ");
    char **name1 = my_strtok(alias_name->name, " ");

    while (alias_value) {
        if (is_same_name_value(name1[0], command, value1[0], alias_value)) {
            free_my_tmp_array(name1, value1);
            return true;
        }
        alias_value = alias_value->next;
    }
    free_my_tmp_array(name1, value1);
    return false;
}

bool is_alias_looping(alias_t *alias, char *command)
{
    alias_t *alias_name = alias;
    alias_t *alias_value = alias->next;

    while (alias_name) {
        if (analyse_value_loop(alias_name, alias_value, command))
            return true;
        alias_value = alias_name;
        alias_name = alias_name->next;
    }
    return false;
}
