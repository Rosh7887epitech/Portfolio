/*
** EPITECH PROJECT, 2024
** get_the_line.c
** File description:
** that file should get line if isatty by termios otherwise by getline
*/

#include "my_project.h"

static void error_getline(int status, envp_info_t *envp)
{
    if (status < 0) {
        if (isatty(STDIN_FILENO))
            my_putchar('\n');
        exit(envp->return_status);
    }
}

static char *get_folder_name(char *pwd)
{
    int i = my_strlen(pwd);

    if (pwd == NULL)
        return NULL;
    for (; pwd[i] != '/' && i >= 0; i--);
    if (pwd[i] == '/')
        i++;
    pwd = pwd + i;
    if (my_strlen(pwd) <= 0)
        pwd = my_strdup("/");
    return pwd;
}

static char *get_host_and_user_name(envp_info_t *envp)
{
    char *host_name = find_in_envp(envp->l_envp, "HOSTNAME=", 9);
    char *username = find_in_envp(envp->l_envp, "USER=", 5);
    int size = my_strlen(host_name) + my_strlen(username);
    char *line = malloc(sizeof(char) * size + 2);

    if (my_strlen(host_name) <= 0 || my_strlen(username) <= 0 ||
        host_name == NULL || username == NULL)
        return NULL;
    line = my_strcat(username + 5, "@");
    line = my_strcat(line, host_name + 9);
    line = my_strcat(line, " ");
    return line;
}

static void display_prompt(envp_info_t *envp)
{
    char *pwd = getcwd(NULL, 0);
    char *host_user = get_host_and_user_name(envp);
    char *folder = get_folder_name(pwd);

    if (host_user == NULL || folder == NULL || pwd == NULL) {
        my_putstr("$> ");
        return;
    }
    write(STDOUT_FILENO, "\033[1;31m[", 8);
    write(STDOUT_FILENO, "\033[0m\x1b[1m", 8);
    my_putstr(host_user);
    my_putstr(folder);
    write(STDOUT_FILENO, "\033[1;31m]", 8);
    write(STDOUT_FILENO, "\033[1;33m$ ", 9);
    write(STDOUT_FILENO, "\033[0m", 4);
}

int get_the_line(info_t *line, envp_info_t *envp)
{
    size_t len = 0;
    int status = 0;

    if (isatty(STDIN_FILENO)) {
        display_prompt(envp);
        get_input(envp, line);
        clean_esperluette(line->line_getted);
        if (line->line_getted == NULL || line->line_getted[0] == '\0')
            line->line_getted = my_strdup("\n");
        status = my_strlen(line->line_getted);
    } else {
        status = getline(&line->line_getted, &len, stdin);
        error_getline(status, envp);
    }
    return status;
}
