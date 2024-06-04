/*
** EPITECH PROJECT, 2023
** test my_printf
** File description:
** full test for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../lib/my/rush3.h"

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(rush3.c, 4_4, .init = redirect_all_std)
{
    ./rush1-1 4 4 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 4 4");
}

Test(rush3.c, 50_50, .init = redirect_all_std)
{
    ./rush1-1 50 50 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 50 50");
}

Test(rush3.c, 7_7, .init = redirect_all_std)
{
    ./rush1-1 7 7 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 7 7");
}

Test(rush3.c, 55_55, .init = redirect_all_std)
{
    ./rush1-1 55 55 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 55 55");
}

Test(rush3.c, 5_1, .init = redirect_all_std)
{
    ./rush1-1 5 1 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 5 1");
}

Test(rush3.c, 50_1, .init = redirect_all_std)
{
    ./rush1-1 50 1 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 50 1");
}

Test(rush3.c, 1_1, .init = redirect_all_std)
{
    ./rush1-1 1 1 | ./rush3;
    cr_assert_stdout_eq_str ("[rush-1-1] 1 1");
}

Test(rush3.c, 0_0, .init = redirect_all_std)
{
    ./rush1-1 0 0 | ./rush3;
    cr_assert_stdout_eq_str ("error 84");
}

