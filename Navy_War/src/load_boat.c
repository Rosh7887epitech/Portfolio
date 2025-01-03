/*
** EPITECH PROJECT, 2024
** project
** File description:
** load_boat
*/

#include "my.h"

static void fill_structure(base_t *var, int i, char **pos)
{
    var->sy = (my_getnbr(pos[i]) + 1);
    var->sx = (search_letter(var, pos[i]) * 2);
    var->ey = (my_getnbr(pos[i + 1]) + 1);
    var->ex = (search_letter(var, pos[i + 1]) * 2);
}

static int collision_x(int h, base_t *var, char *b)
{
    for (int i = 0; i < h; i++) {
        if (var->map_pone[var->ey][i * 2 + 8] != '.')
            return 84;
        var->map_pone[var->ey][i * 2 + 8] = b[0];
    }
    return 0;
}

static int collision_y(int h, base_t *var, char *b)
{
    for (int i = 0; i < h; i++) {
        if (var->map_pone[var->sy + i][var->ex] != '.')
            return 84;
        var->map_pone[var->sy + i][var->ex] = b[0];
    }
    return 0;
}

static int collision_x_two(int h, base_t *var, char *b)
{
    for (int i = 0; i < h; i++) {
        if (var->map_ptwo[var->ey][i * 2 + 8] != '.')
            return 84;
        var->map_ptwo[var->ey][i * 2 + 8] = b[0];
    }
    return 0;
}

static int collision_y_two(int h, base_t *var, char *b)
{
    for (int i = 0; i < h; i++) {
        if (var->map_ptwo[var->sy + i][var->ex] != '.')
            return 84;
        var->map_ptwo[var->sy + i][var->ex] = b[0];
    }
    return 0;
}

int pos_boat_two(base_t *var, char *b, int h)
{
    int lx = var->ex - var->sx;
    int ly = var->ey - var->sy;

    if (lx <= 0 && ly <= 0)
        return 84;
    if (lx > 0) {
        if (((lx / 2) + 1) != h)
            return 84;
        if (collision_x_two(h, var, b) == 84)
            return 84;
    }
    if (ly > 0) {
        if (ly + 1 != h)
            return 84;
        if (collision_y_two(h, var, b) == 84)
            return 84;
    }
    return 0;
}

int load_boat_two(base_t *var)
{
    char **pos = my_str_to_word_array(var->buff_two);
    int b = 0;
    int temp = 2;

    for (int i = 0; pos[i] != NULL; i += 2) {
        if (i == 0 || i == 3 || i == 6 || i == 9) {
            b = my_getnbr(pos[i]);
            i++;
        }
        if (b != temp)
            return 84;
        temp++;
        fill_structure(var, i, pos);
        if (pos_boat_two(var, my_itoa(b), b) == 84)
            return 84;
    }
    return 0;
}

int pos_boat_one(base_t *var, char *b, int h)
{
    int lx = var->ex - var->sx;
    int ly = var->ey - var->sy;

    if (lx <= 0 && ly <= 0)
        return 84;
    if (lx > 0) {
        if (((lx / 2) + 1) != h)
            return 84;
        collision_x(h, var, b);
    }
    if (ly > 0) {
        if (ly + 1 != h)
            return 84;
        collision_y(h, var, b);
    }
    return 0;
}

int load_boat_one(base_t *var)
{
    char **pos = my_str_to_word_array(var->buff);
    int b = 0;
    int temp = 2;

    for (int i = 0; pos[i] != NULL; i += 2) {
        if (i == 0 || i == 3 || i == 6 || i == 9) {
            b = my_getnbr(pos[i]);
            i++;
        }
        if (b != temp)
            return 84;
        temp++;
        fill_structure(var, i, pos);
        if (pos_boat_one(var, my_itoa(b), b) == 84)
            return 84;
    }
    return 0;
}
