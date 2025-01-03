/*
** EPITECH PROJECT, 2024
** main
** File description:
** main navy
*/

#include "my.h"

g_t var_sig = {0, 0, 0, 0};

void handler(int signal, siginfo_t *info, void *context)
{
    if (signal == SIGUSR1) {
        var_sig.u1++;
        var_sig.temp = info->si_pid;
    }
    if (signal == SIGUSR2) {
        var_sig.u2++;
    }
}

int signal_me(void)
{
    struct sigaction sg;

    sg.sa_flags = SA_SIGINFO;
    sg.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sg, NULL);
    sigaction(SIGUSR2, &sg, NULL);
    return 0;
}
