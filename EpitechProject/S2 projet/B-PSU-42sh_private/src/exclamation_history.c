/*
** EPITECH PROJECT, 2024
** B-PSU-MIRROR-42
** File description:
** exclamation_history
*/

#include "history.h"
#include "my_project.h"

int delete_line_f(char *str, int fd, envp_info_t *info)
{
    char *data = get_data_file(info);
    char **data_array = NULL;
    char **cpy = NULL;

    if (data == NULL || info == NULL)
        return -1;
    data_array = my_strtok(data, "\n");
    cpy = my_delete_line_in_tab(data_array, str);
    fd = open_history_write(info);
    if (fd != -1) {
        for (int i = 0; cpy[i] != NULL; i++) {
            write(fd, cpy[i], my_strlen(cpy[i]));
            write(fd, "\n", 1);
        }
    }
    return 0;
}

int multiple_excla(char *str)
{
    if (str == NULL)
        return 1;
    if ((str[0] == '!' && str[1] != '\0') && str[1] == '!')
        return 0;
    return 1;
}

int is_number(char *line)
{
    if (line == NULL)
        return -1;
    for (int i = 0; line[i] != '\0'; i++) {
        if ((line[i] < '0' || line[i] > '9'))
            return -1;
    }
    return 0;
}

bool is_exclamation(char *line)
{
    if (line == NULL)
        return false;
    if (line[0] == '!')
        return true;
    return false;
}

static int check_error_exclamation(char *line)
{
    if (line != NULL) {
        if (line[1] == '\0' || line[1] == ' ') {
            write(2, "!: Command not found.\n", 22);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int execute_exclamation(info_t *line, envp_info_t *info)
{
    char *data = get_data_file(info);
    char **data_array = NULL;

    if (data == NULL || line->line_getted == NULL || info == NULL)
        return 1;
    clean_esperluette(line->line_getted);
    data_array = my_strtok(line->line_getted, "!");
    if (check_error_exclamation(line->line_getted) == EXIT_FAILURE)
        return -1;
    if (multiple_excla(line->line_getted) == 0) {
        line->line_getted = search_last_cmd_in_history(data, line, info);
        return 0;
    }
    if (is_number(data_array[0]) == -1)
        line->line_getted = search_cmd_in_history(data, data_array[0], info);
    else
        line->line_getted = search_nb_in_history(data, data_array[0], info);
    if (line->line_getted != NULL)
        our_sh(line, info, my_strlen(line->line_getted));
    return 0;
}
