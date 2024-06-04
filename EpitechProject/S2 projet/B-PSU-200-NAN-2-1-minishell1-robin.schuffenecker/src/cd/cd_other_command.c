/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-robin.schuffenecker
** File description:
** cd_other_command
*/

#include "cd.h"

int cond_exit(char *line)
{
    char **ex = my_str_to_word_array(line, ' ');
    int n = 0;

    if (my_strcmp(line, "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (ex[1] != NULL && ex[2] == NULL)
        n = my_str_num(ex[1]);
    if (ex[2] != NULL || n == 0) {
        my_putstr("exit: Expression Syntax.\n");
        if (!isatty(0))
            exit(1);
        return 1;
    }
    if (n == 1) {
        n = my_getnbr(ex[1]);
        my_putstr("exit\n");
        exit(n);
    }
}

int old_cd(base_t *var)
{
    if (my_strcmp(var->command[1], "-") == 0) {
        if (var->old_path != NULL) {
            chdir(var->old_path);
            return 0;
        }
        my_putstr(": No such file or directory.\n");
        if (!isatty(0))
            exit(1);
        return 1;
    }
}
