/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-bsnavy-robin.schuffenecker
** File description:
** signal_me
*/

#include "../include/navy.h"

int status = 0;
int i = 0;
int j = 0;

void handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
		j++;
	if (signal == SIGQUIT) {
		my_put_nbr(i);
        my_put_nbr (j);
        status = -1;
	}
}

int signal_me(char const **argv)
{
    struct sigaction sg;

    sg.sa_flags = SA_SIGINFO;
    sg.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sg, NULL);
    sigaction(SIGUSR2, &sg, NULL);
    sigaction(SIGQUIT, &sg, NULL);
    return 0;
}

int main(int argc, char const **argv)
{
    signal_me(argv);
    while(status != -1) {
        continue;
    }
	return (0);
}
