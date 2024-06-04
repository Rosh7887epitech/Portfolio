/*
** EPITECH PROJECT, 2024
** perm_alias.c
** File description:
** that file should handle perm aliases
*/
#include "my_project.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

static char *read_from_rc(char *filepath)
{
    int fd = open(filepath, O_RDONLY | O_CREAT, 0755);
    struct stat sb;
    ssize_t read_size = 0;
    char *buffer = NULL;

    if (fd == -1)
        return NULL;
    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    read_size = read(fd, buffer, sb.st_size);
    if (read_size == -1)
        return NULL;
    buffer[sb.st_size] = '\0';
    if (buffer[sb.st_size - 1] != '\n')
        buffer = my_strcat(buffer, "\n");
    close(fd);
    return buffer;
}

static int count_line_without_comment(char **array)
{
    int line = 0;

    for (int i = 0; array[i]; i++) {
        if (array[i][0] != '#')
            line++;
    }
    return line;
}

static char **remove_comment(char **array)
{
    int size = count_line_without_comment(array);
    char **new_array = malloc(sizeof(char *) * (size + 1));
    int index = 0;

    for (int i = 0; array[i]; i++) {
        if (array[i][0] != '#') {
            new_array[index] = my_strdup(array[i]);
            index++;
        }
    }
    new_array[size] = NULL;
    free_array(array);
    return new_array;
}

// line : 74 :::::: check_inhibitors(&line);
static void add_to_list_from_file(char **array, alias_t **alias,
    envp_info_t *info)
{
    info_t line;

    line.line_getted = NULL;
    for (int i = 0; array[i]; i++) {
        if (my_strncmp(array[i], "alias ", 6) == 0) {
            clean_str(array[i]);
            line.line_getted = my_strdup(array[i]);
            handle_alias_command(line.line_getted, alias, info);
        }
        if (line.line_getted != NULL)
            free(line.line_getted);
    }
}

alias_t *add_alias_from_rc(envp_info_t *info)
{
    alias_t *alias = NULL;
    char *path = find_in_envp(info->l_envp, "HOME=", 5);
    char *buffer = NULL;
    char **array = NULL;

    if (path == NULL)
        return NULL;
    path = my_strcat(path + 5, "/.42shrc");
    buffer = read_from_rc(path);
    if (buffer == NULL)
        return NULL;
    array = my_strtok(buffer, "\n");
    if (array == NULL)
        return NULL;
    array = remove_comment(array);
    if (array == NULL)
        return NULL;
    add_to_list_from_file(array, &alias, info);
    free_array(array);
    return alias;
}

void print_alias(alias_t *alias)
{
    while (alias) {
        my_putstr(alias->name);
        my_putstr("\t");
        my_putstr(alias->value);
        my_putstr("\n");
        alias = alias->next;
    }
}
