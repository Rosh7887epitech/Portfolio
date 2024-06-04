/*
** EPITECH PROJECT, 2024
** create_alias.c
** File description:
** that file should handle the creation of alias
*/
#include "my_project.h"
#include <stdlib.h>

static alias_t *create_alias(char *name, char *value)
{
    alias_t *new = malloc(sizeof(alias_t));

    if (name != NULL)
        new->name = my_strdup(name);
    else
        new->name = NULL;
    if (value != NULL)
        new->value = my_strdup(value);
    else if (name != NULL)
        new->value = my_strdup(name);
    else
        new->value = my_strdup("error");
    new->next = NULL;
    return new;
}

static bool is_already_alias(alias_t *alias, char *name, char *value)
{
    while (alias) {
        if (my_strcmp(alias->name, name) == 0 && value == NULL) {
            alias->value = my_strdup(name);
            return true;
        }
        if (my_strcmp(alias->name, name) == 0) {
            alias->value = my_strdup(value);
            return true;
        }
        alias = alias->next;
    }
    return false;
}

void add_alias(alias_t **alias, char *name, char *value)
{
    alias_t *new = NULL;

    if (name != NULL)
        if (is_already_alias(*alias, name, value))
            return;
    new = create_alias(name, value);
    if (*alias == NULL)
        *alias = new;
    else {
        new->next = *alias;
        *alias = new;
    }
}
