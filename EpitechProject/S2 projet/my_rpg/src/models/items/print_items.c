/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** print_items
*/

#include "rpg.h"
#include "my.h"
#include "extern.h"

static void print_weapon(const weapon_t *weapon)
{
    printf("Weapon: ID: %d, Name: %s, Damage: %d, weight: %.1f,"
        " attack speed: %.1f, type: %s, rarety: %s, durability: %d,"
        " range: %.1f\n", weapon->id, weapon->name,
        weapon->damage, weapon->weight, weapon->attack_speed,
        typeitem_names[weapon->type], rarity_names[weapon->rarity],
        weapon->durability, weapon->range);
}

static void print_consumable(const consumable_t *consumable)
{
    printf("Consumable: ID: %d, Name: %s, Health Boost: %d\n",
        consumable->id, consumable->name, consumable->health);
}

static void print_equipment(const equipment_t *equipment)
{
    printf("Equipment: ID: %d, Name: %s, Armor: %d, weight: %.1f\n",
        equipment->id, equipment->name, equipment->armor, equipment->weight);
}

void print_items(const item_node_t *head)
{
    while (head != NULL) {
        switch (head->items.type) {
            case TYPE_WEAPON:
                print_weapon(&head->items.weapon);
                break;
            case TYPE_EQUIPMENT:
                print_equipment(&head->items.equipment);
                break;
            case TYPE_CONSUMABLE:
                print_consumable(&head->items.consumable);
                break;
            case TYPE_COUNT:
                break;
        }
        head = head->next;
    }
}
