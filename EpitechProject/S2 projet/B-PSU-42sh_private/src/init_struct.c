/*
** EPITECH PROJECT, 2024
** init_struct.c
** File description:
** that file should init and free all my structure
*/

#include "../include/my_project.h"
#include <stdlib.h>

envp_info_t *alloc_struct(char **envp)
{
    envp_info_t *env = malloc(sizeof(envp_info_t));

    env->envp = array_cpy(envp);
    env->my_cd = malloc(sizeof(info_t));
    env->my_cd->line_getted = NULL;
    env->l_envp = envp_to_list(envp);
    env->old_pwd = find_in_envp(env->l_envp, "OLDPWD=", 7);
    if (env->old_pwd != NULL)
        env->old_pwd = env->old_pwd + 7;
    env->status = 0;
    env->return_status = 0;
    env->jobs = malloc(sizeof(jobs_t));
    env->jobs->n_jobs = malloc(sizeof(int) * 1);
    env->jobs->n_jobs[0] = -1;
    env->jobs->name_jobs = NULL;
    env->alias = add_alias_from_rc(env);
    env->tmp_line = NULL;
    env->local = NULL;
    return env;
}

void free_struct(envp_info_t *environ)
{
    free_array(environ->envp);
    free(environ->my_cd->line_getted);
    free(environ->my_cd);
    free(environ);
}
