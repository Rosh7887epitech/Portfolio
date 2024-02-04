/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (len <= 0) {
        ht = NULL;
        return ht;
    }
    ht->hash = hash;
    ht->size = len;
    ht->st_tab = malloc(sizeof(secured_t *) * len);
    for (int i = 0; i < len; i++) {
        ht->st_tab[i] = NULL;
    }
    return ht;
}
