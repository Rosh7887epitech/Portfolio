/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** sprite_items
*/

#include "my_json.h"
#include "item.h"
#include "macro.h"

bool create_sprite_item(item_t *item, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (!texture)
        return false;
    item->item_obj.sprite = sfSprite_create();
    if (!item->item_obj.sprite)
        return false;
    sfSprite_setTexture(item->item_obj.sprite, texture, sfTrue);
    IF_DEBUG(printf("sprite created\n"));
    return true;
}

bool create_sprite_item_from_json(char *name, item_t *item, json_value_t *json)
{
    char *path = NULL;

    if (!name)
        return false;
    IF_DEBUG(printf("name = %s\n", name));
    path = json_object_get_string(json, name);
    if (!path)
        return false;
    IF_DEBUG(printf("path = %s\n", path));
    return create_sprite_item(item, path);
}

char *take_name_from_item(item_t *item)
{
    if (item->type == TYPE_EQUIPMENT)
        return (char *)item->equipment.name;
    if (item->type == TYPE_WEAPON)
        return (char *)item->weapon.name;
    if (item->type == TYPE_CONSUMABLE)
        return (char *)item->consumable.name;
    return NULL;
}

void browse_items_and_create_sprite(item_node_t *head, json_value_t *json)
{
    item_node_t *current = head;
    char *name = NULL;

    while (current) {
        name = take_name_from_item(&current->items);
        create_sprite_item_from_json(name, &current->items, json);
        current = current->next;
    }
}
