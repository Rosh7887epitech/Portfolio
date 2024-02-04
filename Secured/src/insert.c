/*
** EPITECH PROJECT, 2024
** insert
** File description:
** insert
*/

#include "../include/hashtable.h"

secured_t *create_node(char *key, char *value)
{
    secured_t *node = malloc(sizeof(secured_t));

    node->key = my_strdup(key);
    node->value = my_strdup(value);
    node->next = NULL;
    return node;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int new_key;
    char *new_str;
    secured_t *node;
    int position;

    if (ht == NULL || key == NULL || value == NULL || ht->st_tab == NULL)
        return 84;
    new_key = ht->hash(key);
    position = new_key % ht->size;
    new_str = my_itoa(new_key);
    if (ht_search(ht, new_str) == NULL)
        ht_delete(ht, key);
    node = create_node(new_str, value);
    if (ht->st_tab[position] == NULL)
        ht->st_tab[position] = node;
    else {
        node->next = ht->st_tab[position];
        ht->st_tab[position] = node;
    }
    return 0;
}
