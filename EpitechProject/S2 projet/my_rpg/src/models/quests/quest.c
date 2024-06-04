/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** quest
*/

#include "my.h"
#include "extern.h"

const char *questtype_names[QUEST_COUNT] = {
    "QUEST_KILL",
    "QUEST_COLLECT",
    "QUEST_TALK"
};

int wich_quest_type(json_value_t *json)
{
    char *type = NULL;

    if (json == NULL)
        return -1;
    type = json_object_get_string(json, "type");
    if (type == NULL)
        return -1;
    for (int i = 0; i < QUEST_COUNT; i++) {
        if (my_strcmp(type, questtype_names[i]) == 0)
            return i;
    }
    return -1;
}
