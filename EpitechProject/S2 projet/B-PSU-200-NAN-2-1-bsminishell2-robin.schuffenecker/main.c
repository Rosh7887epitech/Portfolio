/*
** EPITECH PROJECT, 2024
** BSminishell1
** File description:
** main
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
    int fd[2];
    char **child = my_str_to_word_array(argv[2]);
    char **parent = my_str_to_word_array(argv[1]);
    pid_t pid;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        execve(child[0], child, env);
    } else {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        execve(parent[0], parent, env);
    }
    return 0;
}
