/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** that function should be the main of the project
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include "my_project.h"
#include <sys/wait.h>
#include <fcntl.h>

static char *transform_path(char *line, envp_info_t *info)
{
    char *input = my_strdup(line);
    char *env_find = NULL;
    char *fct = NULL;

    input = remove_quotes(input);
    fct = reduce_path(input);
    env_find = find_path(info->l_envp, fct);
    if (!env_find)
        return my_strdup(remove_quotes(line));
    fct = my_strcat(find_path(info->l_envp, fct), my_strcat("/", fct));
    return my_strdup(fct);
}

static void modify_fd(fd_t *fd_file, int i, char ***cmd)
{
    int status = 0;

    if (is_injection(cmd[i][0]) != -1) {
        status = open(cmd[i][0] + 1, O_RDONLY);
        if (status == -1) {
            my_printerror(cmd[i][0] + 1, 0);
            my_printerror(": No such file or directory.\n", 1);
            exit(1);
        }
        dup2(status, STDIN_FILENO);
        cmd[i]++;
    } else
        dup2(fd_file->joind_fd, STDIN_FILENO);
    if ((cmd[i + 1]) != NULL)
        dup2(fd_file->fd[1], STDOUT_FILENO);
    status = is_redirection(cmd[i][array_size(cmd[i]) - 1]);
    if (status != -1)
        redirect_write(cmd[i][array_size(cmd[i]) - 1], status);
    close(fd_file->fd[0]);
    close(fd_file->fd[1]);
}

static char **command_array(char **command)
{
    char **command_without = array_cpy(command);

    for (int i = 0; command_without[i]; i++) {
        if (command_without[i][0] == '>')
            command_without[i] = NULL;
    }
    return command_without;
}

static void my_pipe_execute_buildin(char ***cmd, int index, envp_info_t *info,
    bool is_pipe)
{
    char *str = NULL;
    info_t line;
    int status = 0;

    if (is_buildin(cmd[index][0])) {
        for (int i = 0; cmd[index][i]; i++)
            str = my_strcat(str, my_strcat(cmd[index][i], " "));
        clean_esperluette(str);
        line.line_getted = my_strdup(str);
        status = my_build_in(&line, info);
        info->return_status = status;
        if (is_pipe)
            exit(status);
    }
    if (is_pipe)
        exit(1);
}

static int my_pipe_execute(fd_t *file, int index, char ***cmd,
    envp_info_t *info)
{
    int status = 0;
    char *tmp = NULL;
    int pid = fork();

    if (pid == -1)
        return my_printerror("Error FORK\n", -1);
    if (pid == 0) {
        modify_fd(file, index, cmd);
        if (!is_buildin(cmd[index][0])) {
            tmp = transform_path(remove_quotes(cmd[index][0]), info);
            execve(tmp, command_array(rm_quotes_tab(cmd[index])), info->envp);
            free(tmp);
            access_to_file(cmd[index][0]);
        }
        my_pipe_execute_buildin(cmd, index, info, true);
    }
    wait_my_pid(cmd, index, pid, &status);
    close(file->fd[1]);
    file->joind_fd = file->fd[0];
    return segfault_handling(status);
}

// fd[0] == read, fd[1] == write
// fd[0] == STDIN_FILENO, fd[1] == STDOUT_FILENO
static void execute_pipe(char ***cmd, envp_info_t *info)
{
    int fd[2];
    int join_fd = dup(STDIN_FILENO);
    fd_t file_des = {fd, join_fd};

    for (int i = 0; cmd[i] != NULL; i++) {
        pipe(file_des.fd);
        info->return_status = my_pipe_execute(&file_des, i, cmd, info);
        if (info->return_status != 0)
            return;
    }
}

static char ***tab_command_from_line(char *str)
{
    char **array = strtok_with_quotes(str, "|");
    char **tmp_array = NULL;
    char ***tab = NULL;
    int count = array_size(array);

    tab = malloc(sizeof(char **) * (count + 1));
    for (count = 0; array[count]; count++) {
        clean_esperluette(array[count]);
        tmp_array = strtok_with_quotes(array[count], " ");
        for (int i = 0; tmp_array[i]; i++)
            clean_str(tmp_array[i]);
        tab[count] = array_cpy(tmp_array);
        free_array(tmp_array);
    }
    tab[count] = NULL;
    free_array(array);
    return tab;
}

static bool is_good_pipe(char *str)
{
    if (str[0] == '|')
        return my_printerror("Invalid null command.\n", false);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '|' && str[i + 1] == '\0')
            return my_printerror("Invalid null command.\n", false);
    }
    return true;
}

static void free_char_3d_array(char ***arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != NULL; j++)
            free(arr[i][j]);
        free(arr[i]);
    }
    free(arr);
}

bool make_pipe(char *line, envp_info_t *info)
{
    char ***command = NULL;

    clean_str(line);
    if (!is_good_pipe(line)) {
        info->return_status = 1;
        return false;
    }
    command = tab_command_from_line(line);
    if (!check_commands(command)) {
        free_char_3d_array(command);
        info->return_status = 1;
        return false;
    } else {
        if (execute_pipe_last_buildin(command, info))
            return true;
        execute_pipe(command, info);
        error_injection(command, info);
        free_char_3d_array(command);
        return true;
    }
}
