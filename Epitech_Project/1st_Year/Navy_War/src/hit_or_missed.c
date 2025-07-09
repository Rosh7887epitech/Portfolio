/*
** EPITECH PROJECT, 2024
** hit
** File description:
** missed
*/

#include "my.h"

int ping_two(base_t *var, int x, int y)
{
    if (hit_boat_two(var, x, y) == 1) {
        my_putstr(":hit\n");
        kill(var->pid_one, SIGUSR1);
        usleep(200);
        kill(var->pid_one, SIGUSR2);
        usleep(200);
    } else {
        my_putstr(":missed\n");
        kill(var->pid_one, SIGUSR1);
        usleep(200);
        kill(var->pid_one, SIGUSR1);
        usleep(200);
        kill(var->pid_one, SIGUSR2);
        usleep(200);
    }
    var_sig.u1 = 0;
}

int ping_one(base_t *var, int x, int y)
{
    if (hit_boat(var, x, y) == 1) {
        my_putstr(":hit\n");
        kill(var->pid_two, SIGUSR1);
        usleep(200);
        kill(var->pid_two, SIGUSR2);
        usleep(200);
    } else {
        my_putstr(":missed\n");
        kill(var->pid_two, SIGUSR1);
        usleep(200);
        kill(var->pid_two, SIGUSR1);
        usleep(200);
        kill(var->pid_two, SIGUSR2);
        usleep(200);
    }
    var_sig.u1 = 0;
}

int h_or_m_two(base_t *var, char *line)
{
    int result = 0;
    char *pos = my_strdup(line);

    pos[2] = '\0';
    result = receive_sig();
    if (result == 1) {
        my_putstr("\nresult: ");
        my_putstr(pos);
        my_putstr(":hit\n");
        var->map_pone[var->y + 1][var->x * 2] = 'x';
        result = 0;
    }
    if (result == 2) {
        my_putstr("\nresult: ");
        my_putstr(pos);
        my_putstr(":missed\n");
        var->map_pone[var->y + 1][var->x * 2] = 'o';
        result = 0;
    }
}

int h_or_m_one(base_t *var, char *line)
{
    int result = 0;
    char *pos = my_strdup(line);

    pos[2] = '\0';
    result = receive_sig();
    if (result == 1) {
        my_putstr("\nresult: ");
        my_putstr(pos);
        my_putstr(":hit\n");
        var->map_ptwo[var->y + 1][var->x * 2] = 'x';
        result = 0;
    }
    if (result == 2) {
        my_putstr("\nresult: ");
        my_putstr(pos);
        my_putstr(":missed\n");
        var->map_ptwo[var->y + 1][var->x * 2] = 'o';
        result = 0;
    }
}
