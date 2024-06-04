/*
** EPITECH PROJECT, 2024
** backtick.c
** File description:
** that file should handle backtick
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_project.h"

static char *get_all_backtick(FILE *fp)
{
    size_t size = 0;
    char *path = NULL;
    int status = getline(&path, &size, fp);
    char *tab = NULL;

    while (status > 0) {
        clean_esperluette(path);
        if (tab == NULL)
            tab = my_strdup(path);
        else
            tab = my_strcat(my_strcat(tab, " "), path);
        clean_esperluette(tab);
        status = getline(&path, &size, fp);
    }
    return tab;
}

char *extract_backtick(char *command)
{
    FILE *fp;
    char *tab = NULL;

    fp = popen(command, "r");
    if (fp == NULL) {
        my_printerror("Erreur lors de l'ouverture du processus.\n", 1);
        return NULL;
    }
    tab = get_all_backtick(fp);
    pclose(fp);
    return tab;
}

bool there_backtick(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '`' && is_pos_in_quotes(str, i) != SINGLE_QUOTES)
            return true;
    }
    return false;
}

static char **add_tab(int i, char *line, char **tab, int *index)
{
        char *tmp = my_strdup("`");

        for (i = i + 1; line[i] != '\0'; i++) {
            tmp = my_strcat(tmp, char_to_str(line[i]));
            if (line[i] == '`' && is_pos_in_quotes(line, i) != SINGLE_QUOTES)
                break;
        }
        clean_esperluette(tmp);
        if (tab == NULL)
            tab = malloc(sizeof(char *) * 2);
        else
            tab = realloc(tab, sizeof(char *) * (*index + 2));
        tab[*index] = my_strdup(tmp);
        tab[*index + 1] = NULL;
        *index = *index + 1;
        return tab;
}

static char **extract_backtick_from_line(char *line)
{
    char **tab = NULL;
    int index = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '`' && is_pos_in_quotes(line, i) != SINGLE_QUOTES)
            tab = add_tab(i, line, tab, &index);
    }
    return tab;
}

static char *remove_tick_str(char *str)
{
    if (str == NULL)
        return NULL;
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == '`' && is_pos_in_quotes(str, j) != SINGLE_QUOTES)
                str[j] = ' ';
    }
    return str;
}

static void remove_backtick_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i] = remove_tick_str(tab[i]);
        clean_esperluette(tab[i]);
    }
}

static void modify_backtick(char **tab_tick, char *line, envp_info_t *info,
    char *tmp)
{
    for (int i = 0; tab_tick[i] != NULL; i++) {
        if (is_invalid_tick_cmd(tab_tick, i, line, info) == -1)
            continue;
        tmp = extract_backtick(tab_tick[i]);
        tab_tick[i] = my_strcat("`", tab_tick[i]);
        tab_tick[i] = my_strcat(tab_tick[i], "`");
        if (tmp != NULL) {
            clean_esperluette(tab_tick[i]);
            replace_strings(line, tab_tick[i], tmp);
        } else
            replace_strings(line, tab_tick[i], " ");
    }
}

int handle_backtick(char *line, envp_info_t *info)
{
    char *tmp = my_strdup(line);
    char **tab_tick = NULL;

    if (my_strncmp(line, "alias ", 5) == 0)
        return false;
    if (there_backtick(tmp) == false)
        return false;
    if (error_backtick(tmp)) {
        info->return_status = 1;
        return -1;
    }
    tab_tick = extract_backtick_from_line(tmp);
    remove_backtick_tab(tab_tick);
    if (tab_tick == NULL)
        return false;
    modify_backtick(tab_tick, line, info, tmp);
    return true;
}
