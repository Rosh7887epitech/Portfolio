/*
** EPITECH PROJECT, 2024
** create
** File description:
** book
*/

#include "../include/my.h"

void add_address(entry_t **address_book, int len, char *name,
    char *phone_number)
{
    int i;

    if (len == 0) {
        return;
    }
    for (i = 0; i < len; i++) {
        if (address_book[i]->name == NULL &&
            address_book[i]->phone_number == NULL) {
            break;
        }
    }
    if (i >= len) {
        my_putstr("add_address: not enough capacity to store new adress\n");
    } else {
        address_book[i] = create_address(name, phone_number);
        my_putstr("new address added\n");
    }
}

entry_t *create_address(char *name, char *phone_number)
{
    entry_t *address = malloc(sizeof(entry_t));

    address->name = my_strdup(name);
    address->phone_number = my_strdup(phone_number);
    return address;
}

entry_t **create_address_book(int len)
{
    entry_t **book = malloc(sizeof(entry_t *) * len);

    for (int i = 0; i < len; i++) {
        book[i] = malloc(sizeof(entry_t));
        book[i]->name = NULL;
        book[i]->phone_number = NULL;
    }
    my_putstr("address book created\n");
    return book;
}
