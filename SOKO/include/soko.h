/*
** EPITECH PROJECT, 2023
** soko
** File description:
** soko
*/

#ifndef SOKO_H_
    #define SOKO_H_

    #include <ncurses.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct soko {
    int p_row;
    int p_col;
    char **map;
    char **dup;
    int *coor_o_x;
    int *coor_o_y;
    int *coor_x_x;
    int *coor_x_y;
    int i;
    int j;
    int row;
    int col;
    int nb_o;
    int nb_x;

} soko_t;

int sokoban(int argc, char const **argv, soko_t *var, struct stat *sb);
char **load_2d_arr_from_file(char *buff, soko_t *var);
char *load_file_in_mem(char const *filepath);
int my_popup(soko_t *var);
void my_putchar(char c);
int stat_of_file(int argc, char const **argv, soko_t *var, struct stat *sb);
int my_putstr(char const *str);
soko_t *pos_of_p(soko_t *var);
int move_player(char ch, soko_t *var, int nb_rows, int nb_cols);
int vertical_move(char ch, soko_t *var, int nb_rows, int nb_cols);
int horizontal_move(char ch, soko_t *var, int nb_rows, int nb_cols);
soko_t *coordinate_of_o(soko_t *var);
soko_t *coordinate_of_x(soko_t *var);
int nb_of_o(soko_t *var);
int nb_of_x(soko_t *var);
int object(soko_t *var);
char **mem_dup_2d_array(soko_t *var);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);


#endif /* !SOKO */
