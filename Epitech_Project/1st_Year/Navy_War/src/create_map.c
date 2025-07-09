/*
** EPITECH PROJECT, 2024
** map
** File description:
** map create
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **dup = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++) {
        dup[i] = malloc(sizeof(char) * nb_cols);
        my_strcpy(dup[i], arr[i]);
    }
    return dup;
}

void create_map(base_t *var)
{
    char **map = malloc(sizeof(char *) * 10);

    for (int i = 0; i < 8; i++)
        map[i] = malloc(sizeof(char)* 18);
    map[0] = my_strdup(" |A B C D E F G H");
    map[1] = my_strdup("-+---------------");
    map[2] = my_strdup("1|. . . . . . . .");
    map[3] = my_strdup("2|. . . . . . . .");
    map[4] = my_strdup("3|. . . . . . . .");
    map[5] = my_strdup("4|. . . . . . . .");
    map[6] = my_strdup("5|. . . . . . . .");
    map[7] = my_strdup("6|. . . . . . . .");
    map[8] = my_strdup("7|. . . . . . . .");
    map[9] = my_strdup("8|. . . . . . . .");
    var->map_pone = mem_dup_2d_array(map, 10, 18);
    var->map_ptwo = mem_dup_2d_array(map, 10, 18);
}
