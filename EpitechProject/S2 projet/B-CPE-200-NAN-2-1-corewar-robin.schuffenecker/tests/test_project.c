/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-corewar-robin.schuffenecker
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std (void)
{
cr_redirect_stdout ();
cr_redirect_stderr ();
}

Test(init_struct, test_init_struct)
{
    info_t *info = init_struct();
    cr_assert_eq(info->dump, 0);
    cr_assert_eq(info->nb_champ, 0);
    cr_assert_eq(info->champ, NULL);
    cr_assert_eq(info->env->memory_size, 0);
    cr_assert_eq(info->env->memory, NULL);
}

Test(load_champions_in_mem, test_load_champions_in_mem)
{
    info_t *info = init_struct();
    env_t *env = malloc(sizeof(env_t));
    env->memory_size = 10;
    env->memory = malloc(sizeof(uint8_t) * env->memory_size);
    champ_t *champ = malloc(sizeof(champ_t));
    champ->load_ad = 0;
    champ->instru = malloc(sizeof(instruction_t));
    champ->instru->code = 1;
    champ->instru->next = NULL;
    info->champ = champ;
    load_champions_in_mem(info, env);
    cr_assert_eq(env->memory[0], 1);
}
