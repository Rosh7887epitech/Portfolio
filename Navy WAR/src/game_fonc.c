/*
** EPITECH PROJECT, 2024
** attack
** File description:
** def
*/

#include "my.h"

int defense_two(base_t *var)
{
    int y = 0;
    int x = 0;
    char c;

    my_putstr("\nwaiting for enemy's attack...\n");
    y += (receive_sig() + 1);
    x += (receive_sig() * 2);
    my_putstr("\n\nresult: ");
    c = conv_letter(var, (x / 2));
    my_putchar(c);
    my_put_nbr(y - 1);
    ping_two(var, x, y);
}

int defense_one(base_t *var)
{
    int y = 0;
    int x = 0;
    char c;

    my_putstr("\nwaiting for enemy's attack...\n");
    y += (receive_sig() + 1);
    x += (receive_sig() * 2);
    my_putstr("\n\nresult: ");
    c = conv_letter(var, (x / 2));
    my_putchar(c);
    my_put_nbr(y - 1);
    ping_one(var, x, y);
}

int attack_two(base_t *var)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t read;

    my_putstr("\nattack: ");
    read = getline(&line, &bufsize, stdin);
    if (my_strlen(line) != 3 || search_letter(var, line) == -1 ||
        line[1] >= '9' || line[1] <= '0') {
        my_putstr("\nwrong position\n");
        return attack_two(var);
    }
    if (recup_pos_two(var, line) == 84)
        return 84;
    h_or_m_two(var, line);
    return 0;
}

int attack_one(base_t *var)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t read;
    int result = 0;

    my_putstr("\nattack: ");
    read = getline(&line, &bufsize, stdin);
    if (my_strlen(line) != 3 || search_letter(var, line) == -1 ||
        line[1] >= '9' || line[1] <= '0') {
        my_putstr("\nwrong position\n");
        return attack_one(var);
    }
    if (recup_pos_one(var, line) == 84)
        return 84;
    h_or_m_one(var, line);
    return 0;
}
