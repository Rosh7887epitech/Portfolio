/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game_render
*/

#pragma once

#include "game_types.h"
#include "musics.h"
#include "utils.h"

#define IS_HOVER(button) (button->is_hovered(button, &event.mouseMove)) ? 1 : 0
#define IS_CLICK(button) (button->is_click(button, &event.mouseButton)) ? 1 : 0
#define IS_REL(button) (button->is_rel(button, &event.mouseButton)) ? 1 : 0
#define IS_PRES(button) (button->is_pres(button, &event.mouseButton)) ? 1 : 0

enum button_state {
    NON = 0,
    HOVER,
    PRESSED,
    RELEASED,
    CLICKED
};

enum menu_state {
    PRESS,
    RELEASE,
    NONE
};

typedef enum {
    NONE_MENU,
    START_MENU,
    INTRA_MENU,
    SETTING_MENU,
    INVENTORY_MENU
} state_menu_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_click)(struct button_s *, sfMouseButtonEvent*);
    sfBool (*is_hovered)(struct button_s *, sfMouseMoveEvent*);
    sfBool (*is_rel)(struct button_s *, sfMouseButtonEvent*);
    sfBool (*is_pres)(struct button_s *, sfMouseButtonEvent*);
    enum button_state state;
} button_t;

typedef struct start_buttons_s {
    button_t *new_game;
    button_t *load;
    button_t *settings;
    button_t *exit;
} start_buttons_t;

typedef struct inventory_buttons_s {
    button_t *invent_1;
    button_t *invent_2;
    button_t *invent_3;
    button_t *invent_4;
    button_t *invent_5;
    button_t *invent_6;
    button_t *invent_7;
    button_t *invent_8;
    button_t *invent_9;
    button_t *invent_10;
    button_t *invent_11;
    button_t *invent_12;
    button_t *invent_13;
    button_t *invent_14;
    button_t *invent_15;
    button_t *invent_16;
    button_t *helmet;
    button_t *boots;
    button_t *wappon;
    button_t *shield;
} inventory_buttons_t;

typedef struct in_game_buttons_s {
    button_t *settings;
    button_t *exit_game;
    button_t *resume;
    button_t *save;
    button_t *menu;
} in_game_buttons_t;

typedef struct settings_buttons_s {
    button_t *setting_exit;
    button_t *volume;
    button_t *setting_help;
} settings_buttons_t;

typedef struct settings_menu_page_s {
    sfIntRect rect;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f origin;
    enum menu_state status;
    settings_buttons_t settings_buttons;
} settings_menu_page_t;

typedef struct intra_menu_page_s {
    sfIntRect rect;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f origin;
    enum menu_state status;
    in_game_buttons_t in_game_buttons;
} intra_menu_page_t;

typedef struct start_menu_page_s {
    sfIntRect rect;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f origin;
    enum menu_state status;
    start_buttons_t start_buttons;
} start_menu_page_t;

typedef struct inventory_menu_s {
    sfIntRect rect;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f origin;
    enum menu_state status;
    inventory_buttons_t inventory_buttons;
} inventory_menu_t;

typedef struct inventory_s {
    int max_capacity;
    int acutal_capacity;
    item_node_t *n_items;
    inventory_menu_t inventory;
} inventory_t;

typedef struct menu_s {
    intra_menu_page_t sets;
    start_menu_page_t settings;
    settings_menu_page_t set;
    inventory_menu_t inventory;
    state_menu_t state;
    int last_state;
} menu_t;

void render_game(const game_t *game);

void check_status_menu(game_t *rpg, sfEvent event);

bool init_menu(menu_t *menu);
bool init_start_buttons(start_buttons_t *button);
bool init_intra_game_buttons(in_game_buttons_t *button);
bool init_intra_menu_sets(intra_menu_page_t *sets);
bool init_start_menu_sets(start_menu_page_t *settings);
bool init_settings_buttons(settings_buttons_t *button);
bool init_settings_menu_sets(settings_menu_page_t *set);
bool init_inventory(inventory_t *inventory, item_t item);
bool init_menu(menu_t *menu);
bool init_all_buttons(menu_t *menu);

void display_start_menu_buttons(const game_t *rpg);
void display_settings_menu_buttons(const game_t *rpg);
void display_intra_menu_buttons(const game_t *rpg);
void display_inventory_menu(const game_t *rpg);

void set_inventory_scale(const inventory_buttons_t *button);
void set_invent_positions(const game_t *rpg, const inventory_buttons_t *button,
    sfView *view);
void set_settings_menu_in_game(const game_t *rpg);
void set_specials_pos(const inventory_buttons_t *but, sfView *view);

void handle_exit_button(sfEvent event, button_t *exit, game_t *game);
void handle_new_button(sfEvent event, button_t *new, game_t *game);
void handle_settings_button(sfEvent event, button_t *settings, game_t *game);
void handle_load_button(sfEvent event, button_t *load, game_t *game);
void handle_settings_button(sfEvent event, button_t *settings, game_t *game);
void handle_exit_game_button(sfEvent event, button_t *exit, game_t *game);
void handle_resume_button(sfEvent event, button_t *resume, game_t *game);
void handle_save_button(sfEvent event, button_t *save, game_t *game);
void handle_sets_button(sfEvent event, button_t *settings, game_t *game);
void handle_exit_sets_button(sfEvent event, button_t *exit, game_t *game);
void handle_volume_button(sfEvent event, button_t *volume, game_t *game);
void handle_help_button(sfEvent event, button_t *help, game_t *game);

void check_states(const game_t *game);
void draw_npc(const game_t *game, node_npc_t *current);
void draw_letter(const game_t *game, node_npc_t *current);
void display_npc_on_screen(const game_t *game);
void display_text_and_frame(const game_t *game);
void display_frame(sfRenderWindow *window, sfView *view,
    sfSprite *sprite, off_set_t offset);
void render_text_in_game(const game_t *game);
