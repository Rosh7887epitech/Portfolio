/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "include/bootstrap.h"
#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int data1 = 42;
    int data2 = 314;

    linked_list_t *myList = NULL;
    push_to_list(&myList, &data1);
    push_to_list(&myList, &data2);
    display_list(myList, my_put_nbr);
    return 0;
}