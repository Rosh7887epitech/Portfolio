/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#ifndef BSQ_H_
    #define BSQ_H_

typedef struct base {
    int rows;
    int cols;
    int x;
    int y;
    int nb_rows;
    int nb_cols;
    char **map;
    char *buff;
    char **cop;
    int max_size;
    int size_tmp;

} base_t;

int setting_up(int argc, char const **argv);
base_t *pos_of_square(base_t *var);
int find_biggest_square(base_t *var);
int fs_get_number_from_first_line(char const *filepath);
base_t *load_2d_arr_from_file(char const *filepath, base_t *var);
char **mem_alloc_2d_array(base_t *var);
char **mem_dup_2d_array(char **arr, base_t *var);
base_t *size_of_square(base_t *var, char const *filepath);
int stat_of_file(char const *filepath);
char *load_file_in_mem(char const *filepath);
base_t *change_char(base_t *var);

#endif
