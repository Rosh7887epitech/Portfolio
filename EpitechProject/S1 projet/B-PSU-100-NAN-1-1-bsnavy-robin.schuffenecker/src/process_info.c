/*
** EPITECH PROJECT, 2023
** main
** File description:
** main graphical
*/

#include "../include/navy.h"

int process_info(char const **argv)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgid(pid);

    my_putstr("PID: ");
    my_put_nbr(pid);
    my_putstr("\n");
    my_putstr("PPID: ");
    my_put_nbr(ppid);
    my_putstr("\n");
    my_putstr("PGID:  ");
    my_put_nbr(pgid);
    my_putstr("\n");
    return 0;
}
