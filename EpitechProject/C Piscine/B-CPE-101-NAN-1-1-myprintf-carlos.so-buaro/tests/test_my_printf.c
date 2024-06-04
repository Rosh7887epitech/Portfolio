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

Test(my_printf,simple_string, .init = redirect_all_std)
{
    my_printf ("hello world");
    cr_assert_stdout_eq_str ("hello world");
}

Test(my_printf,simple_char, .init = redirect_all_std)
{
    my_printf ("r");
    cr_assert_stdout_eq_str ("r");
}

Test(my_printf,simple_int, .init = redirect_all_std)
{
    my_printf ("42");
    cr_assert_stdout_eq_str ("42");
}

Test(my_printf,string_char_int, .init = redirect_all_std)
{
    my_printf ("bonjour je suis %s et j'adore les t%c, j'ai souvent 100/%d mais des fois j'ai des %s%c%d%i", "fougere", 'a', 100, "test", 'q', 12, 84, 98);
    cr_assert_stdout_eq_str ("bonjour je suis fougere et j'adore les ta, j'ai souvent 100/100 mais des fois j'ai des testq1284");
}

Test(my_printf,simple_float, .init = redirect_all_std)
{
    my_printf ("%f", 42.84);
    cr_assert_stdout_eq_str ("42.840000");
}

Test(my_printf,simple_exp, .init = redirect_all_std)
{
    my_printf ("%e", 42.586);
    cr_assert_stdout_eq_str ("4.258600e+01");
}

Test(my_printf,simple_hexa, .init = redirect_all_std)
{
    my_printf ("%x", 42);
    cr_assert_stdout_eq_str ("2a");
}

Test(my_printf,simple_hexa_up, .init = redirect_all_std)
{
    my_printf ("%X", 42);
    cr_assert_stdout_eq_str ("2A");
}

Test(my_printf,simple_oct, .init = redirect_all_std)
{
    my_printf ("%o", 42);
    cr_assert_stdout_eq_str ("52");
}

Test(my_printf,simple_unsigned, .init = redirect_all_std)
{
    my_printf ("%u", 3000000000);
    cr_assert_stdout_eq_str ("3000000000");
}

Test(my_printf,babebibobu, .init = redirect_all_std)
{
    my_printf ("test %i test %c test %f test %s test %e test %p test %o test %x test %F test %X", 42, 'r', 55.55, "babebibobu", 85.654, 42, 42, 42, 66.47, 42);
    cr_assert_stdout_eq_str ("test 42 test r test 55.550000 test babebibobu test 8.565400e+01 test 0x2a test 52 test 2a test 66.470000 test 2A");
}

Test(my_printf,modulo_double, .init = redirect_all_std)
{
    my_printf ("%%");
    cr_assert_stdout_eq_str ("%");
}
