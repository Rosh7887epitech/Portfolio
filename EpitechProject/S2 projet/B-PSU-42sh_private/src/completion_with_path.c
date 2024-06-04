/*
** EPITECH PROJECT, 2024
** completion_with_path.c
** File description:
** that file should handle the auto-completion with path specified
*/
#include "my_project.h"

void clean_term(term_stru_t *term)
{
    for (int i = 0; term->str != NULL && term->str[i] != '\0'; i++)
        my_putstr("\b \b");
}

static char *extract_path_from_str(char *command, int nb_slash)
{
    int counted = 0;
    char *filepath = NULL;

    for (int i = 0; command[i] != '\0' && counted < nb_slash; i++) {
        if (command[i] == '/')
            counted++;
        if (filepath == NULL) {
            filepath = malloc(sizeof(char) * 2);
            filepath[0] = command[i];
            filepath[1] = '\0';
        } else
            filepath = my_strcat(filepath, char_to_str(command[i]));
    }
    return my_strdup(filepath);
}

static char *extract_path(char *command)
{
    int nb_slash = 0;

    if (command == NULL || command[0] == '\0' || command[0] == '\n')
        return NULL;
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '/')
            nb_slash++;
    }
    if (nb_slash == 0)
        return my_strdup(command);
    return extract_path_from_str(command, nb_slash);
}

static bool replce_cmpletion(term_stru_t *term, envp_info_t *info, char *path,
    char **tab)
{
    char *str = NULL;

    for (int i = 0; tab[i + 1] != NULL; i++) {
        if (str == NULL)
            str = my_strdup(tab[i]);
        else
            str = my_strcat(str, my_strcat(" ", tab[i]));
    }
    clean_term(term);
    if (array_size(tab) > 1)
        path = my_strcat(" ", path);
    term->str = my_strcat(my_strcat(str, path), term->tab_cmpletion[0]);
    my_putstr(term->str);
    info->tmp_line[0] = '\0';
    return true;
}

static bool print_path_cmplt(term_stru_t *term, envp_info_t *info, char *path,
    char **tab)
{
    if (array_size(term->tab_cmpletion) == 1)
        return replce_cmpletion(term, info, path, tab);
    else if (array_size(term->tab_cmpletion) == 0) {
        info->tmp_line = NULL;
        return true;
    } else {
        my_putstr("\n");
        print_arg(term->tab_cmpletion);
    }
    return false;
}

bool tabulation_with_path(char **tab, term_stru_t *term, envp_info_t *info)
{
    char *path = NULL;
    char *command = NULL;
    int len = 0;

    if (tab == NULL || tab[0] == NULL)
        return false;
    len = array_size(tab) - 1;
    path = extract_path(tab[len]);
    if (my_strlen(tab[len]) > my_strlen(path))
        command = my_strdup(tab[len] + my_strlen(path));
    if (path == NULL)
        return true;
    add_file_to_tab(command, path, term);
    return print_path_cmplt(term, info, path, tab);
}
