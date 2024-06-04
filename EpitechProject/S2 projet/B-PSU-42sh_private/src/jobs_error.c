/*
** EPITECH PROJECT, 2024
** B-PSU-42sh_private
** File description:
** jobs_error
*/

#include "jobs.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int first_pos_esperluette(info_t *line, envp_info_t *envp)
{
    char *str = my_strdup(line->line_getted);
    int nb_esp = 0;

    if (line->line_getted[0] == '&') {
        for (nb_esp = 0; str[nb_esp] == '&' && str[nb_esp] != '\0'; nb_esp++);
        if (str[nb_esp] == '\0') {
            envp->return_status = 0;
            return 1;
        }
        str = my_strdup(str + nb_esp);
        line->line_getted = my_strdup(str);
    }
    free(str);
    return 0;
}

void final_line(info_t *line)
{
    char **com = my_strtok(line->line_getted, "&");
    int size = array_size(com);
    int nb_jobs = count_nb_jobs(line);

    if (size > nb_jobs) {
        clean_esperluette(com[size - 1]);
        line->line_getted = my_strdup(com[size - 1]);
        free_array(com);
    } else {
        line->line_getted[0] = '\n';
        free_array(com);
    }
}

static char **remove_char(char **tab, int value)
{
    int size = count_str(tab);
    char **new_tab = malloc(sizeof(char *) * (size + 1));
    int j = 0;

    if (!new_tab)
        return NULL;
    for (int i = 0; i < size; i++) {
        if (i != value) {
            new_tab[j] = my_strdup(tab[i]);
            j++;
        }
    }
    new_tab[j] = NULL;
    free(tab);
    return new_tab;
}

static int *remove_int(int *tab, int value)
{
    int size = count_size(tab);
    int *new_tab = malloc(sizeof(int) * size);
    int j = 0;

    if (!new_tab)
        return NULL;
    for (int i = 0; i < size; i++) {
        if (i != value) {
            new_tab[j] = tab[i];
            j++;
        }
    }
    new_tab[size - 1] = -1;
    free(tab);
    return new_tab;
}

static int cond_error_job(int index)
{
    if (index == 1) {
        return my_printerror("fg: no current job\n", 1);
    }
    return my_printerror("bg: no current job\n", 1);
}

int error_jobs(envp_info_t *envp, int index)
{
    if (!isatty(STDIN_FILENO)) {
        my_printerror("No job control in this shell.\n", 1);
        exit(1);
    }
    if (envp->jobs->n_jobs[0] == -1) {
        return cond_error_job(index);
    }
    return 0;
}

int error_param(envp_info_t *envp, int pos)
{
    if (envp->jobs->n_jobs[pos -1] == -1)
        return -1;
    return 0;
}

void remove_tab(envp_info_t *envp, int size)
{
    envp->jobs->n_jobs = remove_int(envp->jobs->n_jobs, size - 1);
    envp->jobs->name_jobs = remove_char(envp->jobs->name_jobs, size - 1);
}
