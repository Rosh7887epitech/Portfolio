/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/org.h"
#include "../shell/shell.h"

int main(void)
{
    list *var = NULL;

    if (workshop_shell(&var) == 84) {
        return 84;
    } else {
        return 0;
    }
}
