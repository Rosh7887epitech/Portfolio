/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-quentin.gerard
** File description:
** extern
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "item.h"
#include "npc.h"
#include "text.h"
#include "utils.h"

extern const sfVector2f vectorfzero;
extern const sfVector2f initial_menu_size;
extern const sfColor hover_color;
extern const sfColor grey_color;
extern const sfColor silver_color;
extern const sfColor light_gray;
extern const sfColor dimgray;
extern const char *typeitem_names[TYPE_COUNT];
extern const char *weapontype_names[WEAPON_COUNT];
extern const char *equipmenttype_names[EQUIPMENT_COUNT];
extern const char *consumabletype_names[CONSUMABLE_COUNT];
extern const char *rarity_names[RARITY_COUNT];
extern const char *questtype_names[QUEST_COUNT];
extern const sfFont *globalFont;
extern const sfVector2f npc_text_pos;
extern const sfVector2f npc_text_name_scale;
extern const sfVector2f npc_text_scale;
extern const sfVector2f quest_name_scale;
extern const sfVector2f quest_text_scale;
extern const sfVector2f npc_story_name_scale;
extern const off_set_t quest_name_offset;
extern const off_set_t quest_text_offset;
extern const off_set_t npc_text_offset;
extern const off_set_t npc_text_name_offset;
extern const off_set_t npc_story_name_offset;
extern const off_set_t npc_dialog_text_offset;
extern const sfText *global_quest_text;
