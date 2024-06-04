/*
** EPITECH PROJECT, 2024
** create
** File description:
** book
*/

#include "../include/my.h"

void delete_address_book(entry_t **address_book, int len)
{
    int i;

    if (len == 0) {
        return;
    }
    for (i = 0; i < len; i++) {
        if (address_book[i] != NULL) {
            free(address_book[i]);
        }
    }
    write(1, "\naddress book deleted\n", 23);
}

void execute_on_address_book(entry_t **address_book, int len, void(*execute)())
{
    for (int i = 0; i < len; i++) {
        execute(address_book[i]);
    }
}

void dummy_function(entry_t *address)
{
    write(1, address->name, my_strlen(address->name));
    write(1, "\n", 1);
}
