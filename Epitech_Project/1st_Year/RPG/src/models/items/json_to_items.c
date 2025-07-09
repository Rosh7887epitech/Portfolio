/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** json_to_items
*/

#include "rpg.h"
#include "my.h"

equipment_t json_to_equipment(json_value_t *json)
{
    equipment_t equipment = {0};
    int type = wich_equipment_type(json);
    int rarety = wich_rarety(json);

    equipment.id = json_object_get_int(json, "id");
    equipment.durability = json_object_get_int(json, "durability");
    equipment.name = json_object_get_string(json, "name");
    equipment.armor = json_object_get_int(json, "armor");
    equipment.weight = json_object_get_double(json, "weight");
    equipment.rarity = rarety;
    equipment.type = type;
    return equipment;
}

weapon_t json_to_weapon(json_value_t *json)
{
    weapon_t weapon = {0};
    int type = wich_weapon_type(json);
    int rarety = wich_rarety(json);

    weapon.id = json_object_get_int(json, "id");
    weapon.durability = json_object_get_int(json, "durability");
    weapon.name = json_object_get_string(json, "name");
    weapon.damage = json_object_get_int(json, "damage");
    weapon.range = json_object_get_double(json, "range");
    weapon.attack_speed = json_object_get_double(json, "attack_speed");
    weapon.weight = json_object_get_double(json, "weight");
    weapon.rarity = rarety;
    weapon.type = type;
    return weapon;
}

consumable_t json_to_consumable(json_value_t *json)
{
    consumable_t consumable = {0};
    int type = wich_consumable_type(json);
    int rarety = wich_rarety(json);

    consumable.id = json_object_get_int(json, "id");
    consumable.name = json_object_get_string(json, "name");
    consumable.health = json_object_get_int(json, "health");
    consumable.weight = json_object_get_double(json, "weight");
    consumable.rarity = rarety;
    consumable.type = type;
    return consumable;
}

item_t json_to_item(json_value_t *json)
{
    item_t item = {0};
    json_value_t *details = json_object_get(json, "details");
    int type = wich_type(json);

    if (type == -1) {
        return item;
    }
    switch (type) {
        case TYPE_WEAPON:
            item.weapon = json_to_weapon(details);
            break;
        case TYPE_EQUIPMENT:
            item.equipment = json_to_equipment(details);
            break;
        case TYPE_CONSUMABLE:
            item.consumable = json_to_consumable(details);
            break;
    }
    item.type = type;
    return item;
}

static void reverse_items(item_node_t **head)
{
    item_node_t *prev = NULL;
    item_node_t *current = *head;
    item_node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

static int item_null(json_value_t *items)
{
    if (items == NULL) {
        printf("No items found.\n");
        return 1;
    }
    return 0;
}

static item_node_t *parse_item(int count, json_value_t *items)
{
    item_node_t *head = NULL;
    item_t item = {0};
    item_node_t *node = NULL;
    item_node_t *current = NULL;

    for (int i = 0; i < count; i++) {
        item = json_to_item(json_array_get(items, i));
        node = malloc(sizeof(item_node_t));
        node->items = item;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            current = head;
        } else {
            current->next = node;
            current = current->next;
        }
    }
    reverse_items(&head);
    return head;
}

item_node_t *json_to_items(json_value_t *json)
{
    item_node_t *head = NULL;
    json_value_t *items = json_object_get(json, "items");
    int count = get_item_count(json);

    if (item_null(items))
        return NULL;
    head = parse_item(count, items);
    return head;
}
