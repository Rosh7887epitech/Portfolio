/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** stories
*/

#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "rpg.h"
#include "quest.h"
#include "text.h"

static node_stories_t *create_story(json_value_t *json_story)
{
    node_stories_t *node = calloc(1, sizeof(node_stories_t));
    stories_t story = {0};
    json_value_t *json_dialog = json_object_get(json_story, "dialog");

    if (!node) {
        perror("Failed to allocate memory for Stories node");
        return NULL;
    }
    if (verif_json_value_stories(json_story, json_dialog) == 1)
        return NULL;
    story.id = json_object_get_int(json_story, "id");
    strncpy(story.name, json_object_get_string(json_story, "name"),
        sizeof(story.name) - 1);
    story.name_obj = create_text(story.name);
    story.n_dialog = parse_dialogues(json_dialog);
    node->stories = story;
    node->next = NULL;
    return node;
}

static void add_story(node_stories_t **head, node_stories_t **current,
    node_stories_t *node)
{
    if (*head == NULL) {
        *head = node;
        *current = *head;
    } else {
        (*current)->next = node;
        *current = (*current)->next;
    }
}

static void reverse_list_stories(node_stories_t **head)
{
    node_stories_t *prev = NULL;
    node_stories_t *current = *head;
    node_stories_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

node_stories_t *parse_stories(json_value_t *json_stories)
{
    node_stories_t *head = NULL;
    node_stories_t *current = NULL;
    int count = json_array_length(json_stories);
    json_value_t *json_story = NULL;
    node_stories_t *node = NULL;

    for (int i = 0; i < count; i++) {
        json_story = json_array_get(json_stories, i);
        if (!json_story)
            continue;
        node = create_story(json_story);
        if (node == NULL)
            continue;
        add_story(&head, &current, node);
    }
    reverse_list_stories(&head);
    return head;
}
