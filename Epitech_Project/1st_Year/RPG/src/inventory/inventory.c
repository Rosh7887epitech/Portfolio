/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** inventory
*/

#include "rpg.h"

void print_inventory(inventory_t *inventory)
{
    item_node_t *current = inventory->n_items;

    while (current != NULL) {
        print_items(current);
        current = current->next;
    }
}

void add_item_to_inventory(item_node_t **head, item_t item)
{
    item_node_t *new_node = malloc(sizeof(item_node_t));

    if (new_node == NULL)
        return;
    new_node->items = item;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void delete_item_to_inventory(inventory_t *inventory, int item_id)
{
    item_node_t *temp = inventory->n_items;
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
        inventory->n_items = temp->next;
    } else {
        prev->next = temp->next;
    }
    if (temp->next != NULL)
        temp->next->prev = prev;
    free(temp);
}

// void move_prev_item_to_inventory(inventory_t *inventory, int item_id)
// {
//     item_node_t *node = inventory->n_items;

//     while (node != NULL && node->items.weapon.id != item_id &&
//         node->items.equipment.id != item_id &&
//         node->items.consumable.id != item_id) {
//         node = node->prev;
//     }
//     if (node == NULL)
//         return;
// }

// void move_next_item_to_inventory(inventory_t *inventory, int item_id)
// {
//     item_node_t *node = inventory->n_items;

//     while (node != NULL && node->items.weapon.id != item_id &&
//         node->items.equipment.id != item_id &&
//         node->items.consumable.id != item_id) {
//         node = node->next;
//     }
//     if (node == NULL)
//         return;
// }
static void display_invent_button(sfRenderWindow *window,
    const inventory_buttons_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->invent_1->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_2->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_3->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_4->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_5->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_6->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_7->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_8->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_9->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_10->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_11->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_12->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_13->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_14->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_15->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->invent_16->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->boots->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->wappon->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->shield->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->helmet->rect, NULL);
}

void display_inventory_menu(const game_t *rpg)
{
    sfRenderWindow *window = rpg->window.window;
    const inventory_buttons_t *button =
        &rpg->inventory.inventory.inventory_buttons;
    sfView *view = rpg->player.p_view.view;

    set_invent_positions(rpg, button, view);
    set_inventory_scale(button);
    set_specials_pos(button, view);
    sfRenderWindow_drawSprite(window, rpg->window.back, NULL);
    sfRenderWindow_drawSprite(window, rpg->inventory.inventory.sprite, NULL);
    display_invent_button(window, button);
}

// item_node_t *move_prev_item_to_inventory(item_node_t *node, int nb)
// {
//     if (node == NULL)
//         return NULL;
//     for (int i = 0; node->prev != NULL && i != nb; i++)
//         node = node->prev;
//     return node;
// }

// item_node_t *move_next_item_to_inventory(item_node_t *node, int nb)
// {
//     if (node == NULL)
//         return NULL;
//     for (int i = 0; node->next != NULL && i != nb; i++)
//         node = node->next;
//     return node;
// }
