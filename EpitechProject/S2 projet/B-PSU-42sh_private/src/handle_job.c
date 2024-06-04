/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** job_control
*/

#include "jobs.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int count_nb_jobs(info_t *line)
{
    int index = 0;

    for (int i = 0; line->line_getted[i] != '\0'; i++) {
        if (line->line_getted[i] == '&' &&
            (line->line_getted[i + 1] != '&' &&
            line->line_getted[i - 1] != '&') && i > 0)
            index++;
    }
    return index;
}

static int *realloc_int(int *tab, int add)
{
    int index = count_size(tab);
    int *cop = NULL;

    if (index == -1)
        return NULL;
    cop = malloc(sizeof(int) * (index + 2));
    if (cop == NULL)
        return NULL;
    for (int i = 0; i < index; i++) {
        cop[i] = tab[i];
    }
    cop[index] = add;
    cop[index + 1] = -1;
    free(tab);
    return cop;
}

static char **realloc_tab(char **tab, char *add)
{
    int index = count_str(tab);
    char **cop = NULL;

    if (index == -1) {
        cop = malloc(sizeof(char *) * 2);
        cop[0] = add;
        cop[1] = NULL;
        return cop;
    }
    cop = malloc(sizeof(int) * (index + 2));
    if (cop == NULL)
        return NULL;
    for (int i = 0; i < index; i++) {
        cop[i] = my_strdup(tab[i]);
    }
    cop[index] = my_strdup(add);
    cop[index + 1] = NULL;
    free(tab);
    return cop;
}

static void display_jobs(int i, int pid)
{
    my_putstr("[");
    my_put_nbr(i + 1);
    my_putstr("] ");
    my_put_nbr(pid);
    my_putstr("\n");
}

static void end_of_prog(int i, int pid, char **argu, envp_info_t *envp)
{
    display_jobs(i, pid);
    envp->jobs->n_jobs = realloc_int(envp->jobs->n_jobs, pid);
    envp->jobs->name_jobs = realloc_tab(envp->jobs->name_jobs, argu[0]);
}

static int exec_jobs(envp_info_t *envp, char *path, char **com, int i)
{
    int pid = 0;
    char **argu = NULL;

    pid = fork();
    if (pid == -1)
        return my_printerror("Error FORK\n", 1);
    argu = my_strtok(com[i], " ");
    if (argu == NULL)
        return 1;
    if (pid == 0) {
        execve(path, argu, envp->envp);
        access_to_file(path);
        exit(1);
    }
    end_of_prog(i, pid, argu, envp);
    return 0;
}

int have_param(info_t *line, envp_info_t *envp)
{
    char **parameter = my_strtok(line->line_getted, " ");
    int return_value = -1;

    if (parameter == NULL || parameter[1] == NULL)
        return 0;
    if (my_strncmp(parameter[1], "%", 1) == 0) {
        return_value = my_getnbr(parameter[1]);
        if (return_value == -1 || return_value == 0)
            return 0;
    }
    if (error_param(envp, return_value) == -1)
        return -1;
    return return_value;
}

int search_prog(info_t *line, envp_info_t *envp)
{
    char **com = my_strtok(line->line_getted, "&");
    int index = 0;
    int status = 0;
    char *path = NULL;

    if (com == NULL)
        return 1;
    getpid();
    index = count_nb_jobs(line);
    for (int i = 0; i < index; i++) {
        clean_esperluette(com[i]);
        path = search_path_jobs(line, envp, com[i]);
        if (path == NULL)
            return 1;
        if (exec_jobs(envp, path, com, i) == 1)
            return 1;
    }
    return segfault_handling(status);
}
