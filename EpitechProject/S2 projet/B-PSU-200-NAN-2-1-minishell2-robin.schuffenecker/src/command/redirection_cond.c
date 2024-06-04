/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell2-robin.schuffenecker
** File description:
** redirection_cond
*/

#include "command.h"

static char *search_red(base_t *var, char *com)
{
    char *result = NULL;

    com = clean_line(com);
    var->command = my_str_to_word_array(com, ' ');
    if (nb_of_slash(var->command[0]) < 1 &&
        my_strncmp(com, "./", 2) != 0)
        result = search_command(var, com);
    else
        result = my_strdup(var->command[0]);
    if (result == NULL)
        com = my_strdup(com);
    else {
        result = my_strcat(result, "/");
        com = my_strcat(result, com);
    }
    return com;
}

static void child_cond(base_t *var, int fd, char **com)
{
    fd = open("temp.txt", O_RDONLY);
    dup2(fd, STDIN_FILENO);
    close(fd);
    if (execve(com[0], com, NULL) == -1)
        exit(exec_error(var, com[0]));
}

static int follow_d_left(base_t *var, int fd, char **com)
{
    pid_t pid;
    char *del[] = {"/bin/rm", "temp.txt", NULL};
    int status = 0;

    pid = fork();
    if (pid == 0) {
        child_cond(var, fd, com);
    }
    waitpid(pid, &status, 0);
    if (pid != -1)
        my_re_command(status);
    pid = fork();
    if (pid == 0) {
        execve("/bin/rm", del, var->env);
    }
    waitpid(pid, &status, 0);
    if (pid != -1)
        my_re_command(status);
    return 0;
}

static int d_left_redirection(base_t *var, char **com, char *word)
{
    char *line = NULL;
    size_t len = 0;
    int read;
    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while (read != -1) {
        read = getline(&line, &len, stdin);
        if (my_strncmp(line, word, strlen(word)) == 0)
            break;
        write(fd, line, my_strlen(line));
    }
    close(fd);
    return follow_d_left(var, fd, com);
}

int d_left(base_t *var, char *line, int w)
{
    char *file;
    char **com;

    file = pars_file("<<", line);
    com = pars_com(var, "<<", file, line);
    return d_left_redirection(var, com, file);
}

static char *pars_cond(char **cmd, char *file, int i)
{
    if (cmd[i + 1] != NULL) {
        file = cmd[i + 1];
        return file;
    }
}

char *pars_file(char *sep, char *line)
{
    char **cmd = my_str_to_word_array(line, ' ');
    char *file;

    for (int i = 0; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], sep) == 0)
            file = pars_cond(cmd, file, i);
    }
    return file;
}

char **pars_com(base_t *var, char *sep, char *file, char *line)
{
    char **cmd = my_str_to_word_array(line, ' ');
    char **res = NULL;
    char *new = my_strdup("\0");

    for (int i = 0; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], sep) == 0 || my_strcmp(cmd[i], file) == 0) {
            continue;
        } else {
            new = my_strcat(new, cmd[i]);
            new = my_strcat(new, " ");
        }
    }
    new = clean_line(new);
    res = my_str_to_word_array(new, ' ');
    res[0] = search_red(var, res[0]);
    return res;
}
