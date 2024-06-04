/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-bsnavy-robin.schuffenecker
** File description:
** who_sig_me
*/

#include "../include/navy.h"

int who_sig_me(char const **argv)
{
    int usr1 = my_getnbr(argv[1]);
    int usr2 = my_getnbr(argv[2]);
    struct sigaction sg;

    sg.sa_flags = SA_SIGINFO;
    sg.sa_sigaction = &handler;
    sigaction(usr1, &sg, NULL);
    sigaction(usr2, &sg, NULL);
    while(1);
    return 0;
}