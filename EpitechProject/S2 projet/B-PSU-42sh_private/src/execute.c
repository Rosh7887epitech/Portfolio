/*
** EPITECH PROJECT, 2024
** execute.c
** File description:
** that function should execute the commande and return the good think
*/

#include <sys/wait.h>
#include "../include/my_project.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void access_to_file(char *filename)
{
    if (errno == ENOEXEC) {
        my_printerror(filename, 1);
        my_printerror(": Exec format error. Wrong Architecture.\n", 1);
        return;
    }
    if (access(filename, F_OK) != -1) {
        my_printerror(filename, 1);
        my_printerror(": Permission denied.\n", 1);
    } else {
        my_printerror(filename, 1);
        my_printerror(": Command not found.\n", 1);
    }
}

int segfault_handling(int status)
{
    char *str = NULL;

    if (!WIFEXITED(status)) {
        str = strsignal(WTERMSIG(status));
        if (my_strncmp(str, "Floating point exception", 24) == 0)
            my_printerror("Floating exception", status);
        else
            my_printerror(str, status);
        if (WCOREDUMP(status)) {
            my_printerror(" (core dumped)", status);
            return my_printerror("\n", status);
        }
        return my_printerror("\n", status + 128);
    }
    return WEXITSTATUS(status);
}

static char *extract_function_from_path(char *str)
{
    for (int i = my_strlen(str); i > 0; i--) {
        if (str[i] == '/') {
            str[i] = '\0';
            break;
        }
        str[i] = '\0';
    }
    return str;
}

static int is_file_existing(char *filepath, char *function)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;

    dir = opendir(extract_function_from_path(my_strdup(filepath)));
    if (dir == NULL)
        return 1;
    entry = readdir(dir);
    while (entry != NULL) {
        if (my_strcmp(entry->d_name, function) == 0)
            return 0;
        entry = readdir(dir);
    }
    my_printerror(my_strcat("./", function), 1);
    return my_printerror(": Command not found.\n", 1);
}

char *reduce_path(char *line)
{
    int count = 0;
    int index = 0;

    if (line == NULL)
        return NULL;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '/')
            count++;
    }
    if (count == 0)
        return my_strdup(line);
    for (index = 0; line[index] != '\0' && count > 0; index++) {
        if (line[index] == '/')
            count--;
    }
    return line + index;
}

int is_reg_file(char *filepath, char *function)
{
    struct stat sb;
    int file_exi = is_file_existing(filepath, function);

    if (file_exi != 0)
        return 1;
    stat(function, &sb);
    if (S_ISDIR(sb.st_mode)) {
        my_printerror(my_strcat("./", function), 1);
        return my_printerror(": Permission denied.\n", 1);
    }
    if (!access(filepath, X_OK))
        return 0;
    my_printerror(my_strcat("./", function), 1);
    return my_printerror(": Permission denied.\n", 1);
}

static void redirection_in_file(char *filename)
{
    int fd = 0;

    if (filename[0] != '>') {
        filename = remove_quotes(filename);
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0755);
    } else {
        filename = remove_quotes(filename);
        fd = open(filename + 1, O_WRONLY | O_CREAT | O_APPEND, 0755);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

int my_exec(char *filepath, char **argu, char **envp, char *filename)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == -1)
        return my_printerror("Error FORK\n", 84);
    if (pid == 0) {
        if (filename != NULL)
            redirection_in_file(filename);
        execve(filepath, argu, envp);
        access_to_file(filepath);
        exit(1);
    }
    waitpid(pid, &status, 0);
    return segfault_handling(status);
}
