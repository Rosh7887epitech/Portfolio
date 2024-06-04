/*
** EPITECH PROJECT, 2024
** cd_function
** File description:
** that function should reproduce the cd
*/
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_project.h"
#include <string.h>
#include <errno.h>
#include <dirent.h>

static int handle_cd(char *path, envp_info_t *env, info_t *line)
{
    char *catch = NULL;

    if (path == NULL)
        return 1;
    catch = getcwd(NULL, 0);
    if (chdir(path) == 0) {
        env->old_pwd = my_strdup(catch);
        exec_cwdcmd(line, env);
        return 0;
    }
    my_printerror(path, 1);
    my_printerror(": ", 1);
    my_printerror((strerror(errno)), 1);
    my_printerror(".\n", 1);
    if (!isatty(STDIN_FILENO) && env->is_semicolon != 1)
        exit(1);
    if (access(path, F_OK) == -1)
        return 1;
    return errno;
}

char *find_in_envp(path_t *envp_list, char *to_find, int size)
{
    if (!to_find || !envp_list)
        return "";
    while (envp_list) {
        if (my_strncmp(envp_list->value, to_find, size) == 0)
            return my_strdup(envp_list->value);
        envp_list = envp_list->next;
    }
    return "";
}

int change_directory(char *line, envp_info_t *envp, info_t *line_t)
{
    char *home = NULL;

    if (my_strlen(line) > 2)
        line += 3;
    else
        line += 2;
    if (my_strcmp(line, "~") == 0 || my_strlen(line) < 1) {
        home = find_in_envp(envp->l_envp, "HOME=", 5);
        if (home && my_strlen(home) > 5)
            return handle_cd(home + 5, envp, line_t);
        return my_printerror("No $home variable set.\n", 1);
    }
    if (my_strcmp(line, "-") == 0)
        return handle_cd(envp->old_pwd, envp, line_t);
    line = remove_quotes(line);
    return handle_cd(line, envp, line_t);
}
