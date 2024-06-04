/*
** EPITECH PROJECT, 2024
** parse_redirection.c
** File description:
** that function should handler redirection parsing
*/
#include "my_project.h"
#include <stdlib.h>
#include <stdio.h>

static int redi_len(redirection_t *list)
{
    int longueur = 0;

    while (list != NULL) {
        longueur++;
        list = list->next;
    }
    return longueur;
}

char **redirection_t_array(redirection_t *redi)
{
    int len = redi_len(redi);
    char **array = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; redi; i++) {
        array[i] = my_strdup(redi->redi);
        redi = redi->next;
    }
    array[len] = NULL;
    return array;
}

static redirection_t *node_redirction(char *str)
{
    redirection_t *redi = malloc(sizeof(redirection_t));

    redi->redi = my_strdup(str);
    redi->next = NULL;
    return redi;
}

void add_redi(redirection_t **list, char *str)
{
    redirection_t *current = *list;
    redirection_t *prec = NULL;
    redirection_t *node = node_redirction(str);
    int pos = redi_len(*list);

    if (*list == NULL) {
        *list = node;
        return;
    }
    for (int i = 0; i < pos; i++) {
        prec = current;
        current = current->next;
    }
    prec->next = node;
    node->next = current;
}

static char *separe_redirection(char *new)
{
    int count = 0;

    for (int i = 0; new[i]; i++) {
        if (i > 0 && new[i] == ' ' && (new[i - 1] == '<' || new[i - 1] == '>'))
            count++;
        new[i] = new[i + count];
    }
    return new;
}

static char *add_space(char *str)
{
    char *new = NULL;

    for (int i = 0; str[i]; i++) {
        if ((str[i] == '<' || str[i] == '>')
            && is_pos_in_quotes(str, i) == NO_QUOTES)
            new = my_strcat(new, my_strcat(" ", char_to_str(str[i])));
        else
            new = my_strcat(new, my_strcat("", char_to_str(str[i])));
    }
    clean_esperluette(new);
    for (int i = 0; i < 3; i++)
        new = separe_redirection(new);
    return new;
}

redirection_t *list_redirection(char **array)
{
    redirection_t *redi = NULL;
    char *str = NULL;

    for (int i = 0; array[i]; i++)
        str = my_strcat(str, my_strcat(array[i], " "));
    str = add_space(str);
    array = str_to_word_array(str, " ");
    array = remove_quotes_before_list(array, "<", "<<");
    array = remove_quotes_before_list(array, ">", ">>");
    free(str);
    for (int i = 0; array[i]; i++)
        add_redi(&redi, array[i]);
    return redi;
}

void parse_redirection(redirection_t **redi, redirection_t *other)
{
    redirection_t *cpy = *redi;

    while (cpy) {
        if (is_redirection(cpy->redi) != -1)
            add_redi(&other, cpy->redi);
        cpy = cpy->next;
    }
    *redi = other;
}

void modify_redis(redirection_t **redi)
{
    redirection_t *cpy = *redi;
    redirection_t *other = NULL;

    while (cpy) {
        if (is_injection(cpy->redi) != -1)
            add_redi(&other, cpy->redi);
        cpy = cpy->next;
    }
    cpy = *redi;
    while (cpy) {
        if (is_redirection(cpy->redi) == -1 && is_injection(cpy->redi) == -1)
            add_redi(&other, cpy->redi);
        cpy = cpy->next;
    }
    parse_redirection(redi, other);
}
