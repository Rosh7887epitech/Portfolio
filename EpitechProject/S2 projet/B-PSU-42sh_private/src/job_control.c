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

int count_str(char **tab)
{
    int k = 0;

    if (tab == NULL)
        return -1;
    for (k = 0; tab[k] != NULL; k++);
    return k;
}

int count_size(int *tab)
{
    int k = 0;

    if (tab == NULL)
        return -1;
    for (k = 0; tab[k] != -1; k++);
    return k;
}

static int back_display(envp_info_t *envp, int size, int param_size)
{
    if (param_size >= 1)
        size = param_size;
    my_putstr("[");
    my_put_nbr(size);
    my_putstr("]\t");
    my_putstr(envp->jobs->name_jobs[size - 1]);
    my_putstr(" &");
    my_putstr("\n");
    return size;
}

static int background_prog(info_t *line, envp_info_t *envp)
{
    int status = 0;
    int size = 0;
    int pid = 0;
    int param_size = 0;

    if (error_jobs(envp, 0) == 1)
        return 1;
    size = count_size(envp->jobs->n_jobs);
    param_size = have_param(line, envp);
    if (param_size == -1)
        return 0;
    size = back_display(envp, size, param_size);
    pid = fork();
    if (pid == 0) {
        waitpid(envp->jobs->n_jobs[size - 1], &status, WUNTRACED);
        exit(0);
    }
    waitpid(pid, &status, 0);
    remove_tab(envp, size);
    return 0;
}

static int forground_prog(info_t *line, envp_info_t *envp)
{
    int status = 0;
    int size = 0;
    int param_size = 0;

    if (error_jobs(envp, 1) == 1)
        return 1;
    size = count_size(envp->jobs->n_jobs);
    param_size = have_param(line, envp);
    if (param_size == -1)
        return 0;
    if (param_size != 0)
        size = param_size;
    my_putstr(envp->jobs->name_jobs[size - 1]);
    my_putstr("\n");
    waitpid(envp->jobs->n_jobs[size - 1], &status, WUNTRACED);
    remove_tab(envp, size);
    line->line_getted[0] = '\n';
    return 0;
}

char *search_path_jobs(info_t *line, envp_info_t *envp, char *com)
{
    char *input = NULL;
    char *env_find = NULL;
    char *fct = NULL;
    char **array = NULL;

    if (handle_usr_injection(line, &array, envp) != 0)
        return NULL;
    if (array == NULL)
        array = my_strtok(com, " ");
    input = shell_function(com);
    fct = reduce_path(input);
    env_find = find_path(envp->l_envp, fct);
    if (!env_find)
        return input;
    fct = my_strcat(env_find, my_strcat("/", fct));
    return fct;
}

int execute_jobs_control(info_t *line, envp_info_t *envp)
{
    int i = 0;
    char *str_tmp = my_strcat(line->line_getted, " ");

    if (my_strncmp(str_tmp, "fg ", 3) == 0)
        return forground_prog(line, envp);
    if (my_strncmp(str_tmp, "bg ", 3) == 0) {
        i = background_prog(line, envp);
        line->line_getted[0] = '\n';
        return i;
    }
    for (int i = 0; line->line_getted[i] != '\0'; i++) {
        if (line->line_getted[i] == '&') {
            i = search_prog(line, envp);
            final_line(line);
            return i;
        }
    }
    free(str_tmp);
    return 0;
}
