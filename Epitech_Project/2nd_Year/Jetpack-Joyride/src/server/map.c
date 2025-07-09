/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** map
*/
#include "my.h"

char **copy_map(char **map)
{
    char **copy = NULL;
    int i = 0;

    if (map == NULL)
        return NULL;
    while (map[i] != NULL)
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++)
        copy[j] = my_strdup(map[j]);
    copy[i] = NULL;
    return copy;
}

static void count_map_dimensions(char *map_str, int *rows, int *cols)
{
    *rows = 0;
    *cols = 0;
    if (map_str == NULL)
        exit(84);
    for (int i = 0; map_str[i] != '\0'; i++) {
        if (map_str[i] == '\n')
            (*rows)++;
        if (*cols == 0 && map_str[i] == '\n')
            *cols = i;
    }
}

void parse_map(char *map_str, server_t *server_info)
{
    int rows = 0;
    int cols = 0;
    int i = 0;
    char *line = NULL;

    count_map_dimensions(map_str, &rows, &cols);
    server_info->map = malloc(sizeof(char *) * (rows + 1));
    if (!server_info->map)
        exit(84);
    line = strtok(map_str, "\n");
    while (i < rows && line) {
        server_info->map[i] = my_strdup(line);
        if (!server_info->map[i])
            exit(84);
        line = strtok(NULL, "\n");
        i++;
    }
    server_info->map[rows] = NULL;
    free(map_str);
}

static char *append_line(char *buffer, char *line, size_t *total)
{
    char *tmp = NULL;
    size_t len = strlen(line);

    tmp = realloc(buffer, *total + len + 1);
    if (!tmp)
        exit(84);
    buffer = tmp;
    memcpy(buffer + *total, line, len);
    *total += len;
    buffer[*total] = '\0';
    return buffer;
}

char *get_map_str(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    char *buffer = NULL;
    size_t len = 0;
    size_t total = 0;

    if (!file) {
        perror(filepath);
        free(filepath);
        exit(84);
    }
    while (getline(&line, &len, file) != -1) {
        if (line[0] == '\n')
            continue;
        buffer = append_line(buffer, line, &total);
    }
    free(line);
    fclose(file);
    return buffer;
}
