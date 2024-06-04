/*
** EPITECH PROJECT, 2024
** B-AIA-200-NAN-2-1-n4s-robin.schuffenecker
** File description:
** stat_sim
*/

#include <unistd.h>
#include "my.h"

void start_simulation(char *line, size_t buff)
{
    dprintf(1, "START_SIMULATION\n");
    getline(&line, &buff, stdin);
    read_stdout(line);
    dprintf(2, line);
}

void stop_simulation(char *line, size_t buff)
{
    dprintf(1, "STOP_SIMULATION\n");
    getline(&line, &buff, stdin);
    read_stdout(line);
    dprintf(2, line);
}
