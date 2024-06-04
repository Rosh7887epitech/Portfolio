/*
** EPITECH PROJECT, 2024
** B-PSU-MIRROR-42
** File description:
** count
*/

#include "history.h"
#include "my_project.h"

int nb_line_of_array(char **line_array)
{
    int i = 0;

    if (line_array == NULL)
        return -1;
    for (; line_array[i] != NULL; i++);
    return i;
}

int count_line_file(char *file_data)
{
    int nbr = 0;

    if (file_data == NULL)
        return -1;
    for (int i = 0; file_data[i] != '\0'; i++) {
        if (file_data[i] == '\n')
            nbr++;
    }
    return nbr;
}

int nb_command_line(char *file_data)
{
    int nbr = 0;
    char **array_of_data = NULL;
    char **line_of_data = NULL;

    if (file_data == NULL)
        return -1;
    array_of_data = my_strtok(file_data, "\n");
    if (array_of_data == NULL || array_of_data[0] == NULL)
        return 0;
    for (int i = 0; array_of_data[i] != NULL; i++) {
        line_of_data = my_strtok(array_of_data[i], " ");
        if (array_of_data[i + 1] == NULL && is_number(line_of_data[0]) != -1) {
            nbr = atoi(line_of_data[0]);
            nbr++;
            return nbr;
        }
    }
    return -1;
}
