/*
XC** EPITECH PROJECT, 2023
** test my_printf
** File description:
** full test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../lib/my/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_ls,simple_dir, .init = redirect_all_std)
{
    my_ls ("hello world");
    cr_assert_stdout_eq_str ("hello world");
}
