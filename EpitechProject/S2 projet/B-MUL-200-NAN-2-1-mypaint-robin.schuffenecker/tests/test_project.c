/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** a file to test : my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_project.h"

void redirect_all_std (void)
{
cr_redirect_stdout ();
cr_redirect_stderr ();
}
