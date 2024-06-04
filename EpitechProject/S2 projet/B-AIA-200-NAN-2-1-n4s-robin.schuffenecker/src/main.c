/*
** EPITECH PROJECT, 2024
** n4s_package
** File description:
** main
*/

#include <unistd.h>
#include "my.h"

static void get_speed(char *line, size_t buff)
{
    dprintf(1, "GET_CURRENT_SPEED\n");
    getline(&line, &buff, stdin);
    dprintf(2, line);
}

void cycle_wait(char *line, size_t buff, int cycles)
{
    dprintf(1, "CYCLE_WAIT:%i\n", cycles);
    getline(&line, &buff, stdin);
    read_stdout(line);
    dprintf(2, line);
}

void turn(char *line, size_t buff, float degrees)
{
    dprintf(1, "WHEELS_DIR::%f\n", degrees);
    getline(&line, &buff, stdin);
    read_stdout(line);
    dprintf(2, line);
}

int read_stdout(char *line)
{
    // dprintf(2, "------%s", line);
    if (strstr(line, "Track Cleared")) {
        dprintf(1, "STOP_SIMULATION\n", 1);
        exit(0);
    }
}

int main(void)
{
    char *line = NULL;
    size_t buff;
    info_t *info = malloc(sizeof(info_t));

    start_simulation(line, buff);
    info->speed = 0.35;
    info->continue_while = 0;
    while (1) {
        get_lidar(line, buff, info);
        stay_straight(line, buff, info);
        if (info->continue_while == 1) {
            info->continue_while = 0;
            continue;
        }
    }
    return 0;
}
