/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell2-robin.schuffenecker
** File description:
** sh_test
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_itoa, convert_positive_integer) {
    int score = 123;
    char *result = my_itoa(score);
    cr_assert_str_eq(result, "123", "La conversion de 123 devrait donner \"123\"");
    free(result);
}

Test(my_itoa, convert_zero) {
    int score = 0;
    char *result = my_itoa(score);
    cr_assert_str_eq(result, "0", "La conversion de 0 devrait donner \"0\"");
    free(result);
}

Test(my_strlen, length_of_empty_string) {
    char *str = "";
    cr_assert_eq(my_strlen(str), 0, "La longueur d'une chaîne vide devrait être 0");
}

Test(my_strlen, length_of_regular_string) {
    char *str = "test";
    cr_assert_eq(my_strlen(str), 4, "La longueur de \"test\" devrait être 4");
}