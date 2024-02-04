/*
** EPITECH PROJECT, 2024
** dump
** File description:
** dump
*/

#include "../include/hashtable.h"

void print_list(secured_t *node)
{
    while (node) {
        my_putstr("\n> ");
        my_putstr(node->key);
        my_putstr(" - ");
        my_putstr(node->value);
        node = node->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    secured_t **node;

    if (ht == NULL || ht->st_tab == NULL)
        return;
        node = ht->st_tab;
    for (int i = 0; i < ht->size; i++) {
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:");
        print_list(node[i]);
        my_putstr("\n");
    }
    return;
}
