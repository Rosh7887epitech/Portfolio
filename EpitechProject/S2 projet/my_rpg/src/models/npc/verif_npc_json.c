/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** verif_npc_json
*/

#include "npc.h"
#include "my.h"

bool is_missing(json_value_t *json, const char *key, bool is_string,
    const char *type)
{
    if (is_string) {
        if (json_object_get_string(json, key) == NULL) {
            printf("%s %s not found.\n", type, key);
            return 1;
        }
        return 0;
    }
    if (json_object_get_int(json, key) == 0) {
        printf("%s %s not found.\n", type, key);
        return 1;
    }
    return 0;
}

static bool verif_json_value_npc(json_value_t *json_stories,
    json_value_t *json_quests, char *name)
{
    if (!json_stories && !json_quests) {
        printf("%s stories and quests not found.\n", name);
        return 1;
    }
    if (json_stories && json_stories->type != JSON_ARRAY) {
        printf("%s stories not found.\n", name);
        return 1;
    }
    if (json_quests && json_quests->type != JSON_ARRAY) {
        printf("%s quests not found.\n", name);
        return 1;
    }
    return 0;
}

bool verif_npc_json(json_value_t *json_npc, json_value_t *json_stories,
    json_value_t *json_quests)
{
    char *name = NULL;

    if (is_missing(json_npc, "id", false, "NPC"))
        return 1;
    if (is_missing(json_npc, "name", true, "NPC")) {
        return 1;
    }
    name = json_object_get_string(json_npc, "name");
    return verif_json_value_npc(json_stories, json_quests, name);
}

bool verif_json_value_dialogue(json_value_t *json_dialog_opt,
    json_value_t *json_dialog)
{
    if (is_missing(json_dialog, "id", false, "Dialogue"))
        return 1;
    if (is_missing(json_dialog, "name", true, "Dialogue"))
        return 1;
    if (is_missing(json_dialog, "text", true, "Dialogue"))
        return 1;
    if (!json_dialog_opt) {
        printf("Dialogue options not found.\n");
        return 1;
    }
    if (json_dialog_opt->type != JSON_ARRAY) {
        printf("Dialogue options not found.\n");
        return 1;
    }
    return 0;
}

bool verif_json_value_stories(json_value_t *json_story,
    json_value_t *json_dialog)
{
    if (!json_dialog) {
        printf("Story dialog not found.\n");
        return 1;
    }
    if (json_dialog->type != JSON_ARRAY) {
        printf("Story dialog not found.\n");
        return 1;
    }
    if (is_missing(json_story, "id", false, "Story"))
        return 1;
    if (is_missing(json_story, "name", true, "Story"))
        return 1;
    return 0;
}

bool verif_json_dialogue_option(json_value_t *json_dialog_option)
{
    if (is_missing(json_dialog_option, "id", false, "Dialogue Option"))
        return 1;
    if (is_missing(json_dialog_option, "text", true, "Dialogue Option"))
        return 1;
    return 0;
}
