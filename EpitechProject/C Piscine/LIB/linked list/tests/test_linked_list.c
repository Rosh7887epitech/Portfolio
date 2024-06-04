/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include/ls.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(put_list, print_list, .init = redirect_all_std)
{
    list *tkt = NULL;

    add_list(&tkt, 8);
    put_list(&tkt);
    cr_assert_stdout_eq_str("8 -> NULL\n")
}