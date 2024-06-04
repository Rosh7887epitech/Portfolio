/*
** EPITECH PROJECT, 2024
** B-CPE-210-NAN-2-1-stumper5-davy.gatineau
** File description:
** main
*/

#include "my.h"

static int init_memory(env_t *env)
{
    env->memory_size = MEM_SIZE;
    env->memory = malloc(sizeof(uint8_t) * env->memory_size);
    if (env->memory == NULL)
        return 84;
    for (int i = 0; i < env->memory_size; i++) {
        env->memory[i] = 0;
    }
}

info_t *init_struct(void)
{
    info_t *info = malloc(sizeof(info_t));

    if (info == NULL)
        exit(84);
    info->nb_champ = 0;
    info->dump = 0;
    info->champ = NULL;
    info->env = malloc(sizeof(env_t));
    if (info->env == NULL)
        return NULL;
    return info;
}

int main(int ac, char **av)
{
    info_t *info = init_struct();

    if (info == NULL)
        return 84;
    init_memory(info->env);
    if (pars_arg(ac, av, info) == 84)
        return 84;
    load_champions_in_mem(info, info->env);
    game_loop(info);
    return 0;
}
