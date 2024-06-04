/*
** EPITECH PROJECT, 2024
** print_2d.c
** File description:
** that function should print an 2d array
*/
#include "../include/my_project.h"
#include <stdlib.h>

void print_arg(char **arg)
{
    if (!arg)
        return;
    for (int i = 0; arg[i] != NULL; i++) {
        my_putstr(arg[i]);
        my_putchar('\n');
    }
}

void print_list(path_t *list)
{
    if (list == NULL)
        return;
    while (list != NULL) {
        my_putstr(list->value);
        my_putchar('\n');
        list = list->next;
    }
}

static int get_len_to_advance(char *str)
{
    int len = 0;
    int count = 0;

    for (len = 0; str[len] != '\0' && count != 2; len++) {
        if (str[len] == ' ')
            count++;
    }
    return len;
}

static char *get_last_cmd(envp_info_t *envp)
{
    int fd = 0;
    struct stat sb;
    char *history = NULL;
    char **array = NULL;
    int nb_last_line = 0;
    char *path = NULL;

    fd = open_history_read(envp, &path);
    if (fd == -1 || stat(path, &sb) != 0)
        return NULL;
    history = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, history, sb.st_size);
    history[sb.st_size] = '\0';
    array = my_strtok(history, "\n");
    if (array_size(array) < 2)
        return NULL;
    nb_last_line = nb_line_of_array(array) - 2;
    clean_esperluette(array[nb_last_line]);
    history = array[nb_last_line] + get_len_to_advance(array[nb_last_line]);
    return history;
}

static void print_last_cmd(envp_info_t *info)
{
    char *last_cmd = get_last_cmd(info);

    my_putstr("_\t");
    if (last_cmd)
        my_putstr(last_cmd);
    my_putstr("\n\n");
}

void print_set_list(path_t *list, envp_info_t *info)
{
    while (list != NULL) {
        if (list->value[0] < 'A' || list->value[0] > 'Z')
            break;
        my_putstr(list->value);
        my_putchar('\n');
        list = list->next;
    }
    if (isatty(0))
        print_last_cmd(info);
    while (list != NULL) {
        my_putstr(list->value);
        my_putchar('\n');
        list = list->next;
    }
}
