/*
** EPITECH PROJECT, 2024
** delete
** File description:
** delete
*/

#include "../include/hashtable.h"

secured_t **cond_delete(secured_t *current, secured_t *prev,
    secured_t **node, char *new_key)
{
    if (my_strcmp(new_key, current->key) == 0) {
        if (prev == NULL)
            *node = current->next;
        else
            prev->next = current->next;
        free(current);
        return node;
    }
}

secured_t *loop_delete(secured_t *node, char *new_key)
{
    secured_t *current = node;
    secured_t *prev = NULL;

    while (current != NULL) {
        cond_delete(current, prev, &node, new_key);
        prev = current;
        current = current->next;
    }
    return node;
}

int ht_delete(hashtable_t *ht, char *key)
{
    secured_t **node;
    int k;
    char *new_key;
    char *new_value;
    int index;

    if (ht == NULL || key == NULL || ht->st_tab == NULL)
        return 84;
    node = ht->st_tab;
    k = ht->hash(key);
    index = k % ht->size;
    new_key = my_itoa(k);
    node[index] = loop_delete(node[index], new_key);
    return 0;
}
