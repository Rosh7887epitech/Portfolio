/*
** EPITECH PROJECT, 2024
** navy
** File description:
** navy
*/

#pragma once

    #include "my.h"
    #include "include.h"
    #include <signal.h>

int process_info(char const **argv);
int kill_it(char const **argv);
int signal_me(char const **argv);
int who_sig_me(char const **argv);
void handler(int signal, siginfo_t *info, void *context);

