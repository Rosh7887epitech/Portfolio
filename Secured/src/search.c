/*
** EPITECH PROJECT, 2024
** search
** File description:
** search
*/

#include "../include/hashtable.h"

char *loop_search(secured_t *node, char *new_key)
{
    char *returned = my_strdup("NOFIND");

    while (node != NULL) {
        if (my_strcmp(new_key, node->key) == 0)
            return node->value;
        node = node->next;
    }
    return returned;
}

char *ht_search(hashtable_t *ht, char *key)
{
    secured_t **node;
    int k;
    char *new_key;
    char *new_value;
    int index;

    if (ht == NULL || key == NULL || ht->st_tab == NULL)
        return NULL;
    node = ht->st_tab;
    k = ht->hash(key);
    index = k % ht->size;
    new_key = my_itoa(k);
    new_value = my_strdup(loop_search(node[index], new_key));
    if (my_strcmp(new_value, "NOFIND") == 0)
        return NULL;
    return new_value;
}
