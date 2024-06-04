/*
** EPITECH PROJECT, 2024
** BSminishell1
** File description:
** main
*/

#include "my.h"

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
    }
    return;
}

void child_prog(int status)
{
    my_putstr("Program terminated.");
    my_putstr("\nStatus: ");
    if (WIFEXITED(status) == 0)
        my_putstr("Segmentation fault");
    if (WIFEXITED(status) == 1)
        my_putstr("OK");
    my_putstr("\n");
}

char **disp_info(int argc, char **argv, char **arg, pid_t pid)
{
    arg = my_str_to_word_array(argv[1]);
    my_putstr("Program name: ");
    my_putstr(arg[0]);
    my_putstr("\nNb args: ");
    my_put_nbr(argc);
    my_putstr("\nPID: ");
    my_put_nbr(pid);
    return arg;
}

int main(int argc, char **argv, char **env)
{
    char **arg;
    int status;
    pid_t pid = getpid();
    int pid_c;

    arg = disp_info(argc, argv, arg, pid);
    pid_c = fork();
    if (pid_c != 0) {
        my_putstr("\nCHILD PID: ");
        my_put_nbr(pid_c);
        my_putstr("\n");
    }
    if (pid_c == 0)
        execve(arg[0], arg, arg);
    pid_c = wait(&status);
    child_prog(status);
    return 0;
}
