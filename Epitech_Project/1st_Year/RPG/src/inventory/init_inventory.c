/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_inventory
*/

#include "rpg.h"

void init_specials_invent_buttons(inventory_buttons_t *button)
{
    char *shiel_fp = "assets/images/items/shield.png";
    char *wappon_fp = "assets/images/items/sword.png";
    char *boots_fp = "assets/images/items/boots.png";
    char *helmet_fp = "assets/images/items/helmet.png";

    button->helmet = create_buttons(helmet_fp);
    button->boots = create_buttons(boots_fp);
    button->shield = create_buttons(shiel_fp);
    button->wappon = create_buttons(wappon_fp);
}

void init_inventory_buttons(inventory_buttons_t *button)
{
    char *filepath = "assets/images/buttons/inventory_button.png";

    button->invent_1 = create_buttons(filepath);
    button->invent_2 = create_buttons(filepath);
    button->invent_3 = create_buttons(filepath);
    button->invent_4 = create_buttons(filepath);
    button->invent_5 = create_buttons(filepath);
    button->invent_6 = create_buttons(filepath);
    button->invent_7 = create_buttons(filepath);
    button->invent_8 = create_buttons(filepath);
    button->invent_9 = create_buttons(filepath);
    button->invent_10 = create_buttons(filepath);
    button->invent_11 = create_buttons(filepath);
    button->invent_12 = create_buttons(filepath);
    button->invent_13 = create_buttons(filepath);
    button->invent_14 = create_buttons(filepath);
    button->invent_15 = create_buttons(filepath);
    button->invent_16 = create_buttons(filepath);
}

bool init_inventory(inventory_t *inventory, item_t item)
{
    inventory->n_items = NULL;
    inventory->inventory.status = NONE;
    inventory->inventory.texture =
        sfTexture_createFromFile("assets/images/inventory.png", NULL);
    inventory->inventory.sprite = sfSprite_create();
    inventory->inventory.rect = (sfIntRect){0, 0, 1920, 1080};
    inventory->inventory.scale = (sfVector2f){1.7, 1.7};
    inventory->inventory.origin = (sfVector2f){48, 48};
    sfSprite_setTexture(inventory->inventory.sprite,
        inventory->inventory.texture, sfTrue);
    sfSprite_setTextureRect(inventory->inventory.sprite,
        inventory->inventory.rect);
    sfSprite_setPosition(inventory->inventory.sprite, (sfVector2f){960, 540});
    sfSprite_setScale(inventory->inventory.sprite, inventory->inventory.scale);
    sfSprite_setOrigin(inventory->inventory.sprite,
        inventory->inventory.origin);
    init_inventory_buttons(&inventory->inventory.inventory_buttons);
    init_specials_invent_buttons(&inventory->inventory.inventory_buttons);
    add_item_to_inventory(&inventory->n_items, item);
    return true;
}
