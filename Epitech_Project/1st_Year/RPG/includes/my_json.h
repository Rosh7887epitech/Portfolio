/*
** EPITECH PROJECT, 2024
** my_json
** File description:
** my_json
*/

#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT
} json_type_t;

typedef struct json_value {
    json_type_t type;
    struct json_value* parent;
    union {
        double number;
        char *string;
        int boolean;
        struct json_object *object;
        struct json_array *array;
    } data;
} json_value_t;

typedef struct json_object {
    char *key;
    json_value_t *value;
    struct json_object *next;
    json_value_t *parent;
} json_object_t;

typedef struct json_array {
    json_value_t *value;
    struct json_array *next;
    json_value_t *parent;
    int size;
} json_array_t;

// remove

json_value_t *json_object_remove(json_value_t *object, const char *key);
json_value_t *json_array_remove(json_value_t *array, int index);


// print

void json_print(const json_value_t *value);

// add

void json_add_object(json_value_t *object, const char *key,
    json_value_t *value);
void json_add_array(json_value_t *array, json_value_t *value);

// create

json_value_t *json_create_bool(int boolean);
json_value_t *json_create_number(double number);
json_value_t *json_create_string(const char *string);
json_value_t *json_create_array(void);
json_value_t *json_create_object(void);
json_value_t *json_create_null(void);

// free

void json_free(json_value_t *value);

// get

json_value_t *json_object_get(const json_value_t *object, const char *key);
char *json_object_get_string(const json_value_t *value, const char *key);
int json_object_get_int(const json_value_t *value, const char *key);
double json_object_get_double(const json_value_t *value, const char *key);
int json_object_get_bool(const json_value_t *value, const char *key);
json_value_t *json_array_get(const json_value_t *array, int index);
int json_array_length(json_value_t *json_array);

// parse

json_value_t *parse_value(const char **data);
json_value_t *parse_object(const char **data);
json_value_t *parse_array(const char **data);
json_value_t *parse_json(const char *json);

// serialize

void json_serialize(json_value_t *value, char *buffer, int *index);
int get_item_count(json_value_t *json);
