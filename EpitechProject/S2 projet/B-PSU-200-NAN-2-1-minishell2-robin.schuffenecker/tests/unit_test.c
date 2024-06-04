/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell2-robin.schuffenecker
** File description:
** sh_test
*/

#include <criterion/criterion.h>
#include "my.h"
#include "command.h"
#include "env.h"
#include "cd.h"


Test(clean_line, removes_extra_spaces)
{
    char *input = "   Hello   world  ";
    char *expected_output = "Hello world";
    char *result = clean_line(input);
    cr_assert_str_eq(result, expected_output, "Expected '%s' but got '%s'", expected_output, result);
    free(result);
}

Test(my_getnbr, valid_input) {
    cr_assert_eq(my_getnbr("123"), 123, "Conversion de '123' devrait être 123");
    cr_assert_eq(my_getnbr("-123"), -123, "Conversion de '-123' devrait être -123");
    cr_assert_eq(my_getnbr("0"), 0, "Conversion de '0' devrait être 0");
    cr_assert_eq(my_getnbr("2147483647"), 2147483647, "Conversion de '2147483647' devrait être 2147483647");
    cr_assert_eq(my_getnbr("-2147483648"), -2147483648, "Conversion de '-2147483648' devrait être -2147483648");
}

Test(my_itoa, valid_input) {
    char *result;
    result = my_itoa(123);
    cr_assert_str_eq(result, "123", "Conversion de 123 devrait donner '123'");
    free(result);

    result = my_itoa(0);
    cr_assert_str_eq(result, "0", "Conversion de 0 devrait donner '0'");
    free(result);
}

Test(my_strcmp, equal_strings) {
    cr_assert_eq(my_strcmp("hello", "hello"), 0, "'hello' et 'hello' devraient être égaux");
}

Test(my_strcmp, different_strings) {
    cr_assert(my_strcmp("hello", "world") != 0, "'hello' et 'world' ne devraient pas être égaux");
}

Test(my_strcmp, empty_string) {
    cr_assert_eq(my_strcmp("", ""), 0, "Deux chaînes vides devraient être égales");
}

Test(my_strdup, valid_input) {
    char *source = "Hello, World!";
    char *dup = my_strdup(source);
    cr_assert_str_eq(dup, source, "La chaîne dupliquée devrait être égale à la source");
    free(dup);
}

Test(my_strlen, valid_strings) {
    cr_assert_eq(my_strlen("hello"), 5, "La longueur de 'hello' devrait être 5");
    cr_assert_eq(my_strlen(""), 0, "La longueur d'une chaîne vide devrait être 0");
}

Test(my_strncpy, copy_partial_string) {
    char src[] = "Hello, World!";
    char dest[6];
    my_strncpy(dest, src, 5);
    dest[5] = '\0';
    cr_assert_str_eq(dest, "Hello", "5 premiers caractères de 'Hello, World!' devraient être 'Hello'");
}


