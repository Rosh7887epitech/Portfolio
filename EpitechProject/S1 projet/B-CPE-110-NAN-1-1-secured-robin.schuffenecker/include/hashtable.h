/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include "my.h"

typedef struct hashtable_s {
    secured_t **st_tab;
    int size;
    int (*hash)(char *);
} hashtable_t;

// Hash function
int hash(char *key);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
