/*
** EPITECH PROJECT, 2023
** stat
** File description:
** stat
*/

#include "include/include.h"
#include "include/my.h"
#include "include/bsq.h"

int stat_of_file(char const *filepath)
{
    struct stat sb;
    int size = 0;

    stat(filepath, &sb);
    size = sb.st_size;
    return size;
}
