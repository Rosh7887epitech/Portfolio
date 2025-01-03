/*
** EPITECH PROJECT, 2024
** p1
** File description:
** p1
*/

#include "my.h"
#include <unistd.h>

int cond_letter(base_t *var, char *line, int i)
{
    if (line[i] >= 73 || line[i] <= 64)
        return -1;
    else
        return line[i] - 'A' + 1;
}

int search_letter(base_t *var, char *line)
{
    int h = 0;

    h = cond_letter(var, line, 0);
    if (h == -1)
        return -1;
    else
        return h;
}

int recup_pos_one(base_t *var, char *line)
{
    int py = line[1] - '0';
    int px = search_letter(var, line);

    var->x = px;
    var->y = py;
    for (int i = 0; i < py; i++) {
        kill(var->pid_two, SIGUSR1);
        usleep(1000);
    }
    kill(var->pid_two, SIGUSR2);
    usleep(1000);
    for (int i = 0; i < px; i++) {
        kill(var->pid_two, SIGUSR1);
        usleep(1000);
    }
    kill(var->pid_two, SIGUSR2);
}

int loop_one(base_t *var)
{
    var_sig.bol = 0;
    while (var_sig.bol != 1 || var_sig.bol != 2) {
        display_map_pone(var);
        if (attack_one(var) == 84)
            return 84;
        defense_one(var);
        verif_map(var);
        verif_map_two(var);
        if (var_sig.bol == 1)
            return 1;
        if (var_sig.bol == 2)
            return 0;
    }
}

static int error_case(base_t *var, pid_t pid_one, char **argv)
{
    if (filereader(var, argv[1]) == 84)
        return 84;
    if (pid_one <= 100)
        return 84;
    signal_me();
    if (load_boat_one(var) == 84)
        return 84;
}

static int end_cond(int r)
{
    if (r == 1)
        my_putstr("\nI won\n");
    if (r == 0)
        my_putstr("\nEnemy won\n");
    if (r == 84)
        return 84;
    return 0;
}

int player_one(int argc, char **argv, base_t *var)
{
    pid_t pid_one = getpid();
    int r = 0;

    if (error_case(var, pid_one, argv) == 84)
        return 84;
    my_putstr("my_pid: ");
    my_put_nbr(pid_one);
    my_putstr("\n\nwaiting for enemy...\n");
    pause();
    var->pid_two = var_sig.temp;
    if (var_sig.u1 == 1) {
        kill(var->pid_two, SIGUSR1);
        my_putstr("\nenemy connected\n");
        var_sig.u1 = 0;
    }
    r = loop_one(var);
    if (end_cond(r) == 84)
        return 84;
    return 0;
}
