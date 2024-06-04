/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** my_delete_line_in_tab
*/

#include "history.h"
#include "my_project.h"

int search(char **tab, char *searched)
{
    if (tab == NULL || searched == NULL)
        return -1;
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(searched, tab[i], my_strlen(searched)) == 0) {
            return i;
        }
    }
    return -1;
}

char **shift_line_in_tab(int pos, char **tab)
{
    free(tab[pos]);
    for (int i = pos; tab[i] != NULL; i++) {
        if (tab[i + 1] != NULL)
            tab[i] = my_strdup(tab[i + 1]);
        else
            tab[i] = NULL;
    }
    return tab;
}

char **my_delete_line_in_tab(char **tab, char *searched)
{
    int pos = 0;

    if (search(tab, searched) != -1)
        pos = search(tab, searched);
    tab = shift_line_in_tab(pos, tab);
    return tab;
}
