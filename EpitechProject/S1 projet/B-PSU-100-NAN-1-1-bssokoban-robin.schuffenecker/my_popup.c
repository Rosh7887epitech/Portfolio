/*
** EPITECH PROJECT, 2023
** pop up
** File description:
** pop up
*/

#include <ncurses.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int main(int argc, char **argv)
{
    char ch;
    int middle_size = my_strlen(argv[1]) / 2;

    initscr();
    while (1) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - (middle_size / 2), argv[1]);
        ch = getch();
        if (ch == 32 || ch == ' ') {
            endwin();
            return 0;
        }
        refresh();
    }
    return 0;
}
