/*
** EPITECH PROJECT, 2023
** setting up
** File description:
** setting up
*/

#include "include/include.h"
#include "include/my.h"
#include "include/bsq.h"

static int display(base_t *var)
{
    for (int i = 0; i < var->nb_rows; i++) {
        for (int j = 0; j < var->nb_cols; j++) {
            my_putchar(var->cop[i][j]);
        }
        my_putstr("\n");
    }
}

int setting_up(int argc, char const **argv)
{
    base_t *var = malloc(sizeof(var));
    int size_buff = stat_of_file(argv[1]);
    char *buff = malloc(sizeof(char) * size_buff);
    int fd = open(argv[1], O_RDONLY);
    int nb;

    if (size_buff == 0 || size_buff > 250503 || fd == -1) {
        my_putstr("error\n");
        return 84;
    }
    nb = fs_get_number_from_first_line(argv[1]);
    var = size_of_square(var, argv[1]);
    if (nb > var->nb_rows || nb < var->nb_rows) {
        return 84;
    }
    var = load_2d_arr_from_file(argv[1], var);
    pos_of_square(var);
    var = change_char(var);
    display(var);
}
