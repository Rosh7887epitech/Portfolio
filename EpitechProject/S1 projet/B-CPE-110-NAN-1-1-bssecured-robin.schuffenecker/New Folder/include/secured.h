/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured Bootstrap
** File description:
** bootstrap.h
*/

#pragma once

typedef struct secured_s
{
    char *key;
    char *value;

} secured_t;


typedef struct hashtable_s {
    secured_t **test;
} hashtable_t;
