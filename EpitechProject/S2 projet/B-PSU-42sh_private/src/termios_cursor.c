/*
** EPITECH PROJECT, 2024
** termios_cursor.c
** File description:
** that file should handle cursor pos
*/
#include "my_project.h"

void move_cursor(int row, int col)
{
    printf("\033[%d;%dH", row, col);
    fflush(stdout);
}

void get_cursor_position(int *row, int *col)
{
    printf("\033[6n");
    fflush(stdout);
    scanf("\033[%d;%dR", row, col);
}
