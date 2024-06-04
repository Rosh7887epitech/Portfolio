/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Shell Boostrap
** File description:
** bootstrap.h
*/

#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H

typedef enum type {
    CHAR,
    STRING,
    INTEGER,
    PLAYER
} type_t;

typedef struct player_s {
    char *name;
    int lvl;
} player_t;

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

int print_typed_value(void *data, type_t type);
void push_to_list(linked_list_t **begin, void *data);
void display_list(linked_list_t *begin, void(*disp_fct)(void *tmp));

#endif /* BOOTSTRAP_H */