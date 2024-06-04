/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** SECURED
*/

#pragma once

    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "bootstrap.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strdup(char *src);
entry_t **create_address_book(int len);
entry_t *create_address(char *name, char *phone_number);
void add_address(entry_t **address_book, int len, char *name,
    char *phone_number);
void dummy_function(entry_t *address);
void execute_on_address_book(entry_t **address_book, int len,
    void(*execute)());
void delete_address_book(entry_t **address_book, int len);
int main(void);
