/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/my.h"

int main(void)
{
    int size = 5;
    entry_t **address_book;

    write(1, "Creating addresses :\n", 22);
    address_book = create_address_book(size);
    add_address(address_book, size, "Kevin", "+33 6 45 12 87 11");
    add_address(address_book, size, "Jonathan", "+33 6 74 91 48 12");
    add_address(address_book, size, "Cyril", "+33 7 64 99 01 00");
    add_address(address_book, size, "Leo", " +33 7 65 19 98 71");
    add_address(address_book, size, "Gildas", " +33 6 45 67 89 90");
    add_address(address_book, size, "<3", "+33 6 07 08 09 00");
    write(1, "\nExecute on addresses :\n", 25);
    execute_on_address_book(address_book, size, &dummy_function);
    write(1, "\nDelete addresses :\n", 19);
    delete_address_book(address_book, size);
    return 0;
}
