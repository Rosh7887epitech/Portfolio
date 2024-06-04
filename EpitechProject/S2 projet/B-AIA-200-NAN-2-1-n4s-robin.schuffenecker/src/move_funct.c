/*
** EPITECH PROJECT, 2024
** B-AIA-200-NAN-2-1-n4s-robin.schuffenecker
** File description:
** move_funct
*/

#include <unistd.h>
#include "my.h"

void move_forward(char *line, size_t buff, float speed)
{
    dprintf(1, "CAR_FORWARD:%f\n", speed);
    getline(&line, &buff, stdin);
    read_stdout(line);
    dprintf(2, line);
}

void move_backwards(char *line, size_t buff, float speed)
{
    dprintf(1, "CAR_BACKWARDS:%f\n", speed);
    getline(&line, &buff, stdin);
    read_stdout(line);
    dprintf(2, line);
}
