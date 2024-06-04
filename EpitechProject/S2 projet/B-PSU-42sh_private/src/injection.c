/*
** EPITECH PROJECT, 2024
** injection.c
** File description:
** that file should handle injection
*/
#include "my_project.h"
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static int handle_simple_injection(char **array_fct, int status)
{
    int fd = 0;

    if (status == SIMPLE) {
        fd = open(array_fct[0] + 1, O_RDONLY);
        if (fd == -1) {
            my_printerror(array_fct[0] + 1, 84);
            return my_printerror(": No such file or directory.\n", -1);
        }
        dup2(fd, STDIN_FILENO);
        return true;
    }
    return false;
}

static char *handle_double_injection(char **array_fct)
{
    char *line = NULL;
    char *all_line = NULL;
    int end = 1;
    int status = 0;
    size_t len = 0;

    while (end != 0) {
        if (isatty(STDIN_FILENO))
            my_putstr("? ");
        status = getline(&line, &len, stdin);
        if (status < 0)
            return all_line;
        if (line != NULL &&
            my_strcmp(line, my_strcat(array_fct[0] + 2, "\n")) == 0)
            break;
        all_line = my_strcat(all_line, line);
    }
    return all_line;
}

static void write_in_file(char **array_fct, char *tmp)
{
    int fd = open(my_strcat("tests/", array_fct[0] + 2),
        O_WRONLY | O_CREAT | O_TRUNC, 0755);

    write(fd, tmp, my_strlen(tmp));
    close(fd);
}

bool handle_injection(char **array_fct)
{
    int status = is_injection(array_fct[0]);
    char *tmp = NULL;

    status = handle_simple_injection(array_fct, status);
    if (status == -1)
        return false;
    if (status == true)
        return true;
    if (status == DOUBLE) {
        tmp = handle_double_injection(array_fct);
        if (tmp == NULL)
            return true;
        write_in_file(array_fct, tmp);
        handle_simple_injection((char *[]){my_strcat("<tests/",
            array_fct[0] + 2), NULL}, SIMPLE);
        my_exec("/bin/rm", (char *[]){"rm", my_strcat("tests/",
            array_fct[0] + 2), NULL}, NULL, NULL);
        return true;
    }
    return false;
}
