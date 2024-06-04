/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** item
*/

#pragma once

#include "inventory.h"
#include "player.h"
#include "enemy.h"
#include "npc.h"

typedef enum {
    TYPE_WEAPON,
    TYPE_EQUIPMENT,
    TYPE_CONSUMABLE,
    TYPE_COUNT
} typeitem_t;

typedef enum {
    WEAPON_SWORD,
    WEAPON_AXE,
    WEAPON_BOW,
    WEAPON_COUNT
} weapontype_t;

typedef enum {
    EQUIPMENT_ARMOR,
    EQUIPMENT_HELMET,
    EQUIPMENT_BOOTS,
    EQUIPMENT_SHIELD,
    EQUIPMENT_COUNT
} equipmenttype_t;

typedef enum {
    CONSUMABLE_POTION,
    CONSUMABLE_FOOD,
    CONSUMABLE_COUNT
} consumabletype_t;

typedef enum {
    RARITY_COMMON,
    RARITY_UNCOMMON,
    RARITY_RARE,
    RARITY_EPIC,
    RARITY_LEGENDARY,
    RARITY_COUNT
} rarity_t;

typedef struct {
    int damage;
    int durability;
    double range;
    double attack_speed;
    double weight;
    const char *name;
    int id;
    weapontype_t type;
    rarity_t rarity;
    void (*attack)(struct player_s *, struct enemy_s *);
} weapon_t;

typedef struct {
    int armor;
    int durability;
    double weight;
    const char *name;
    int id;
    equipmenttype_t type;
    rarity_t rarity;
    void (*effect)(struct player_s *);
} equipment_t;

typedef struct {
    int health;
    double weight;
    const char *name;
    int id;
    consumabletype_t type;
    rarity_t rarity;
    void (*consume)(struct player_s *);
} consumable_t;

typedef struct {
    typeitem_t type;
    union {
        weapon_t weapon;
        equipment_t equipment;
        consumable_t consumable;
    };
    sprite_object_t item_obj;
} item_t;

typedef struct item_node_s {
    item_t items;
    struct item_node_s *next;
    struct item_node_s *prev;
} item_node_t;

typedef struct json_value json_value_t;

item_t create_item(typeitem_t type, void *item_details);
void add_item(item_node_t **head, item_t item);
void delete_item(item_node_t **head, int item_id);
void print_items(const item_node_t *head);
int wich_consumable_type(json_value_t *json);
int wich_rarety(json_value_t *json);
int wich_equipment_type(json_value_t *json);
int wich_weapon_type(json_value_t *json);
int wich_type(json_value_t *json);
equipment_t json_to_equipment(json_value_t *json);
weapon_t json_to_weapon(json_value_t *json);
consumable_t json_to_consumable(json_value_t *json);
item_t json_to_item(json_value_t *json);
item_node_t *json_to_items(json_value_t *json);
void free_items_list(item_node_t *head);
void add_item_to_inventory(item_node_t **head, item_t item);
void delete_item_to_inventory(inventory_t *inventory, int item_id);
void move_prev_item_to_inventory(inventory_t *inventory, int item_id);
void move_next_item_to_inventory(inventory_t *inventory, int item_id);
void print_inventory(inventory_t *inventory);
void browse_items_and_create_sprite(item_node_t *head, json_value_t *json);
