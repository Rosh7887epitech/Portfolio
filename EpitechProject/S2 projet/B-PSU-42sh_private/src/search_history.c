/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** search_history
*/

#include "history.h"
#include "my_project.h"

int found_cmd(int fd, char **tab_elem_line, envp_info_t *info)
{
    char *cmd_line_history = NULL;

    if (tab_elem_line == NULL || info == NULL)
        return -1;
    delete_line_f(tab_elem_line[0], fd, info);
    cmd_line_history = format_line_history(tab_elem_line[2], info);
    if (cmd_line_history == NULL)
        return -1;
    write(fd, cmd_line_history, my_strlen(cmd_line_history));
    my_putstr(my_strcat(tab_elem_line[2], "\n"));
    close(fd);
    return 0;
}

char *search_cmd_in_history(char *data, char *search, envp_info_t *info)
{
    char **tab_line = NULL;
    char **tab_elem_line = NULL;
    int fd = 0;

    if (data == NULL || search == NULL || info == NULL)
        return NULL;
    fd = open_history_write(info);
    if (fd == -1)
        return NULL;
    tab_line = my_strtok(data, "\n");
    for (int i = 0; tab_line[i] != NULL; i++) {
        tab_elem_line = my_strtok(tab_line[i], " ");
        if (my_strcmp(search, tab_elem_line[2]) == 0 && fd != -1 &&
            found_cmd(fd, tab_elem_line, info) != -1) {
            close(fd);
            return tab_elem_line[2];
        }
    }
    close(fd);
    return NULL;
}

int element_found(char *cmd_line_history, char **tab_elem_line,
    envp_info_t *info)
{
    int fd = open_history_write(info);

    if (fd == -1)
        return -1;
    if (delete_line_f(tab_elem_line[0], fd, info) != -1) {
        cmd_line_history = format_line_history(tab_elem_line[2], info);
        write(fd, cmd_line_history, my_strlen(cmd_line_history));
        my_putstr(my_strcat(tab_elem_line[2], "\n"));
        close(fd);
        return 0;
    } else {
        close(fd);
        return -1;
    }
}

char *search_nb_in_history(char *data, char *search, envp_info_t *info)
{
    char **tab_line = NULL;
    char **tab_elem_line = NULL;
    char *cmd_line_history = NULL;

    if (data == NULL || search == NULL)
        return NULL;
    tab_line = my_strtok(data, "\n");
    for (int i = 0; tab_line[i] != NULL; i++) {
        tab_elem_line = my_strtok(tab_line[i], " ");
        if (my_strcmp(search, tab_elem_line[0]) == 0) {
            element_found(cmd_line_history, tab_elem_line, info);
            return tab_elem_line[2];
        }
    }
    write(2, search, my_strlen(search));
    write(2, ": Event not found.\n", 19);
    info->return_status = 1;
    return NULL;
}

char *search_last_cmd_in_history(char *data, info_t *line, envp_info_t *info)
{
    char **tab_line = NULL;
    char **tab_elem_line = NULL;
    char *cmd_line_history = NULL;
    char **array = my_strtok(line->line_getted, "!");

    clean_str(line->line_getted);
    if (data == NULL || array == NULL)
        return NULL;
    tab_line = my_strtok(data, "\n");
    for (int i = 0; tab_line[i] != NULL; i++) {
        tab_elem_line = my_strtok(tab_line[i], " ");
        if (array[0] != NULL && tab_line[i + 1] == NULL)
            return concat_history(tab_elem_line, line->line_getted, info);
        if (tab_line[i + 1] == NULL) {
            element_found(cmd_line_history, tab_elem_line, info);
            return tab_elem_line[2];
        }
    }
    return NULL;
}
