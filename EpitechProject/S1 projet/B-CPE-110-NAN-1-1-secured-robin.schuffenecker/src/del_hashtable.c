/*
** EPITECH PROJECT, 2024
** del
** File description:
** del table
*/

#include "../include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    secured_t *next;

    if (ht == NULL || ht->st_tab == NULL)
        return;
    for (int i = 0; i < ht->size; i++) {
        while (ht->st_tab[i] != NULL) {
            next = ht->st_tab[i]->next;
            free(ht->st_tab[i]->key);
            free(ht->st_tab[i]->value);
            free(ht->st_tab[i]);
            ht->st_tab[i] = next;
        }
    }
    free(ht->st_tab);
    ht->st_tab = NULL;
}
