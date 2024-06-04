/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell2-robin.schuffenecker
** File description:
** redirection
*/

#include "command.h"

static char **search_red(base_t *var, char **com)
{
    char *result = NULL;

    for (int i = 0; com[i] != NULL; i++) {
        com[i] = clean_line(com[i]);
        var->command = my_str_to_word_array(com[i], ' ');
        if (nb_of_slash(var->command[0]) < 1 &&
            my_strncmp(com[i], "./", 2) != 0)
            result = search_command(var, com[i]);
        else
            result = my_strdup(var->command[0]);
        if (result == NULL)
            com[i] = my_strdup(com[i]);
        else {
            result = my_strcat(result, "/");
            com[i] = my_strcat(result, com[i]);
        }
    }
    return com;
}

static int whos_fd(int fd, int w, char *file)
{
    if (w == 1)
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return 1;
    return fd;
}

static int right_redirection(base_t *var, char **com, char *file, int w)
{
    int fd;
    pid_t pid;
    int status = 0;

    fd = whos_fd(fd, w, file);
    pid = fork();
    if (pid == -1)
        return 1;
    if (pid == 0) {
        if (dup2(fd, STDOUT_FILENO) == -1)
            return 1;
        if (execve(com[0], com, var->env) == -1)
            exit(exec_error(var, com[0]));
    } else {
        if (waitpid(pid, &status, 0) == -1)
            my_re_command(status);
    }
    close(fd);
    return 0;
}

static int left_two_red(base_t *var, int fd, char **com)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == -1)
        return 1;
    if (pid == 0) {
        if (dup2(fd, STDIN_FILENO) == -1)
            return 1;
        if (execve(com[0], com, var->env) == -1)
            exit(exec_error(var, com[0]));
    } else {
        if (waitpid(pid, &status, 0) == -1)
            my_re_command(status);
    }
    close(fd);
    return 0;
}

static int left_redirection(base_t *var, char **com, char *file)
{
    int fd;

    fd = open(file, O_RDONLY, 0644);
    if (fd == -1)
        return 1;
    return left_two_red(var, fd, com);
}

static int right(base_t *var, char *line, int w)
{
    char *file;
    char **com;

    if (w == 1) {
        file = pars_file(">>", line);
        com = pars_com(var, ">>", file, line);
        return right_redirection(var, com, file, w);
    }
    if (w == 3) {
        file = pars_file(">", line);
        com = pars_com(var, ">", file, line);
        return right_redirection(var, com, file, w);
    }
}

static int red_err(char *line)
{
    int g = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '>' || line[i] == '<')
            g = i;
        if ((line[0] == '<' || line[0] == '>') &&
            line[3] != '\0' && nb_of_char(line, ' ') < 2) {
            my_putstr("Invalid null command.\n");
            return 1;
        }
        if (line[g + 1] == '\0' || (line[0] == '<' && line[1] != '\0' &&
            nb_of_char(line, ' ') < 2)) {
            my_putstr("Missing name for redirect.\n");
            return 1;
        }
    }
}

static int pars_red(base_t *var, char *line, int w)
{
    char *file;
    char **com;

    if (red_err(line) == 1)
        return 1;
    if (w == 1 || w == 3)
        return right(var, line, w);
    if (w == 2)
        return d_left(var, line, w);
    if (w == 4) {
        file = pars_file("<", line);
        com = pars_com(var, "<", file, line);
        return left_redirection(var, com, file);
    }
}

int redirection(base_t *var, char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '>' && line[i + 1] == '>')
            return pars_red(var, line, 1);
        if (line[i] == '<' && line[i + 1] == '<')
            return pars_red(var, line, 2);
        if (line[i] == '>')
            return pars_red(var, line, 3);
        if (line[i] == '<')
            return pars_red(var, line, 4);
    }
    return 0;
}
