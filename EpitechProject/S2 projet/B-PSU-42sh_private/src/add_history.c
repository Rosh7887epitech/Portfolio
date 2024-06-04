/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** add_history
*/

#include "history.h"
#include "my_project.h"

char *format_line_history(char *str, envp_info_t *envp)
{
    char *formated_line = NULL;
    int nb_of_the_line = nb_command_line(get_data_file(envp));
    char **hour_min = NULL;
    time_t temps = time(&temps);

    if (str == NULL || strcmp(str, "\n") == 0 ||
        (str[0] == '!' && str[1] != ' ') || nb_of_the_line == -1)
        return NULL;
    clean_esperluette(str);
    hour_min = my_strtok(ctime(&temps), " :");
    formated_line = my_strcat(formated_line, my_itoa(nb_of_the_line));
    formated_line = my_strcat(formated_line, "  ");
    formated_line = my_strcat(formated_line, hour_min[3]);
    formated_line = my_strcat(formated_line, ":");
    formated_line = my_strcat(formated_line, hour_min[4]);
    formated_line = my_strcat(formated_line, "    ");
    formated_line = my_strcat(formated_line, str);
    formated_line = my_strcat(formated_line, "\n");
    return formated_line;
}

void add_history(char *tmp, envp_info_t *envp)
{
    char *line = my_strdup(tmp);
    char *cmd_line_history = NULL;
    int fd = open_history_write(envp);

    if (fd == -1 || my_strncmp(line, "history", 7) == 0) {
        envp->return_status = 0;
        return;
    }
    cmd_line_history = format_line_history(line, envp);
    if (cmd_line_history != NULL)
        write(fd, cmd_line_history, my_strlen(cmd_line_history));
    close(fd);
}
