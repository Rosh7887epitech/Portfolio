#include <stdio.h>
#include <stdlib.h>

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int is_square_of_size(char **map, int row, int col, int square_size);
int find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col);

int main() {
    int nb_rows = 6;
    int nb_cols = 8;
    int row = 0;
    int col = 0;
    char const *file = "test.txt";
    char **dup;

    dup = load_2d_arr_from_file(file, nb_rows, nb_cols);
    find_biggest_square(dup, nb_rows, nb_cols, row, col);
}
