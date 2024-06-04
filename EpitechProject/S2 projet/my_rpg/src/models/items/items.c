/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** items
*/

#include "rpg.h"
#include "my.h"
#include "my_json.h"

const char *typeitem_names[TYPE_COUNT] = {
    "TYPE_WEAPON",
    "TYPE_EQUIPMENT",
    "TYPE_CONSUMABLE"
};

const char *weapontype_names[WEAPON_COUNT] = {
    "WEAPON_SWORD",
    "WEAPON_AXE",
    "WEAPON_BOW"
};

const char *equipmenttype_names[EQUIPMENT_COUNT] = {
    "EQUIPMENT_ARMOR",
    "EQUIPMENT_HELMET",
    "EQUIPMENT_BOOTS",
    "EQUIPMENT_SHIELD"
};

const char *consumabletype_names[CONSUMABLE_COUNT] = {
    "CONSUMABLE_POTION",
    "CONSUMABLE_FOOD"
};

const char *rarity_names[RARITY_COUNT] = {
    "RARITY_COMMON",
    "RARITY_UNCOMMON",
    "RARITY_RARE",
    "RARITY_EPIC",
    "RARITY_LEGENDARY"
};

item_t create_item(typeitem_t type, void *item_details)
{
    item_t item;

    item.type = type;
    switch (type) {
        case TYPE_WEAPON:
            item.weapon = *(weapon_t *)item_details;
            break;
        case TYPE_EQUIPMENT:
            item.equipment = *(equipment_t *)item_details;
            break;
        case TYPE_CONSUMABLE:
            item.consumable = *(consumable_t *)item_details;
            break;
        case TYPE_COUNT:
            break;
    }
    return item;
}

void add_item(item_node_t **head, item_t item)
{
    item_node_t *new_node = malloc(sizeof(item_node_t));

    if (new_node == NULL)
        return;
    printf("Adding item with ID: %d\n", item.weapon.id);
    new_node->items = item;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void delete_item(item_node_t **head, int item_id)
{
    item_node_t *temp = *head;
    item_node_t *prev = NULL;

    while (temp != NULL && temp->items.weapon.id != item_id &&
        temp->items.equipment.id != item_id &&
        temp->items.consumable.id != item_id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    if (temp->next != NULL)
        temp->next->prev = prev;
    free(temp);
}

void free_items_list(item_node_t *head)
{
    item_node_t *current = head;
    item_node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

json_value_t *json_file(char *file)
{
    char *buffer = file_in_buffer(file);
    json_value_t *json = NULL;

    if (buffer == NULL)
        return NULL;
    json = parse_json(buffer);
    if (json == NULL)
        return NULL;
    free(buffer);
    return json;
}
