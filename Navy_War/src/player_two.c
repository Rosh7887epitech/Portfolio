/*
** EPITECH PROJECT, 2024
** p2
** File description:
** p2
*/

#include "my.h"

char conv_letter(base_t *var, int i)
{
    if (i == 1)
        return 'A';
    if (i == 2)
        return 'B';
    if (i == 3)
        return 'C';
    if (i == 4)
        return 'D';
    if (i == 5)
        return 'E';
    if (i == 6)
        return 'F';
    if (i == 7)
        return 'G';
    if (i == 8)
        return 'H';
    if (i >= 9)
        return 'P';
}

int recup_pos_two(base_t *var, char *line)
{
    int py = line[1] - '0';
    int px = search_letter(var, line);

    var->x = px;
    var->y = py;
    for (int i = 0; i < py; i++) {
        kill(var->pid_one, SIGUSR1);
        usleep(1000);
    }
    kill(var->pid_one, SIGUSR2);
    usleep(1000);
    for (int i = 0; i < px; i++) {
        kill(var->pid_one, SIGUSR1);
        usleep(1000);
    }
    kill(var->pid_one, SIGUSR2);
}

int loop_two(base_t *var)
{
    var_sig.bol = 0;
    while (var_sig.bol != 1 || var_sig.bol != 2) {
        display_map_ptwo(var);
        defense_two(var);
        if (attack_two(var) == 84)
            return 84;
        verif_map(var);
        verif_map_two(var);
        if (var_sig.bol == 1)
            return 0;
        if (var_sig.bol == 2)
            return 1;
    }
}

static int error_case(base_t *var, char **argv, pid_t pid_two)
{
    if (filereader_ptwo(var, argv[2]) == 84)
        return 84;
    if (pid_two <= 100)
        return 84;
    var->pid_two = pid_two;
    signal_me();
    if (load_boat_two(var) == 84)
        return 84;
}

int player_two(int argc, char **argv, base_t *var)
{
    pid_t pid_two = getpid();
    int r = 0;

    if (error_case(var, argv, pid_two) == 84)
        return 84;
    my_putstr("my_pid: ");
    my_put_nbr(pid_two);
    var->pid_one = my_getnbr(argv[1]);
    kill(var->pid_one, SIGUSR1);
    pause();
    my_putstr("\n\nsuccessfully connected to enemy\n");
    r = loop_two(var);
    if (r == 1)
        my_putstr("\nI won\n");
    if (r == 0)
        my_putstr("\nEnemy won\n");
    if (r == 84)
        return 84;
    return 0;
}
