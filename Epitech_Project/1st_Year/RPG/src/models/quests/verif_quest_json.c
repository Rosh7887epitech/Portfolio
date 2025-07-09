/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** verif_quest_json
*/

#include "npc.h"

bool verif_quest_json(json_value_t *json_quest, json_value_t *json_quest_step)
{
    if (json_quest == NULL || json_quest_step == NULL) {
        return 1;
    }
    if (is_missing(json_quest, "id", false, "quest"))
        return 1;
    if (is_missing(json_quest, "title", true, "quest"))
        return 1;
    if (json_quest_step->type != JSON_ARRAY) {
        printf("Quest steps not found.\n");
        return 1;
    }
    return 0;
}

bool verif_quest_step_collect(json_value_t *js_quest_step)
{
    if (is_missing(js_quest_step, "nb_to_collect", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "target_id", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "target_type", false, "quest_step"))
        return true;
    return false;
}

bool verif_quest_step_talk(json_value_t *js_quest_step)
{
    if (is_missing(js_quest_step, "nb_to_talk", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "target_id", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "target_type", false, "quest_step"))
        return true;
    return false;
}

bool verif_quest_step_kill(json_value_t *js_quest_step)
{
    if (is_missing(js_quest_step, "nb_to_kill", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "target_id", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "target_type", false, "quest_step"))
        return true;
    return false;
}

bool verif_quest_step_json(json_value_t *js_quest_step)
{
    if (is_missing(js_quest_step, "description", true, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "id", false, "quest_step"))
        return true;
    if (is_missing(js_quest_step, "type", true, "quest_step"))
        return true;
    return false;
}
