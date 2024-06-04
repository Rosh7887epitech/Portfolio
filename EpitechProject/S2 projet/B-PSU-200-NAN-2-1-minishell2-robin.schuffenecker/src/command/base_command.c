/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** base_command
*/

#include "command.h"

char *my_prog(base_t *var, char *filepath)
{
    char *prog;

    if (my_strcmp(var->command[0], filepath) != 0) {
        prog = my_strcat("/", var->command[0]);
        prog = my_strcat(filepath, prog);
    } else
        prog = my_strdup(filepath);
    return prog;
}

int my_re_command(int status)
{
    int re = 0;
    char *err;

    if (WIFSIGNALED(status)) {
        err = strsignal(WTERMSIG(status));
        write(2, err, my_strlen(err));
        re = WTERMSIG(status);
        if (WCOREDUMP(status)) {
            write(2, " (core dumped)\n", 15);
            return status;
        }
        write(2, "\n", 1);
        return status;
    }
    return WEXITSTATUS(status);
}

int exec_command(base_t *var, char *line, char *filepath)
{
    int status = 0;
    pid_t pid;
    char *prog;

    prog = my_prog(var, filepath);
    pid = fork();
    if (pid == 0) {
        if (execve(prog, var->command, var->env) == -1) {
            exit(exec_error(var, line));
        }
    }
    pid = wait(&status);
    return my_re_command(status);
}

char *search_dir(base_t *var, int i)
{
    DIR *d = opendir(var->path[i]);
    struct dirent *file;

    if (d == NULL)
        return NULL;
    file = readdir(d);
    while (file != NULL) {
        if (my_strcmp(var->command[0], file->d_name) == 0)
            return var->path[i];
        file = readdir(d);
    }
    closedir(d);
    return NULL;
}

char *search_command(base_t *var, char *line)
{
    int i;
    char *result;

    for (i = 0; var->path[i] != NULL; i++) {
        result = search_dir(var, i);
        if (result != NULL)
            return result;
    }
    return NULL;
}
