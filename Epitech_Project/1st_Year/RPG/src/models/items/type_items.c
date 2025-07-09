/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** type_items
*/

#include "rpg.h"
#include "my.h"
#include "extern.h"

int wich_rarety(json_value_t *json)
{
    char *rarity = NULL;

    if (json == NULL)
        return -1;
    rarity = json_object_get_string(json, "rarity");
    if (rarity == NULL)
        return -1;
    for (int i = 0; i < RARITY_COUNT; i++) {
        if (my_strcmp(rarity, rarity_names[i]) == 0)
            return i;
    }
    return -1;
}

int wich_equipment_type(json_value_t *json)
{
    char *type = NULL;

    if (json == NULL)
        return -1;
    type = json_object_get_string(json, "type");
    if (type == NULL)
        return -1;
    for (int i = 0; i < EQUIPMENT_COUNT; i++) {
        if (my_strcmp(type, equipmenttype_names[i]) == 0)
            return i;
    }
    return -1;
}

int wich_weapon_type(json_value_t *json)
{
    char *type = NULL;

    if (json == NULL)
        return -1;
    type = json_object_get_string(json, "type");
    if (type == NULL)
        return -1;
    for (int i = 0; i < WEAPON_COUNT; i++) {
        if (my_strcmp(type, weapontype_names[i]) == 0)
            return i;
    }
    return -1;
}

int wich_consumable_type(json_value_t *json)
{
    char *type = NULL;

    if (json == NULL)
        return -1;
    type = json_object_get_string(json, "type");
    if (type == NULL)
        return -1;
    for (int i = 0; i < CONSUMABLE_COUNT; i++) {
        if (my_strcmp(type, consumabletype_names[i]) == 0)
            return i;
    }
    return -1;
}

int wich_type(json_value_t *json)
{
    char *type = NULL;

    if (json == NULL)
        return -1;
    type = json_object_get_string(json, "type");
    if (type == NULL)
        return -1;
    for (int i = 0; i < TYPE_COUNT; i++) {
        if (my_strcmp(type, typeitem_names[i]) == 0)
            return i;
    }
    return -1;
}
