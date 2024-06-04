/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "rpg.h"

void redirect_all_std (void)
{
cr_redirect_stdout ();
cr_redirect_stderr ();
}

Test(compare_pos, test_compare_pos)
{
    sfVector2f pos1 = {1, 1};
    sfVector2f pos2 = {1, 1};
    cr_assert_eq(compare_pos(pos1, pos2), true);
    sfVector2f pos3 = {1, 2};
    sfVector2f pos4 = {5, 1};
    cr_assert_eq(compare_pos(pos3, pos4), true);
    sfVector2f pos5 = {1, 1};
    sfVector2f pos6 = {6, 1};
    cr_assert_eq(compare_pos(pos5, pos6), true);
    sfVector2f pos7 = {1, 1};
    sfVector2f pos8 = {1, 37};
    cr_assert_eq(compare_pos(pos7, pos8), false);
    sfVector2f pos9 = {1, 1};
    sfVector2f pos10 = {37, 1};
    cr_assert_eq(compare_pos(pos9, pos10), false);
}
