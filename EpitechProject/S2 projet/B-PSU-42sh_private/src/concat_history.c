/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** concat_history
*/

#include "history.h"
#include "my_project.h"

char *tab_elem_line_cat(char **tab_elem_line)
{
    char *result = NULL;

    if (tab_elem_line == NULL)
        return NULL;
    for (int i = 2; tab_elem_line[i] != NULL; i++) {
        result = my_strcat(result, tab_elem_line[i]);
        result = my_strcat(result, " ");
    }
    return result;
}

char *concat_history(char **tab_elem_line, char *str, envp_info_t *envp)
{
    char *concat_history = NULL;
    int fd = 0;
    char *cmd_line_history = NULL;

    fd = open_history_write(envp);
    if (fd == -1)
        return NULL;
    if (str != NULL)
        str = str + 2;
    concat_history = my_strcat(tab_elem_line_cat(tab_elem_line), str);
    concat_history = my_strcat(concat_history, "\n");
    my_putstr(concat_history);
    cmd_line_history = format_line_history(concat_history, envp);
    write(fd, cmd_line_history, my_strlen(cmd_line_history));
    close(fd);
    return concat_history;
}
