/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell2-robin.schuffenecker
** File description:
** separator
*/

#include "command.h"

static int is_myco(char *com)
{
    if (my_strcmp(com, "env") == 0 ||
        my_strcmp(com, "setenv") == 0 ||
        my_strcmp(com, "unsetenv") == 0 ||
        my_strcmp(com, "cd") == 0)
        return 1;
    return 0;
}

static void redirect_input(int i, int temp, int fd[])
{
    if (i != 0) {
        dup2(temp, STDIN_FILENO);
        close(temp);
    }
}

static void redirect_output(int i, int size, int fd[], int temp)
{
    if (i != size - 1) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
    }
}

static void redirect_exec(base_t *var, int i, char ***child)
{
    if (is_myco(child[i][0]) == 1) {
        my_put_command(var, child[i][0]);
        exit(0);
    } else {
        if (execve(child[i][0], child[i], NULL) == -1)
            exit(exec_error(var, child[i][0]));
    }
}

static int parent_redirect(int temp, int fd[])
{
    if (temp != -1)
        close(temp);
    close(fd[1]);
    temp = fd[0];
    return temp;
}

static void pipe_wait(int status, pid_t pid, int i, int size)
{
    if (i == size - 1) {
        waitpid(pid, &status, 0);
        if (pid != -1)
            my_re_command(status);
    }
}

static int pipe_loop(base_t *var, char ***child, int size)
{
    int fd[2];
    pid_t pid;
    int status = 0;
    int temp = -1;

    for (int i = 0; i < size; i++) {
        pipe(fd);
        pid = fork();
        if (my_strcmp(child[i][0], "/usr/bin/env") == 0)
            child[i][0] = my_strdup("env");
        if (pid == 0) {
            redirect_input(i, temp, fd);
            redirect_output(i, size, fd, temp);
            redirect_exec(var, i, child);
        }
        temp = parent_redirect(temp, fd);
        pipe_wait(status, pid, i, size);
    }
    return 0;
}

static char ***alloc_triple_arr(char **com, int size)
{
    char ***child = NULL;

    child = malloc(sizeof(char **) * size);
    if (child == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        child[i] = my_str_to_word_array(com[i], ' ');
        if (child[i] == NULL)
            return NULL;
    }
    child[size] = NULL;
    return child;
}

int pipe_exec(base_t *var, char *line)
{
    int size = 0;
    char **com = my_str_to_word_array(line, '|');
    char ***child = NULL;

    if (pipe_err(line) == 1)
        return 1;
    com = search_pipe(var, com);
    for (size; com[size] != NULL; size++);
    child = alloc_triple_arr(com, size);
    if (child == NULL)
        return 1;
    return pipe_loop(var, child, size);
}

int sep_exec(base_t *var, char *line)
{
    char **com = my_str_to_word_array(line, ';');
    int res = 0;

    for (int i = 0; com[i] != NULL; i++) {
        res = cond_loop(var, com[i], res);
        var->status = 0;
        var->exit = res;
    }
    return res;
}
