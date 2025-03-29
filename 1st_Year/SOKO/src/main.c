/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/soko.h"

static int lenght(char *buff)
{
    int row = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            row++;
    }
    return row;
}

static int verif_map(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != 'O' && buff[i] != 'P' &&
        buff[i] != '#' && buff[i] != 'X' &&
        buff[i] != ' ' && buff[i] != '\n') {
            return 84;
        }
    }
}

int sokoban(int argc, char const **argv, soko_t *var, struct stat *sb)
{
    int row = 0;
    int col = 0;
    char *buff = malloc(sizeof(char) * sb->st_size + 2);
    int fd = open(argv[1], O_RDONLY);
    int k = 0;

    read(fd, buff, sb->st_size);
    if (verif_map(buff) == 84 )
        return 84;
    var->row = lenght(buff);
    var->map = load_2d_arr_from_file(buff, var);
    var->dup = mem_dup_2d_array(var);
    k = my_popup(var);
    return 0;
}

int error_case(int argc, char const **argv, soko_t *var, struct stat *sb)
{
    if (argc != 2) {
        return 84;
    }
    if (stat(argv[1], sb) != -1) {
        stat_of_file(argc, argv, var, sb);
    }
}

static int usage(int argc, char const **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("    ./my_sokoban map\nDESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, ");
        my_putstr("containing '#' for walls,\n");
        my_putstr("          'P' for the player, 'X' for boxes ");
        my_putstr("and 'O' for storage locations.\n");
    } else {
        return 84;
    }
}

int main(int argc, char const **argv)
{
    struct stat sb;
    soko_t *var = malloc(sizeof(soko_t));

    if (error_case(argc, argv, var, &sb) == 84) {
        return 84;
    } else {
        usage(argc, argv);
    }
}
