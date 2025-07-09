/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** text
*/

#include "rpg.h"
#include "my.h"
#include "text.h"
#include "extern.h"

const sfFont *globalFont = NULL;
const sfText *global_quest_text = NULL;
const sfVector2f npc_text_pos = {1250, 1400};
const sfVector2f npc_text_name_scale = {0.12, 0.12};
const sfVector2f npc_text_scale = {0.1, 0.1};
const sfVector2f npc_story_name_scale = {0.15, 0.15};
const sfVector2f quest_name_scale = {0.19, 0.19};
const sfVector2f quest_text_scale = {0.11, 0.11};
const off_set_t quest_name_offset = {+145, -95};
const off_set_t quest_text_offset = {+146, -75};
const off_set_t npc_text_offset = {-150, 70};
const off_set_t npc_text_name_offset = {-170, 45};
const off_set_t npc_story_name_offset = {-150, 55};
const off_set_t npc_dialog_text_offset = {-140, 60};

bool loadglobalfont(const char *fontPath)
{
    globalFont = sfFont_createFromFile(fontPath);
    if (!globalFont) {
        my_printf("Error: Couldn't load font\n");
        return false;
    }
    return true;
}

void freeglobalfont(void)
{
    sfFont_destroy((sfFont*)globalFont);
    globalFont = NULL;
}

sfText *create_text(const char *str)
{
    sfText *text = sfText_create();

    if (!text) {
        my_printf("Error: Couldn't create text\n");
        return NULL;
    }
    if (!globalFont) {
        my_printf("Error: No font loaded\n");
        return NULL;
    }
    sfText_setFont(text, globalFont);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, TEXT_SIZE);
    sfText_setPosition(text, npc_text_pos);
    sfText_setColor(text, TEXT_COLOR);
    return text;
}

void destroy_text(sfText *text)
{
    sfText_destroy(text);
}
